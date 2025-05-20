#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cctype>
#include <iomanip>
#include <sstream>

using namespace std;
int C = 0;
const int SIZE = 9;

void instructions(){
	cout<<"According to the difficulty level you will choose,you will start with some points:\n";
	cout<<"Levels:\n";
	cout << "1. Easy   - 10 points\n";
    cout << "2. Medium - 20 points\n";
    cout << "3. Hard   - 30 points\n\n";
    cout << "- Fill the grid so that each number from 1 to 9\n";
    cout << "    appears exactly once in every row, column, and 3x3 box.\n";
    cout << "- To enter a number, type: row column value (e.g. 3 4 7).\n";
    cout << "- You can use 'h' to reveal a correct value (for free).\n";
    cout << "- You can use 'a' to fill in all obvious values (for free).\n";
    cout << "- If you run out of attempts, you can buy 3 extra attempts for 5 points.\n";
    cout << "- You can exit the game whenever you want.\n";
    
    cout << "Scoring:\n";
	cout << "- You gain 2 points for every correct number you enter.\n";
	cout << "- You lose 2 points for every incorrect number.\n";
}

void showDifficultyMenu() {
    cout << "\nChoose difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "0. Exit\n";
    cout << "Your choice: ";
}

void displayBoard(int board[SIZE][SIZE], int mistakes ,int hintsLeft) {
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
    cout << "Mistakes: " << mistakes << "/3 | Points: " << C << "\n";
    if (hintsLeft >= 0) {
        cout << "Remaining hints: " << hintsLeft << "/2\n";
    }
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

bool giveHelp(int board[SIZE][SIZE], int solutionBoard[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = solutionBoard[i][j];
                cout << "Help used: Cell (" << i+1 << "," << j+1 << ") filled with " << solutionBoard[i][j] << ".\n";
                return true;
            }
        }
    }
    return false;
}



void GamePoints(int board[SIZE][SIZE], int solutionBoard[SIZE][SIZE], int row, int col, int num){
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && num >= 1 && num <= 9) {
        if (board[row][col] == 0) {
            if (solutionBoard[row][col] == num) {
                C += 2;
            } else {
                C -= 2;
            }
        }
    }
}

bool Tries(int& chances) {
    if (C < 5) {
        cout << "Sorry, you don't have enough points to buy more chances.\n";
        return false;
    }

    char an;
    do {
        cout << "Would you like to buy 3 more chances for 5 point? (y/n): ";
        cin >> an;
        an = tolower(an);
        if (an != 'y' && an != 'n') {
            cout << "Invalid input. Please type 'y' or 'n'.\n";
        }
    } while (an != 'y' && an != 'n');

    if (an == 'y') {
        chances =0;
        C -= 5;
        cout << "You just bought 3 more chances. Remaining points: " << C << "\n";
        return true;
    } else {
        cout << "You chose not to buy more chances.\n";
        return false;
    }
}

void playSudoku(int board[SIZE][SIZE], int solutionBoard[SIZE][SIZE]) {
    int row, col, num;
    int mistakes=0,hintsLeft=2;
    
    displayBoard(board, mistakes,hintsLeft);

    while (!isBoardFull(board)) {
    	
	cout << "\nEnter row (1-9), column (1-9), and number (1-9), or type 'h' for hint, 'a' for auto-fill, or '0 0 0' to exit: ";
	string input;
	cin >> ws;
	getline(cin, input);

	if (input == "h") {
    	if (hintsLeft > 0) {
       		giveHint(board, solutionBoard);
        	hintsLeft--;
    	} else {
        	cout << "No hints left.\n";
    	}
    	displayBoard(board, mistakes, hintsLeft);
    	continue;
		}
	else if (input == "a") {
    	if (hintsLeft > 0) {
        	autoFillOneCell(board, solutionBoard);
        	hintsLeft--;
    	} else {
        	cout << "No auto-fills left.\n";
    	}
    	displayBoard(board, mistakes, hintsLeft);
    	continue;
	}
	else {
    	istringstream iss(input);
    	if (!(iss >> row >> col >> num)) {
        	cout << "Invalid input. Please enter either 'h', 'a', or 3 numbers.\n";
        	continue;
    	}
	}
        
        if (row == 0 && col == 0 && num == 0) {
    		cout << "You exited the game.\n";
    		break;
		}


        row--; 
        col--;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && num >= 1 && num <= 9) {
            if (board[row][col] == 0) {
				GamePoints(board, solutionBoard, row, col, num);
				if (solutionBoard[row][col] == num) {
    				board[row][col] = num;
    				displayBoard(board,mistakes,hintsLeft);
				} 
				else {
    				mistakes++;
    				cout << "Mistakes:" << mistakes << "/3\n";
    				displayBoard(board,mistakes,hintsLeft);
    				if (mistakes == 3) {
    					bool bought = Tries(mistakes);
    					cout << "Remaining chances: " << mistakes << "/3\n";
    				displayBoard(board,mistakes,hintsLeft);
						if (!bought) { break;}
					}
				}
			} 
			else {
            	cout << "Cell already filled.\n";
			}
    	}
		else{
           	cout << "Invalid input. Try again.\n";
		}     	
	}
    	
		if (isBoardFull(board)) 
       		cout << "Congratulations! You've completed the Sudoku!\n";
    	cout << "\nSolution Board:\n";
    	displayBoard(solutionBoard,mistakes,hintsLeft);
}

void LevelPoints(int l){
	if (l==1){
		C=C+10;
	}
	else if (l==2){
		C=C+20;
	}
	else if (l==3){
		C=C+30;
	}
}

void displayTime(int duration) {
    int minutes = duration / 60;
    int seconds = duration % 60;

    cout << "Time taken: "
         << setw(2) << setfill('0') << minutes << ":"
         << setw(2) << setfill('0') << seconds << "\n";
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
    char ans;
    cout << "Do you want to see the instructions?(y/n): ";//rctaei gia emfanisi odigion
    cin >> ans;
    ans=tolower(ans);
    while(ans!='y' && ans!='n'){
    	cout<<"Wrong input.Enter again(y/n):";
    	cin >> ans;
    	ans=tolower(ans);
	}
    if (ans == 'y') {
        instructions();
    }
    showDifficultyMenu();
    cin >> ep;
   
    while (ep < 0 || ep > 3) {
        cout << "Invalid input. Please enter a number between 0 and 3 (0 for exit): ";
        showDifficultyMenu();
        cin >> ep;
    }

    LevelPoints(ep);
    if (ep == 1) 
        visibleNumbers = 39;
    else if (ep == 2) 
        visibleNumbers = 35;
    else if (ep == 3) 
        visibleNumbers = 29;
    else {
        auto end = steady_clock::now();
		auto duration = duration_cast<seconds>(end - start).count();
		int minutes = duration / 60;
		int seconds = duration % 60;
		cout << "You exited the game.\n";
		displayTime(duration);
		return 0;
    }
    
    fillSudoku(board);
    copy(&board[0][0], &board[0][0] + SIZE * SIZE, &solutionBoard[0][0]); // Save full solution
    removeNumbers(board, visibleNumbers);

    switch (ep) {
        case 1:
			cout << "\n\tEasy level.\n"; break;
        case 2: 
			cout << "\n\tMedium level.\n"; break;
        case 3: 
			cout << "\n\tHard level.\n"; break;
    }

    
    playSudoku(board, solutionBoard);
    
    auto end = steady_clock::now();
	auto duration = duration_cast<seconds>(end - start).count();
	
	displayTime(duration);

	cout << "Your total points are: " << C << "\n";
    return 0;
}
