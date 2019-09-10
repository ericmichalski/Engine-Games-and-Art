#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>

using namespace std;

// Author:  Eric Michalski
// Copyright 2019, All Rights Reserved

class Board{
public:
    void SetBoard(const int Rows = 10, const int Col = 10, const char in_fillchar = '_', int chance = 2, string in_answer = "random", int in_r1 = 2, int in_r2_1 = 2, int in_r2_2 = 3, int in_r3 = 3, int in_r4 = 3){   // Fills board with entered char and size
        numLines = Rows;
        numColumns = Col;
        fill_char = in_fillchar;
        answer = in_answer;
        r1 = in_r1;
        r2_1 = in_r2_1;
        r2_2 = in_r2_2;
        r3 = in_r3;
        r4 = in_r4;
        for(int r = 0; r < numLines; r++) {
             for(int c  = 0; c < numColumns; c++) {
                 if (RandCell(chance) == 1 && answer == "random"){       // If user wants random board
                     nboard[r][c] = '*';
                 }
                 else{                                          // If user wants certain shape
                     nboard[r][c] = fill_char;
                 }
             }
        }
    }

    int RandCell(int in_chance){
        return rand() % in_chance;
    }

    void CheckCells(){      // Checks each cell for rules
        int count, count2, r, c;
        bool change = true;
        bool change2 = true;
        while (change && change2){
            for(r = 0; r < numLines; r++) {
                for(c = 0; c < numColumns; c++) {
                    if (nboard[r][c] == '*'){
                        count = 0;
                        if (nboard[r-1][c] == '*'){
                            count++;
                        }
                        if (nboard[r+1][c] == '*'){
                            count++;
                        }
                        if (nboard[r][c-1] == '*'){
                            count++;
                        }
                        if (nboard[r][c+1] == '*'){
                            count++;
                        }
                        if (nboard[r+1][c+1] == '*'){
                            count++;
                        }
                        if (nboard[r-1][c+1] == '*'){
                            count++;
                        }
                        if (nboard[r-1][c-1] == '*'){
                            count++;
                        }
                        if (nboard[r+1][c-1] == '*'){
                            count++;
                        }
                        if (count > r3 || count < r1){      // Rule 1 and 3
                            nboard[r][c] = '_';
                            change = true;
                        }
                    }
                    else {
                        count2 = 0;
                        if (nboard[r-1][c] == '*'){
                            count2++;
                        }
                        if (nboard[r+1][c] == '*'){
                            count2++;
                        }
                        if (nboard[r][c-1] == '*'){
                            count2++;
                        }
                        if (nboard[r][c+1] == '*'){
                            count2++;
                        }
                        if (nboard[r+1][c+1] == '*'){
                            count2++;
                        }
                        if (nboard[r-1][c+1] == '*'){
                            count2++;
                        }
                        if (nboard[r-1][c-1] == '*'){
                            count2++;
                        }
                        if (nboard[r+1][c-1] == '*'){
                            count2++;
                        }
                        if (count2 == r4){              // Rule 4
                            nboard[r][c] = '*';
                            change2 = true;
                        }
                    }
                }
            }
            generation++;
            system("CLS");
            display();
        }
    }

    void Begin(){     // Initializes board with cells

        int middleLine = numLines / 2;
        int middleCol = numColumns / 2;

        if (answer == "predet"){
            nboard[middleLine][middleCol] = '*';
            nboard[middleLine][middleCol - 1] = '*';
            nboard[middleLine + 1][middleCol] = '*';
            nboard[middleLine][middleCol + 1] = '*';
            nboard[middleLine - 1][middleCol + 1] = '*';
            nboard[middleLine - 1][middleCol - 1] = '*';
            nboard[middleLine + 1][middleCol + 1] = '*';
            nboard[middleLine + 1][middleCol - 1] = '*';
            nboard[middleLine - 1][middleCol] = '*';

            nboard[middleLine - 1][middleCol - 2] = '*';
            nboard[middleLine][middleCol - 2] = '*';
            nboard[middleLine + 1][middleCol - 3] = '*';
        }

        CheckCells();
    }

    void display(){                 // Displays board
        cout << "Board: " << endl;
        cout << "Generation: " << generation << endl;

        for(int r = 0; r < numLines; r++) {
            for(int c = 0; c < numColumns; c++) {
                cout << nboard[r][c];
            }
            cout << endl;
        }
    }

private:
    int r1, r2_1, r2_2, r3, r4;
    int generation = 0;
    char fill_char;
    int numLines, numColumns;
    char nboard[' '][' '];
    string answer;
};

