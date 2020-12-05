#include "CardLine.h"


CardLine::CardLine(){
head = nullptr;
tail = nullptr; 

}
card* CardLine::gettail(){
return tail;

}
card* CardLine::gethead(){
    return head;
}
void CardLine::makeEmpty(){
    head = nullptr;
    tail = nullptr;
}
card* CardLine::find(int val, string suit){
card* c = head;
while(c!=nullptr&&(c->value!=val||c->suit!=suit)) c = c->next;

if(c==nullptr) return c; 
else if(c->value==val&&c->suit==suit&&!c->hidden) return c;
else{

c = nullptr;
return c;

}
}


void CardLine::add(card *c){
if(head == nullptr){
    c->prev = nullptr;
    head = c;
    card *t = c;
    while(t->next!=nullptr) t = t->next;
    tail = t;
    

}
else{
    c->prev = tail;
    tail->next = c;
    while(c->next!=nullptr) c = c->next;
    tail = c;

}

}

bool CardLine::remove(int v, string h){
//you'll have to add a value to a new line before removing this
card *c = tail;
// up is prev, down is next
while(c!=nullptr&&(c->value!=v||c->suit!=h)) c = c->prev;

if(c==nullptr) return false;
else{
    //cout<<"Up here, C is:"<<c->print()<<endl;
    if(c->prev!=nullptr) {
        c->prev->next = nullptr;
        //cout<<"Removal Process: C is selected as"<<c->print()<<endl;
        //cout<<"C->Prev is "<<c->prev->print()<<endl;
        if(c->prev->hidden==true) c->prev->hidden = false;
        tail = c->prev;
        //cout<<"Tail is now set to: "<<tail->print()<<endl; 
        tail->next = nullptr;
        //cout<<"New Tail: "<<tail->print()<<endl;

        }
    else {
          makeEmpty();
          
          }

}
return true;

}
void CardLine::print(){
card *c = head;
while(c!=nullptr){
    c->print();
    cout<<endl;
    c = c->next;
}
}
void CardLine::setHidden(){
card *c = head;
while(c!=nullptr){
c->hidden = true;
c = c->next;

}
tail->hidden = false;


}
string CardLine::print(int v){
card *c = head;
if(empty()&&v==0) return "[   ]";
else if(empty()) return "";
while(v>0){
if(c->next == nullptr)  return "";
else c = c->next;
v--;

}
string s = c->print();
//cout<<endl;
return s;

}
bool CardLine::empty(){
return head==nullptr;

}