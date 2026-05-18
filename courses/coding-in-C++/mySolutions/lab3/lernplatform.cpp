#include "lernplatform.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void Platform::createCourse(std::string titel, std::string description){
    Courses course(titel,description);
    Course.push_back(course);
    return;
}
void Platform::deleteCourse(Courses course){
    //??????? wie mach ich das wenn ich meine course in ner funktion erstelle und direkt ins array Packe
}
void Platform::registerUser(User* user){
    registeredUsers.push_back(user);
    return;
}


void User::joinPlatform(Platform *platform){
    joinedPLatforms.push_back(platform);
    return;
}
void User::leavePlatform(Platform *platform){
    std::remove(joinedPLatforms.begin(), joinedPLatforms.end(), platform);
    return;
}
void User::enroll(Courses *course){
    enrolledIn.push_back(course);
    return;
}
void User::leaveCourse(Courses *course){
    std::remove(enrolledIn.begin(), enrolledIn.end(), course);
    return;
}


void Courses::createLesson(std::string title){

}
void Courses::deleteLesson(std::string title){

}
std::string Courses::getTitle() const{
    return title;
}
void Courses::setTitel(std::string title){
    this->title=title;
    return;
}
std::string Courses::getDescription() const{
    return description;
}
void Courses::setDescription(std::string text){
    this->description=description;
}



void Lesson::setTitle(std::string title){

}
std::string Lesson::getTitle()const{

}
Content Lesson::createContent(std::string type, std::string title){

}
void Lesson::deleteContent(Content content){

}


std::string Content::getTitle() const{

}
void Content::setTitle(std::string title){

}
void Content::displayContent(){

}