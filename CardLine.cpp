#include "CardLine.h"

CardLine::CardLine(){
head = nullptr;
tail = nullptr; 

}

void CardLine::makeEmpty(){
    head = nullptr;
    tail = nullptr;
}

card* CardLine::find(int val, string suit){
//to find if a card is in the card line, returns nullptr if its not found
card* c = head;
while(c!=nullptr&&(c->value!=val||c->suit!=suit)) c = c->next;
if(c==nullptr) return c; 

else if(c->value==val&&c->suit==suit&&!c->hidden) return c;

else{
//just a failsafe
c = nullptr;
return c;
}

}

void CardLine::add(card *c){
if(head == nullptr){
    //adding to the head of the list
    c->prev = nullptr;
    head = c;
    //in case the added card has additional cards underneath it when moved
    card *t = c;
    while(t->next!=nullptr) t = t->next;
    tail = t;
}

else{
    //just adding to the bottom of the linked list
    c->prev = tail;
    tail->next = c;
    while(c->next!=nullptr) c = c->next;
    tail = c;
}

}

bool CardLine::remove(int v, string h){

card *c = tail;
// up is prev, down is next
//find the card to remove first
while(c!=nullptr&&(c->value!=v||c->suit!=h)) c = c->prev;
if(c==nullptr) return false;
else{
    if(c->prev!=nullptr) {
        //if c is not the head, just remove everything below it
        c->prev->next = nullptr;
        //if the previous card in the line is hidden, unhide it
        if(c->prev->hidden==true) c->prev->hidden = false;
        tail = c->prev;
        tail->next = nullptr;

        }
    else {
        //if c is the head, just make the list null
          makeEmpty();
          
          }
}
return true;

}

void CardLine::setHidden(){
//when initializing the board, makes sure every card in the line is hidden except for the tail card
card *c = head;
while(c!=nullptr){
c->hidden = true;
c = c->next;
}

tail->hidden = false;
}

string CardLine::print(int v){
//when printing the game board, I go down the line and print all the cards in line 1, then line 2, line 3....this prints the card of that line.
card *c = head;

//only print the head of an empty list
if(empty()&&v==0) return "[   ]";
else if(empty()) return "";
while(v>0){
if(c->next == nullptr)  return "";
else c = c->next;
v--;
}

string s = c->print();
return s;

}

card* CardLine::gettail() { return tail; }
card* CardLine::gethead(){ return head; }
bool CardLine::empty(){ return head==nullptr; }