vector<int> breakupstring(string str){
    vector<int> numdata;
    stringstream ss;
    ss << str;

    while(!ss.eof()){
        int temp;
        ss >> temp;
        numdata.push_back(temp);
    }

    return numdata;
}

class Rule{                 // Allows changes to inital settings of game through either text file or input
    friend ostream & operator<<( ostream &output, const Rule &R ){
        output << R.R1 << endl << R.R2_1 << endl <<  R.R2_2 <<  R.R3 << endl << endl << R.R4 << endl << R.LB << endl << R.WB << endl << R.chan;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Rule &R ){
     input >> R.R1 >> R.R2_1 >> R.R2_2 >> R.R3 >> R.R4 >> R.LB >> R.WB >> R.chan;
       return input;
   }
public:

  Rule()
    {
    R1 = 2;
    R2_1 = 2;
    R2_2 = 3;
    R3 = 3;
    R4 = 3;
    LB = 10;
    WB = 10;
    chan = 10;
     }

    Rule (int in_R1, int in_R2_1, int in_R2_2, int in_R3, int in_R4, int in_LB, int in_WB, int in_chan)
    {
        R1 = in_R1;
        R2_1 = in_R2_1;
        R2_2 = in_R2_2;
        R3 = in_R3;
        R4 = in_R4;
        LB = in_LB;
        WB = in_WB;
        chan = in_chan;

    }

    int getR1()
    {
        return R1;
    }
    int getR2_1()
    {
        return R2_1;
    }
    int getR2_2()
    {
        return R2_2;
    }
    int getR3()
    {
        return R3;
    }
    int getR4()
    {
        return R4;
    }
    int getLB()
    {
        return LB;
    }
    int getWB()
    {
        return WB;
    }
    int getchan()
    {
        return chan;
    }
    void setR1(int in_R1)
    {
        R1 = in_R1;
    }
    void setR2_1(int in_R2_1)
    {
        R2_1 = in_R2_1;
    }
    void setR2_2(int in_R2_2)
    {
        R2_2 = in_R2_2;
    }
    void setR3(int in_R3)
    {
        R3 = in_R3;
    }
    void setR4(int in_R4)
    {
        R4 = in_R4;
    }
    void setLB(int in_LB)
    {
        LB = in_LB;
    }
    void setWB(int in_WB)
    {
       WB = in_WB;
    }
    void setchan(int in_chan) {
        chan = in_chan;
    }

    void display()
    {
         cout << "Any cell with fewer than " << getR1() << " dies, as if by underpopulation." << endl;
         cout << "Any cell with " << getR2_1() << " or " << getR2_2() << " neighbors lives on to the next generation." << endl;
         cout << "Any live cell with more than " << getR3() << " neighbors dies, as if by overpopulation." << endl;
         cout << "Any cell with exactly " << getR4() << " neighbors becomes a live cell, as if by reproduction." << endl;
         cout << "The length of the board is " << getLB() << " units." << endl;
         cout << "The width of the board is " << getWB() << " units." << endl;
         cout << "The chance of a cell being living initially is a 1 out of " << getchan() << " chance." << endl;

    }

private:
  int R1, R2_1, R2_2, R3, R4, LB, WB, chan;
};

