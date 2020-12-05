#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;
struct card{
int value;
string suit;
bool hidden;
bool inPile;
bool inFinalPile;
card *prev;
card *next;
bool red;
card(){

}
card(int val, string suitt){
value = val;
suit = suitt;
prev = nullptr;
next = nullptr;
if(suit=="H"||suit=="D") red = true;
else if(suit=="C"||suit=="S") red = false;
}

string print(){
string s;
    if(hidden){
        s = "|||||";
    }
    else{
        if(value==1)s = "[A" + suit + " ]";
        else if(value==11)s = "[J"+ suit + " ]";
        else if(value==12)s = "[Q"+suit+" ]";
        else if(value==13)s = "[K"+suit+" ]";
        else if(value==10)s = "["+to_string(value)+suit+"]";
        else s = "["+to_string(value)+suit+" ]";

        /*if(next==nullptr) s+="N";
        else s+=to_string(next->value);
        if(prev==nullptr) s+="N";
        else s+=to_string(prev->value);
    */

    }
  return s;  
}

};
class CardPile{
public:
void shuffle();
CardPile();
CardPile(bool full);
card draw();
bool empty();
//void printAll();
void push(card c);
void print();
void makeEmpty();
string printStack();
card* peek();
private:
card *top;
int size; 



};