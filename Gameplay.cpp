#include "GameBoard.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <curses.h>

int main(){
GameBoard g;
g.print("output.txt");
cout << "Pick a Card or Press D to Draw" << endl;
bool exit = false;
while(!exit&&!g.complete()){
    string choice;
    
    while(cin >> choice) {
        cin.clear();
        cin.ignore();
        if(choice=="D") {g.draw();}
        else if(choice=="E") exit = true;
        else if(choice=="S") g.shuffleDeck();
        
        else {
            g.select(choice);
            }
        
        if (exit) {
            break;
        }
        g.print("output.txt");
        
    }
    
    }


}

