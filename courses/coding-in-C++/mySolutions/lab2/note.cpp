#include "note.hpp"
#include <string>
#include <iostream>

Note::Note(std::string text){
    this->text= new std::string (text);
}

Note::Note(const Note &n){
    this->text= new std::string(*n.text);
}

Note::~Note(){
    delete text;
    text= nullptr;
    std::cout<<"Memory released"<<std::endl;
}

void Note::display(){
    std::cout<<*text<<std::endl;
    return;
}