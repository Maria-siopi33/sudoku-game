#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
//lol
using namespace std;
int C = 0;
const int SIZE = 9;

void instructions(){
	cout<<"Accordingly to the level of difficulty you will choose, we offer you some points to purchase a help if you need it.\n";
	cout<<"Levels:\n";
	cout << "1. Easy: 10 points\n";
    cout << "2. Medium: 20 points\n";
    cout << "3. Hard: 30 points\n";
    cout<<"With every number you find you win 2 additional points. \n";
    cout<<"With every mistake you do you lose 2 points from your total. \n";
}

void showDifficultyMenu() {
    cout << "\nChoose difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "0. Exit\n";
    cout << "Your choice: ";
}

void displayBoard(int board[SIZE][SIZE], int mistakes = 0) {
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
                cout << "You won two points with your correct answer. Total amount: " << C << "\n";
            } else {
                C -= 2;
                cout << "You lost two points with your wrong answer. Total amount: " << C << "\n";
            }
        }
    }
}



void playSudoku(int board[SIZE][SIZE], int solutionBoard[SIZE][SIZE]) {
    int row, col, num;
    int mistakes=0;
    
    displayBoard(board, mistakes);

    while (!isBoardFull(board)) {
        cout << "\nEnter row (1-9), column (1-9), and number (1-9),[Enter 0 0 0 for exit]: ";
        cin >> row >> col >> num;
        
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
    				displayBoard(board,mistakes);
				} 
				else {
    				mistakes++;
    				cout << "Mistakes:" << mistakes << "/3\n";
    				displayBoard(board, mistakes);
    				if (mistakes == 3) {
    					cout << "No more chances. Game over.\n";
    					break;
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
    	displayBoard(solutionBoard);
}

void LevelPoints(int l){
	if (l==1){
		C=C+10;
		//cout<< "You have " << C << "points.\n"; efoson emfanizontai oi pontoi mazi me ton pinaka autew tiw emaniseis mporoyme na tis afairesoume
	}
	else if (l==2){
		C=C+20;
		//cout<< "You have " << C << "points.\n";
	}
	else if (l==3){
		C=C+30;
		//cout<< "You have " << C << "points.\n";
	}
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
    instructions();
    showDifficultyMenu();
    cin >> ep;
   
    while (ep < 0 || ep > 3) {
        cout << "Invalid input. Please enter a number between 0 and 3 (0 for exit): ";
        showDifficultyMenu();
        cin >> ep;
    }

    LevelPoints(ep);
    if (ep == 1) 
        visibleNumbers = 36;
    else if (ep == 2) 
        visibleNumbers = 32;
    else if (ep == 3) 
        visibleNumbers = 26;
    else {
        auto end = steady_clock::now();
		auto duration = duration_cast<seconds>(end - start).count();
		int minutes = duration / 60;
		int seconds = duration % 60;
		cout << "You exited the game.\n";
		if (minutes<1)
			cout << "Time taken:" << seconds << " seconds.\n";//emfanisi tou xronoy se morfi mm:ss
		else
			cout << "Time taken:" << minutes << ":" << seconds << " minutes.\n";//emfanisi tou xronoy se morfi mm:ss	
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
	int minutes = duration / 60;
	int seconds = duration % 60;

	if (minutes < 1)
    	cout << "Time taken: " << seconds << " seconds.\n";
	else
   		cout << "Time taken: " << minutes << ":" << seconds << " minutes.\n";

	cout << "Your total points are: " << C << "\n";
    return 0;
}
