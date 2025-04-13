#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
   void showDifficultyMenu() {
    cout << "\nChoose difficullty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "ep: ";
}
int main(){

    cout << "==============================\n";
    cout << " Welcome to Sudoku!\n";
    cout << "==============================\n";
    int ep;//epilogi xrhsth
    showDifficultyMenu();
    cin >>ep;
    switch (ep) {
        case 1:
            cout << "Easy level""\n";
          
            break;
        case 2:
            cout << "difficult level.\n";
           
            break;
        case 3:
            cout << "more difficult.\n";
          
            break;
        default:
            cout << "you didnt chose correctly.\n";
            break;
    }

   return 0; 
    
    
}
    
 
