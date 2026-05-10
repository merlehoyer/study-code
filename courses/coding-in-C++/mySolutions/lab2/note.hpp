#ifndef NOTE_HPP
#define NOTE_HPP
#include <string>

class Note{
    private: 
    std::string *text;

    public: 
    Note(std::string);
    Note(const Note &n);
    ~Note();
    void display();
};

#endif