#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "CardLine.h"
#include <vector>

using namespace std;

class GameBoard{
public:
GameBoard();
void newGame();
void print(string filename);//make sure to clear previous input
card* select();//add an input here
void draw();
void shuffleDeck();//only if the discard is empty
bool select(string s);
bool move(card* c);
bool complete();

private:
CardLine lines[7];
CardPile drawPile;
CardPile discard;
CardPile h;
CardPile c;
CardPile s;
CardPile d;
CardPile finals[4] = {h, c, s, d};
card* find(int val, string suit);



};