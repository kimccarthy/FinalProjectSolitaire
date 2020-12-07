#include "GameBoard.h"
#include<fstream>
#include<iostream>

using namespace std;

GameBoard::GameBoard(){
   for(int i = 0; i<4; i++){
        finals[i].makeEmpty();
    }
    for(int i = 1; i<=13; i++){
            card h(i, "H");
            card d(i, "D");
            card s(i, "S");
            card c(i, "C");
            h.hidden = true;
            d.hidden = true;
            s.hidden = true;
            c.hidden = true;
         
            drawPile.push(h);
            drawPile.push(d);
            drawPile.push(s);
            drawPile.push(c);  

            }
drawPile.shuffle();

for(int i = 0; i<7; i++){
  for(int j = 0; j<=i; j++){
      card c = drawPile.draw();
      card *crd = new card(c.value, c.suit);
      crd->inPile = false;
      lines[i].add(crd);
  }
}
for(int i = 0; i<7; i++){
lines[i].setHidden();
}
}

void GameBoard::print(string filename){
filebuf fb;
fb.open(filename, ios::out);
ostream os(&fb);

os<<"H: "<<finals[0].printStack();
os<<"    D: "<<finals[1].printStack();
os<<"    C: "<<finals[2].printStack();
os<<"    S: "<<finals[3].printStack();
os<<endl;
os<<endl;
/*for(int i = 0; i<7;i++){
if(lines[i].gethead()==NULL) os<<"NULL    ";
else os<<lines[i].gethead()->value<<lines[i].gethead()->suit<<"   ";

}
os<<endl;
for(int i = 0; i<7;i++){
if(lines[i].gettail()==NULL) os<<"NULL    ";
else os<<lines[i].gettail()->value<<lines[i].gettail()->suit<<"   ";

}
os<<endl;
*/
bool b = false;
int linenum = 0;
while(!b){
b = true;
for(int i = 0; i<7; i++){
    string s = lines[i].print(linenum);
    if(s!="") { 
        os<<s<<"      ";
        b = false;

    }
    else{
        os<<"           ";
    }
    
    
}
linenum++;
os<<endl;
}
os<<endl;
os<<endl;


os<< drawPile.printStack()<<"     ";
os<<discard.printStack();
os<<endl;
os<<endl;
os << "Pick a Card or Press D to Draw" << endl;
if(drawPile.empty()) os<<"Press S to Shuffle the Discard Pile"<<endl;
fb.close();
}

card* GameBoard::select(){
int line = 0;
card *crd = lines[0].gettail();
char inn;
//assume we start with tail of 0
while(inn!='e'){
//cout<<"Selected: ";
//crd->print();
cout<<endl;
cin>>inn;
if(inn=='w'){
    if(crd->prev!=nullptr&&!crd->prev->hidden) crd = crd->prev;
    else crd = lines[line].gettail();
}
else if(inn=='s'){
    if(crd->next!=nullptr) crd = crd->next;
    else{
        card *find = lines[line].gethead();
        while(!find->hidden) find = find->next;
        crd = find->next;
    }

}
else if(inn=='a'){
    if(line==0){
        line = 6;
        while(lines[line].gettail()==nullptr) line--;
        crd = lines[line].gettail();
    }
    else{
        line--;
        while(lines[line].gettail()==nullptr){
            if(line==0) line = 6;
            else line--;
        }
        crd = lines[line].gettail();

    }


}
else if(inn=='d'){
if(line==6){
        line = 0;
        while(lines[line].gettail()==nullptr) line++;
        crd = lines[line].gettail();
    }
    else{
        line++;
        while(lines[line].gettail()==nullptr){
            if(line==6) line = 0;
            else line++;
        }
        crd = lines[line].gettail();

    }


}
else{
    cout<<"Invalid Input"<<endl;
}


}
return crd; 

}

card* GameBoard::find(int val, string suit){
card* c = new card(0, "N");
c = nullptr;
if(!discard.empty()&&discard.peek()->value==val&&discard.peek()->suit==suit){
   c = discard.peek();
   return c;
}
for(int i = 0; i<7; i++){
c = lines[i].find(val, suit);
if(c!=nullptr) {
    return c;
    break;
}

}
c = nullptr;
cout<<"Card Not Found"<<endl;
return c; 

}

