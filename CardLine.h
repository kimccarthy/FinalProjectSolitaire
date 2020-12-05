#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "CardPile.h"

using namespace std;

class CardLine{
public:
CardLine();
void add(card *c);
bool remove(int v, string h); //include unhiding
void print();
string print(int i);
void setHidden();
card* gettail(); 
card* gethead(); 
card* find(int val, string suit);
void makeEmpty();
bool empty();
private:
card* head;
card* tail;






};