int main(){
    string answer1 = "random";
    srand(unsigned (time(nullptr)));
    int rule1 = 2;
    int rule2_1 = 2;
    int rule2_2 = 3;
    int rule3 = 3;
    int rule4 = 3;
    int lengthboard = 10;
    int widthboard = 10;
    int area = lengthboard * widthboard;
    int chance = 10;
    Rule R;
    Board newboard;
    char answer;
    string string1;
    ifstream inFile;

    inFile.open("C:\\temp\\Rule.txt");      // Opens file;
    vector<int> numbers;
    cout << "Rules: " << endl;
    while (!inFile.eof()){
        getline(inFile, string1);
        numbers = breakupstring(string1);
        rule1 = numbers.at(0);
        cout << "Any cell with fewer than " << rule1 << " dies, as if by underpopulation." << endl;
        rule2_1 = numbers.at(1);
        rule2_2 = numbers.at(2);
        cout << "Any cell with " << rule2_1 << " or " << rule2_2 << " neighbors lives on to the next generation." << endl;
        rule3 = numbers.at(3);
        cout << "Any live cell with more than " << rule3 << " neighbors dies, as if by overpopulation." << endl;
        rule4 = numbers.at(4);
        cout << "Any cell with exactly " << rule4 << " neighbors becomes a live cell, as if by reproduction." << endl;
        lengthboard = numbers.at(5);
        cout << "The length of the board is " << lengthboard << " units." << endl;
        widthboard = numbers.at(6);
        cout << "The width of the board is " << widthboard << " units." << endl;
        area = lengthboard * widthboard;
        cout << "This means the area of the board is exactly " << area << " units." << endl;
        chance = numbers.at(7);
        cout << "The chance of a living cell spawning inititially is a 1 out of " << chance << " chance." << endl;
    }

    do{
        cout << endl << "Would you like to change these rules before starting? (y/n)" << endl;      // Checks if user wants to change rules
        cin >> answer;
        if (answer != 'y' && answer != 'n'){
            cout << "Error: Wrong Input. Input 'y' or 'n'" << endl;
        }
    }
    while(answer != 'y' && answer != 'n');

    if (answer == 'y')      // Changes Rules
    {
        do{
            cout << "Ok then. Fill in the blanks with an integer. IN ORDER, for example, 1 4 7 6 9 8." << endl;
            cout << "Any cell with fewer than " << "___" << " dies, as if by underpopulation." << endl;                     // Rule 1
            cout << "Any cell with " << "___" << " or " << "___" << " neighbors lives on to the next generation." << endl;  // Rule 2
            cout << "Any live cell with more than " << "___" << " neighbors dies, as if by overpopulation." << endl;        // Rule 3
            cout << "Any cell with exactly " << "___" << " neighbors becomes a live cell, as if by reproduction." << endl;  // Rule 4
            cout << "The length of the board is " << "___" << " units." << endl;                                            // Length
            cout << "The width of the board is " << "___" << " units wide." << endl;                                        // Width
            cout << "The chance of a cell being living initially is a 1 out of " << "___" << " chance." << endl;            // Chance
            cin >> R;
            cout << endl << "Rules: " << endl;
            R.display();
            if (R.getR1() <= 0 || R.getR2_1() <= 0 || R.getR2_2() <=0 || R.getR3() <= 0 || R.getR4() <= 0 || R.getLB() <= 0 || R.getWB() <= 0 || R.getchan() <= 0 || R.getLB() >= 50 || R.getWB() > 50){
                cout << endl << "Error: Invalid input. Please enter a positive number greater than 0 and a length/width less than 50" << endl << endl;
            }
        }
        while(R.getR1() <= 0 || R.getR2_1() <= 0 || R.getR2_2() <=0 || R.getR3() <= 0 || R.getR4() <= 0 || R.getLB() <= 0 || R.getWB() <= 0 || R.getchan() <= 0 || R.getLB() >= 50 || R.getWB() > 50);
    }
    else if (answer == 'n')
    {
        cout << "Fine then. Let the hunt, BEGIN!" << endl;
    }

    do{
        cout << endl << "Do you want to use random or predetermined cell spawns? (random/predet) " << endl;
        cin >> answer1;
        if (answer1 != "random" && answer1 != "predet"){
            cout << "Error: Wrong input. Input 'random' or 'predet'" << endl;
        }
    }
    while (answer1 != "random" && answer1 != "predet");     // Checks if user wants random initial cells or a predetermined spot

    lengthboard = R.getLB();
    widthboard = R.getWB();
    rule1 = R.getR1();
    rule2_1 = R.getR2_1();
    rule2_2 = R.getR2_2();
    rule3 = R.getR3();
    rule4 = R.getR4();
    chance = R.getchan();

    if (lengthboard >= 50 || widthboard > 50 || rule1 <= 0 || rule2_1 <= 0 || rule2_2 <= 0 || rule3 <= 0 || rule4 <= 0){
        cout << "Error: Cannot enter a length or width greater than 50 (due to slow operation), or a negative number in any position" << endl;
    }
    else if (area > 0 && lengthboard < 50 && widthboard <= 50 && lengthboard > 0 && widthboard > 0 && rule1 > 0 && rule2_1 > 0 && rule2_2 > 0 && rule3 > 0 && rule4 > 0){       // Begins game of life
        system("CLS");
        newboard.SetBoard(lengthboard,widthboard, '_', chance, answer1, rule1, rule2_1, rule2_2, rule3, rule4);
        newboard.Begin();
     }
     else{
        cout << "Error: Invalid entry" << endl;
     }
    return 0;
}
