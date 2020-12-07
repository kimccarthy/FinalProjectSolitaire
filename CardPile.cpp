#include "CardPile.h"
#include <time.h>

CardPile::CardPile(){
top = nullptr;
size = 0;
}

CardPile::CardPile(bool full){
//bool says whether it should be initialized as an empty pile to be discarded on or the draw pile;

if(!full){
    top = nullptr; 
}
else{
top = nullptr;
    for(int i = 1; i<=13; i++){
        card h(i, "H");
        card d(i, "D");
        card s(i, "S");
        card c(i, "C");
        h.hidden = true;
        d.hidden = true;
        s.hidden = true;
        c.hidden = true;

        push(h);
        push(d);
        push(s);
        push(c);
        //shuffle needs to set top
    }

}


}

void CardPile::print(){
card *c = top;
//cout<<"aqui"<<endl;
while(c!=nullptr){
    c->print();
    cout<<" ";
    c = c->prev;

}
cout<<endl;

}

void CardPile::makeEmpty(){
top = nullptr; 
size =0;
}

string CardPile::printStack(){
string s;
if(!empty()){
s = top->print();
//cout<<" Full";
}
else{
s = "[    ]";

}
return s; 

}

void CardPile::push(card cr){
size++;
//cout<<"Size is now "<<size<<endl;
card *c = new card(cr.value, cr.suit);
//c = &cr;
c->hidden = cr.hidden;
if(top == nullptr) c->prev = nullptr;    
else c->prev = top;    
top = c;

//top->print();
//cout<<endl;
}

card CardPile::draw(){
card c = {0, "N"};
if(top==nullptr) { 
    return c; 

    } 

else{
size--;
c.value = top->value;
c.suit = top->suit;
c.hidden = false;
if(top->prev!=nullptr) {
    //deck is not now empty
    top = top->prev; 
    
     }
else top = nullptr;
//deck is now empty

return c; 
}
}

bool CardPile::empty(){
    return (top==nullptr);
}

card* CardPile::peek(){
return top;
}

void CardPile::shuffle(){
int t = size;
card cards[size];
//make an array the size of the cards

for(int i = 0; i<t; i++){
//push the values into the array and hide them all
    cards[i] = draw();
    cards[i].hidden = true;
}
    srand (time(NULL));  
    for (int i = t-1; i > 0; i--)  
    {    
    //for the size of the array, generate a random index and swap said index with another random card
        int j = rand() % (i + 1);  
        swap(cards[i], cards[j]);  
    }  
//push cards back into deck
for(int i = 0; i<t; i++)push(cards[i]);
}



