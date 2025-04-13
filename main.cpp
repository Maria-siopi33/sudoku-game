#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <cstdlib>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
enum Choice { ROCK = 1, PAPER, SCISSORS };//1=ROCK,2=PAPER,3=SCISSORS
void displayChoice(int choice) {//Synartisi epilogis
    switch (choice) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
        default:
            cout << "Invalid choice";
    }
}

int main(int argc, char** argv) {
	 srand(time(0)); 
    char playAgain;

    do {
        int playerChoice, computerChoice;

       
        cout << "Choose an option: \n";//Menu
        cout << "1. Rock\n2. Paper\n3. Scissors\n";
        cout << "Enter your choice (1-3): ";
        cin >> playerChoice;
        if (playerChoice < ROCK || playerChoice > SCISSORS) {
    cout << "Invalid choice! Please enter 1, 2, or 3.\n";
    continue; // Ξεκινάει ο γύρος ξανά
}
computerChoice = rand() % 3 + 1;

        // Εμφάνιση επιλογών
        cout << "You chose: ";
        displayChoice(playerChoice);
        cout << "\nComputer chose: ";
        displayChoice(computerChoice);
        cout << endl;
        
   
        if (playerChoice == computerChoice) {
            cout << "It's a tie!\n";
        } else if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
                   (playerChoice == PAPER && computerChoice == ROCK) ||
                   (playerChoice == SCISSORS && computerChoice == PAPER)) {
            cout << "You win!\n";
        } else {
            cout << "Computer wins!\n";
        }
        
        
    
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y'); 

    cout << "*****************************Goodbye***********************************\n";

    return 0;

}
