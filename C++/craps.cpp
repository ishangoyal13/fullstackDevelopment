/* A plyer rolls two die. Each dice  has six faces. These faces contain 1, 2, 3, 4, 5, 6 spots.
   After the dice have come to rest, the sum of the spots on the two upward faces is calculated.
   if the sum us 7 or 11 on the first rill, the player wins.
   if the sum is 2, 3 or 12 on the first roll, the player loses.
   if the sum is 4, 5, 6, 8, 9 or 10 on the first roll, then that sum becomes the player's "point". 
   To win you must continue rolling the dice until you make your point.
   The player loses  by rolling a 7 before making the point.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include <stdlib.h>

using namespace std;

unsigned int rollDice();

int main() {
    // Game status
    enum class Status {CONTINUE, WON, LOST};

    // randomize random bumber generator using current time
    srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoint{0}; //point if no win or loss on first roll
    Status gameStatus;
    unsigned int sumOfDice{rollDice()}; // first roll of dice

    // determine game status and point based on the first roll

    switch(sumOfDice) {

        case 7: // win with 7 on first roll
        case 11: // win with 11 on frist roll
            gameStatus = Status::WON;
            break;
        case 2: // loses on first roll
        case 3:
        case 12:
            gameStatus = Status::LOST;
            break;
        default:
            gameStatus = Status::CONTINUE; // game is not over yet
            myPoint = sumOfDice; // point to make
            cout << "Point is " << myPoint << endl;
            break;
    }

    // while the game is not complete
    while(Status::CONTINUE == gameStatus) {
        sumOfDice = rollDice(); // roll the dice again

        // determine the status
        if(sumOfDice == myPoint) {
            gameStatus = Status::WON;
        }
        else {
            if(sumOfDice == 7) {
                gameStatus = Status::LOST;
            }
        }
    }

    // display WON or LOST message
    if(Status::WON == gameStatus) {
        cout << "WON" << endl;
    }
    else {
        cout << "LOST" << endl;
    }

}

// roll the dice
unsigned int rollDice() {

    int die1{1 + rand() % 6}; // first die
    int die2{1 + rand() % 6}; // second die

    int sum{die1 + die2};

    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;

    return sum;
}