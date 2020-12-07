#include "GameBoard.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <curses.h>
#include <string>


int main(int argv, char *const argc[]){
GameBoard g;
string filename = argc[1];
g.print(filename);
cout << "Pick a Card or Press D to Draw" << endl;
bool exit = false;
while(!exit&&!g.complete()){
    string choice;
    
    while(cin >> choice) {
        cin.clear();
        cin.ignore();
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
        if(choice=="D") {g.draw();}
        else if(choice=="E") exit = true;
        else if(choice=="S") g.shuffleDeck();
        
        else {
            g.select(choice);
            }
        if(g.complete()) {
            g.print(filename);
            cout<<"Congratulations, you won!"<<endl;
            break;
            }
        if (exit) {
            break;
        }
        g.print(filename);
        
    }
    
    }


}

