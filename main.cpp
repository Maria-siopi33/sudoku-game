#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
<<<<<<< Updated upstream

const int SIZE = 9;

=======
const int SIZE = 9;
>>>>>>> Stashed changes
void showDifficultyMenu() {
    cout << "\nChoose difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "0. Exit\n";
    cout << "Your choice: ";
}

<<<<<<< Updated upstream
void displayBoard(int board[SIZE][SIZE]) {
    cout << "\n    1 2 3   4 5 6   7 8 9 \n";
    cout << " ---------------------------\n";
    for (int i = 0; i < SIZE; i++) {
        if (i % 3 == 0 && i != 0)
=======
void displayBoard(int board[SIZE][SIZE], int chances = -1) {
    cout << "\n    1 2 3   4 5 6   7 8 9 \n";//deiktes gia pio eykoly epilogh
    cout << " ---------------------------\n";
    for (int i = 0; i < SIZE; i++) {
        if (i % 3 == 0 && i != 0) 
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
    }
    cout << " ---------------------------\n";
    if (chances >= 0) {
        cout << "Remaining chances: " << chances << "/3\n";// na emfanizontai oi eykairies poy soy menoyn
>>>>>>> Stashed changes
    }
    cout << " ---------------------------\n";
}

<<<<<<< Updated upstream
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
=======
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) { // elegxoi eisagvghs 
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
bool fillSudoku(int board[SIZE][SIZE], int row = 0, int col = 0) {
=======
bool fillSudoku(int board[SIZE][SIZE], int row = 0, int col = 0) { //periexei lymeno ton pinaka sudoku
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
void removeNumbers(int board[SIZE][SIZE], int count) {
=======
void removeNumbers(int board[SIZE][SIZE], int count) { //bgazei analoga me to epipedo dyskolias mia posothta arithmvn
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
bool isBoardFull(int board[SIZE][SIZE]) {
=======
bool isBoardFull(int board[SIZE][SIZE]) { //elexos an exei lythei to sudoku
>>>>>>> Stashed changes
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == 0)
                return false;
    return true;
}

void playSudoku(int board[SIZE][SIZE], int solutionBoard[SIZE][SIZE]) {
    int row, col, num;
    int chances = 3;

<<<<<<< Updated upstream
    while (!isBoardFull(board)) {
        cout << "\nEnter row (1-9), column (1-9), and number (1-9): ";
        cin >> row >> col >> num;

        row--; 
        col--;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && num >= 1 && num <= 9) {
            if (board[row][col] == 0) {
                if (solutionBoard[row][col] == num) {
                    board[row][col] = num;
                    displayBoard(board);
                } else {
                    cout << "Wrong number! That’s not the correct value for this cell.\n";
                    chances--;
                    cout << "Remaining chances: " << chances << "\n";
                    if (chances == 0) {
                        cout << "No more chances. Game over.\n";
                        break;
                    }
                }
            } else {
                cout << "Cell already filled.\n";
            }
        } else {
            cout << "Invalid input. Try again.\n";
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

    if (ep == 1) 
        visibleNumbers = 36;
    else if (ep == 2) 
        visibleNumbers = 32;
    else if (ep == 3) 
        visibleNumbers = 26;
    else {
        auto end = steady_clock::now();
        auto duration = duration_cast<seconds>(end - start).count();
        cout << "You exited the game.\n";
        cout << "Time taken: " << duration << " seconds.\n";
        return 0;
    }

    fillSudoku(board);
    copy(&board[0][0], &board[0][0] + SIZE * SIZE, &solutionBoard[0][0]); // Save full solution
    removeNumbers(board, visibleNumbers);

    switch (ep) {
        case 1: cout << "\tEasy level.\n"; break;
        case 2: cout << "\tMedium level.\n"; break;
        case 3: cout << "\tHard level.\n"; break;
    }

    displayBoard(board);
    playSudoku(board, solutionBoard);
    
    auto end = steady_clock::now();
    auto duration = duration_cast<seconds>(end - start).count();
    cout << "\nTime taken: " << duration << " seconds.\n";
    return 0;
}

=======
    displayBoard(board, chances);

    while (!isBoardFull(board)) { 
        cout << "\nEnter row (1-9), column (1-9), and number (1-9): "; //eisagvgi mesa se synartisi
        cin >> row >> col >> num;

        row--; 
        col--;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && num >= 1 && num <= 9) {
            if (board[row][col] == 0) {
                if (solutionBoard[row][col] == num) {
                    board[row][col] = num;
                    displayBoard(board, chances);
                } else {
                    cout << "Wrong number! That’s not the correct value for this cell.\n";
                    chances--;
                    if (chances == 0) {
                        cout << "No more chances. Game over.\n";
                        break;
                    }
                    displayBoard(board, chances);
                }
            } else {
                cout << "Cell already filled.\n";
            }
        } else {
            cout << "Invalid input. Try again.\n";
        }
    }

    if (isBoardFull(board)) {
        cout << "Congratulations! You've completed the Sudoku!\n";
    }

    cout << "\nSolution Board:\n"; //deixnv lysh sudoku
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
 
    while (ep < 0 || ep > 3) { //elexos epiloghs
        cout << "Invalid input. Please enter a number between 0 and 3 (0 for exit): ";
        showDifficultyMenu();
        cin >> ep;
    }

    if (ep == 1)
        visibleNumbers = 36;
    else if (ep == 2)
        visibleNumbers = 32;
    else if (ep == 3)
        visibleNumbers = 26;
    else {
        auto end = steady_clock::now();
        auto duration = duration_cast<seconds>(end - start).count();
        cout << "You exited the game.\n";
        cout << "Time taken: " << duration << " seconds.\n";
        return 0;
    }

    fillSudoku(board);
    copy(&board[0][0], &board[0][0] + SIZE * SIZE, &solutionBoard[0][0]); // Save full solution
    removeNumbers(board, visibleNumbers);

    switch (ep) {
        case 1: cout << "\tEasy level.\n"; break;
        case 2: cout << "\tMedium level.\n"; break;
        case 3: cout << "\tHard level.\n"; break;
    }

    playSudoku(board, solutionBoard);

    auto end = steady_clock::now(); //synartisi gia xrono
    auto duration = duration_cast<seconds>(end - start).count();
    cout << "\nTime taken: " << duration << " seconds.\n";
    return 0;
}

>>>>>>> Stashed changes
