#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>

using namespace std;

const int SIZE = 9;

void showDifficultyMenu() {
    cout << "Choose difficulty:\n";
    cout << "1. Easy \n";
    cout << "2. Medium \n";
    cout << "3. Hard \n";
    cout << "0. Exit\n";
}

void giveHint(int board[SIZE][SIZE], int solutionBoard[SIZE][SIZE]) { //dinei ena tyxaio hint 
    vector<pair<int, int>> emptyCells;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                emptyCells.push_back({i, j});
            }
        }
    }

    if (!emptyCells.empty()) {
        auto hintCell = emptyCells[rand() % emptyCells.size()];
        int row = hintCell.first;
        int col = hintCell.second;
        cout << "Hint: Try placing a " << solutionBoard[row][col]
             << " at row " << row + 1 << ", column " << col + 1 << ".\n";
    } else {
        cout << "No hints available. Board is full.\n";
    }
}

void autoFillOneCell(int board[SIZE][SIZE], int solutionBoard[SIZE][SIZE]) { //dinei pragmatikh voitheia
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = solutionBoard[i][j];
                cout << "Auto-filled cell at row " << i + 1 << ", column " << j + 1
                     << " with value " << solutionBoard[i][j] << ".\n";
                return;
            }
        }
    }
    cout << "Board is already full.\n";
}

void displayBoard(int board[SIZE][SIZE], int chances = -1,int hintsLeft = -1) {
    cout << "\n    1 2 3   4 5 6   7 8 9 \n";
    cout << " ---------------------------\n";
    for (int i = 0; i < SIZE; i++) {
        if (i % 3 == 0 && i != 0)
            cout << " ---------------------------\n";
        cout << i + 1 << " | ";
        for (int j = 0; j < SIZE; j++) {
            if (j % 3 == 0 && j != 0)
                cout << "| ";
            if (board[i][j] == 0)
                cout << "  ";
            else
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << " ---------------------------\n";
    if (chances >= 0) {
        cout << "Remaining chances: " << chances << "/3\n";
    }
     if (hintsLeft >= 0) {
        cout << "Remaining hints: " << hintsLeft << "/2\n";
    }
    cout << " ---------------------------\n";
}
  

bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool fillSudoku(int board[SIZE][SIZE], int row = 0, int col = 0) {
    if (row == SIZE - 1 && col == SIZE) return true;
    if (col == SIZE) {
        row++;
        col = 0;
    }
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    random_shuffle(nums.begin(), nums.end());

    for (int num : nums) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (fillSudoku(board, row, col + 1)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void removeNumbers(int board[SIZE][SIZE], int count) {
    vector<pair<int, int>> positions;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            positions.push_back({i, j});

    random_shuffle(positions.begin(), positions.end());

    int removeCount = SIZE * SIZE - count;
    for (int i = 0; i < removeCount; i++) {
        int r = positions[i].first;
        int c = positions[i].second;
        board[r][c] = 0;
    }
}

bool isBoardFull(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == 0)
                return false;
    return true;
}

void playSudoku(int board[SIZE][SIZE], int solutionBoard[SIZE][SIZE]) {
    int chances = 3;
    int hintsLeft = 2;

    displayBoard(board, chances, hintsLeft);

    while (!isBoardFull(board)) {
        cout << "\nEnter 'h' for hint, 'a' for auto-fill, or 'row col num': ";
        string inputLine;
        getline(cin >> ws, inputLine);

        if (inputLine == "h") {
            if (hintsLeft > 0) {
                giveHint(board, solutionBoard);
                hintsLeft--;
            } else {
                cout << "No hints left.\n";
            }
            displayBoard(board, chances, hintsLeft);
            continue;
        } else if (inputLine == "a") {
            if (hintsLeft > 0) {
                autoFillOneCell(board, solutionBoard);
                hintsLeft--;
            } else {
                cout << "No auto-fills left.\n";
            }
            displayBoard(board, chances, hintsLeft);
            continue;
        }

        int row, col, num;
        stringstream ss(inputLine);
        if (ss >> row >> col >> num) {
            row--; col--;

            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && num >= 1 && num <= 9) {
                if (board[row][col] == 0) {
                    if (solutionBoard[row][col] == num) {
                        board[row][col] = num;
                        displayBoard(board, chances, hintsLeft);
                    } else {
                        cout << "Wrong number! That’s not the correct value for this cell.\n";
                        chances--;
                        if (chances == 0) {
                            cout << "No more chances. Game over.\n";
                            break;
                        }
                        displayBoard(board, chances, hintsLeft);
                    }
                } else {
                    cout << "Cell already filled.\n";
                }
            } else {
                cout << "Invalid input range. Try again.\n";
            }
        } else {
            cout << "Invalid input format. Try again.\n";
        }
    }

    if (isBoardFull(board)) {
        cout << "Congratulations! You've completed the Sudoku!\n";
    }

    cout << "\nSolution Board:\n";
    displayBoard(solutionBoard);
}


int main() {
    int ep;
    int board[SIZE][SIZE] = {0};
    int solutionBoard[SIZE][SIZE] = {0};
    int visibleNumbers;
    srand(time(0));

    using namespace std::chrono;
    auto start = steady_clock::now();

    cout << "==============================\n";
    cout << " \tWelcome to Sudoku!\n";
    cout << "==============================\n";
    showDifficultyMenu();
    cin >> ep;

    while (ep < 0 || ep > 3) {
        cout << "Invalid input. Please enter a number between 0 and 3 (0 for exit): ";
        showDifficultyMenu();
        cin >> ep;
    }

    if (ep == 0) {
        auto end = steady_clock::now();
        auto duration = duration_cast<seconds>(end - start).count();
        cout << "You exited the game.\n";
        cout << "Time taken: " << duration << " seconds.\n";
        return 0;
    }

    visibleNumbers = (ep == 1) ? 36 : (ep == 2) ? 32 : 26;
    fillSudoku(board);
    copy(&board[0][0], &board[0][0] + SIZE * SIZE, &solutionBoard[0][0]);
    removeNumbers(board, visibleNumbers);

    switch (ep) {
        case 1: cout << "\tEasy level.\n"; break;
        case 2: cout << "\tMedium level.\n"; break;
        case 3: cout << "\tHard level.\n"; break;
    }

    playSudoku(board, solutionBoard);

    auto end = steady_clock::now();
    auto duration = duration_cast<seconds>(end - start).count();

    if (duration < 60) {
        cout << "\nTime taken: " << duration << " seconds.\n";
    } else {
        int minutes = duration / 60;
        int seconds = duration % 60;
        cout << "\nTime taken: " << minutes << " minutes and " << seconds << " seconds.\n";
    }

    return 0;
}

