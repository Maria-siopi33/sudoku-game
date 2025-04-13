#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;//dinei ta diafora epipeda
 const int SIZE = 9;
   void showDifficultyMenu() {
    cout << "\nChoose difficullty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "ep: ";
}


void displayBoard(int board[SIZE][SIZE]) {//pinakas sudoku xvris noumera
    cout << "-------------------------\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "| ";
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                cout << ". ";
            else
                cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0) cout << "-------------------------\n";
    }
}

// elexei an mporei na mpei o arithmos
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) { //an o ariuthmos poy ua baleis yparxei idi  h sto tetragvno 3*3

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

// gemizei anadromika ton pinaka 
bool fillSudoku(int board[SIZE][SIZE], int row = 0, int col = 0) {
    if (row == SIZE - 1 && col == SIZE) return true;
    if (col == SIZE) {
        row++;
        col = 0;
    }
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    random_shuffle(nums.begin(), nums.end());//anakateyei ton arithmous se tyxaia seira.

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

int main(){

    srand(time(0));

    int board[SIZE][SIZE] = {0};
    cout << "==============================\n";
    cout << " Welcome to Sudoku!\n";
    cout << "==============================\n";
    int ep;//epilogi xrhsth
    showDifficultyMenu();
    cin >>ep;//elexos egkyrothtas
    int visibleNumbers;
    
    if (ep == 1) visibleNumbers = 36;//me bash thn analogi dyskolia soy emfanizei analoga ariumous
    else if (ep == 2) visibleNumbers = 32;
    else visibleNumbers = 26;
    
    fillSudoku(board);
    removeNumbers(board, visibleNumbers);
   
    switch (ep) {
        case 1:
            cout << "Easy level\n";
          displayBoard(board);
            break;
        case 2:
            cout << "difficult level.\n";
           displayBoard(board);
            break;
        case 3:
            cout << "more difficult.\n";
          displayBoard(board);
            break;
        default:
            cout << "you didnt chose correctly.\n";
            break;
            
    }

    

   return 0; 
    
    
}



 
