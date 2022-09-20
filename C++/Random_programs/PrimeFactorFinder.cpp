/* 
Author: Tawhid Khan 
Class: ECE 6122-A
Last Date Modified: 9/21/2021

Description:

Lab1 problem 2 takes in how many moves are allowed and outputs how many black squares
have been used by the Ant. The input is an integer in command line and output is an integer
in a text file. 
*/ 


#include <iostream>
#include <string>
#include <stdlib.h>  
#include <stdio.h> 
#include <fstream> 
#include <bits/stdc++.h>
#include <iterator>
#include <utility>
#include <math.h> 

using namespace std;

/*
This function returns true only if the input number is a positive integer.
*/
bool isNumber(char number[])
{

    //checking for negative numbers
    if (number[0] == '-'){
        return false;
    }
    // go through all the digits and see if they are numerical
    for (int i = 0; number[i] != 0; i++)
    {
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}

/*
This function updates the position of the ant based on its input of current x,y position
and the next move it should make. 
*/
void move(pair<int, int> &pos, const char &next)
{

    if (next == 'u') pos.second++;
    else if(next == 'r') pos.first++;
    else if(next == 'l') pos.first--;
    else pos.second--;
}

/*
This function updates the next move ant should make based on the input which is current position
and which direction it needs to rotate which can be counterclockwise or clockwise. 
*/
void rotate(char &next, const string direction)
{

    if (direction == "counterclockwise"){
        if (next == 'u') next = 'l';
        else if(next == 'r') next = 'u';
        else if(next == 'l') next = 'd';
        else next = 'r';
    } else{
        if (next == 'u') next = 'r';
        else if(next == 'r') next = 'd';
        else if(next == 'l') next = 'u';
        else next = 'l';
    }
}

/*
This main function will parse the command line argument and call the function 
and run a loop that moves the ant around the board based on how many moves it is allowed to make.
The number of moves is an input from command line and it will output how many black squares
there are after the moves are run. The output will be recorded in a text file
*/
int main(int argc, char* argv[])
{

    // There must be a single command line input
    if(argc !=2){
    	ofstream ofs ("output2.txt", ofstream::out);
		ofs << "0" << endl;
		ofs.close();
    	return 0;
    }
    // Input must be a positive number
    if (isNumber(argv[1]) == false){
    	ofstream ofs ("output2.txt", ofstream::out);
		ofs << "0" << endl;
		ofs.close();    	
    	return 0;
    }
    unsigned long moves = strtoul(argv[1], NULL, 0);
    // This map records whether a position x,y is black square or white tire. If it is black square
    // then its value will be 1 while key will be the position
    std::map< std::pair<int,int>, int> blacks;
    // Initialize the positions and first position will become black since ant is here.
    blacks[std::make_pair(0,0)] = 1;
    std::pair<int,int> pos;
    pos.first = 0;
    pos.second = 0;
    // next move can be r = right, u = up, d= down, or l = left
    char next = 'r';
    move(pos, next);
    moves--;
    // while you can make a move, move the ant and change the color of the tile and direction
    // it is going based on whether the tile is black or white. 
    while (moves>0){
        // current tile is white
        if (blacks.find(pos)==blacks.end()){
            blacks[pos] = 1;
            rotate(next, "clockwise");
            move(pos, next);
        } else{
            blacks.erase(pos);
            rotate(next, "counterclockwise");
            move(pos, next);
        }
        moves--;
    }
    ofstream ofs ("output2.txt", ofstream::out);
    ofs << blacks.size() << endl;
    ofs.close();        
    return 0;
}