bool GameBoard::select(string s){


if (s == "D"){
    draw();
    return true;
}

string str = s.substr(0, s.size()-1);
 transform(str.begin(), str.end(), str.begin(), ::toupper);
int val;
try{
if(str=="K") val = 13;
else if(str=="Q") val = 12;
else if(str=="J") val = 11;
else if(str=="A") val = 1;
else val = stoi(str);

}
catch(exception &err){
cout<<"Invalid Input"<<endl;
return false;
}
string str2 = s.substr(s.size()-1);
card *c = find(val, str2);

if(c!=nullptr){
  move(c);

}
else{
    cout<<"Invalid Card"<<endl; 
    return false;
}

return true; 
}

void GameBoard::draw(){
if(!drawPile.empty()) discard.push(drawPile.draw());
else cout<<"Draw Pile is Empty! Press S to Shuffle Discard Pile";


}

bool GameBoard::move(card* crd){
//if the card is an Ace it is automatically moved to its designated pile
if(crd->value==1){
        bool found = false;
        if(!discard.empty()&&crd->value==discard.peek()->value&&crd->suit==discard.peek()->suit) { 
            discard.draw();
            found = true;
            }
        else{
            for(int j = 0; j<7; j++){
                 if(lines[j].find(crd->value, crd->suit)!=nullptr) {
                     lines[j].remove(crd->value, crd->suit);
                     found = true;      
                  }
            }

        }
        if(!found) {
            cout<<"Card Not Found"<<endl; 
            return false;
            }
        
        card a = {crd->value, crd->suit};
        a.inFinalPile = true;
        a.hidden = false; 
        if(crd->suit=="H") finals[0].push(a);
        else if(crd->suit=="S") finals[3].push(a);
        else if(crd->suit=="D") finals[1].push(a);
        else finals[2].push(a);   
        return true;  
    
}
//if its an ace its already gone through its process and returned a bool, so this will catch all others

for(int i = 0; i<4; i++){
if(!finals[i].empty()&&crd->value==(finals[i].peek()->value+1)&&crd->suit==finals[i].peek()->suit){
bool found = false;
if(!discard.empty()&&discard.peek()->value==crd->value&&discard.peek()->suit==crd->suit) {
    discard.draw();
    found = true;
    }
for(int j = 0; j<7; j++){
    if(lines[j].find(crd->value, crd->suit)!=nullptr&&crd->next==nullptr) { 
    lines[j].remove(crd->value, crd->suit);
    found = true;
    }
}
if(found) {
    card a = {crd->value, crd->suit};
    a.inFinalPile = true;
    a.hidden = false;
    finals[i].push(a);
    return true;
    }

}

}

//find if the card is in the pile
bool found = false;
if(!discard.empty()&&discard.peek()->suit==crd->suit&&discard.peek()->value&&crd->value){
    //discard.draw();
    found = true;
}


//find if the card is on the board, if so, where
int cLine = -1;
for(int j = 0; j<7; j++){
    if(!lines[j].empty()&&lines[j].find(crd->value, crd->suit)!=nullptr) { 
    cLine = j; 
    found = true;
    }
}

if(!found) {
    cout<<"Card Not Found"<<endl;
    return false;
    }

if(crd->value==13){
bool found = false;
for(int i = 0; i<7; i++){
if(lines[i].empty()){
    
    if(cLine!=-1) lines[cLine].remove(crd->value, crd->suit);
    else discard.draw();
    lines[i].add(crd);
    return true;

}

}

}

for(int i = 0; i<7; i++){
    if(!lines[i].empty()){
    card *d = lines[i].gettail();
    if(d->value==(crd->value+1)){
        if(((d->red&&!crd->red)||(!d->red&&crd->red))&&!d->hidden){
        if(cLine!=-1){
            lines[cLine].remove(crd->value, crd->suit);
            //cout<<"Removing "<<crd->print()<<" from line"<<cLine;
            card *c = crd;
            while(c->next!=nullptr) c = c->next;
            //cout<<" to card "<<c->print()<<endl;

        }
        else discard.draw();
             
            lines[i].add(crd);
            return true;
        }

    }
}} 
cout<<"Cannot Move Card"<<endl;
return false;

}

void GameBoard::shuffleDeck(){
if(drawPile.empty()){
discard.shuffle();
while(!discard.empty()) {
    card crd = discard.draw();
    crd.hidden = true;
    drawPile.push(crd);
}}

else cout<<"Draw Pile is Not Empty"<<endl;
}

bool GameBoard::complete(){
for(int i = 0; i<7; i++){
if(!lines[i].empty()) return false;
}
//cout<<"All lines empty"<<endl;
//shouldn't get here if any of the lines have stuff in them
if(discard.empty()&&drawPile.empty()) { 
    //cout<<"Congratulations, You've Won!"<<endl; 
    return true;
    }
return false;
}