#ifndef LERNPLATFORM_HPP
#define LERNPLATFORM_HPP
#include <string>

class Platform{
    private:
        // als Object richtig
        std::vector<Courses> Course; //max 100 
        // Mitgabe als referenz
        std::vector<User*>registeredUsers; // Pointer müssen hinter typen!
    public:
        void createCourse(std::string titel, std::string description);
        void deleteCourse(Courses course);
        void registerUser(User* user);
};

class User{
    private:
        const std::string name;
        std::string address;
        std::vector<Courses*> enrolledIn;
        std::vector<Platform*> joinedPLatforms;
    public:
        void joinPlatform(Platform *platform);
        void leavePlatform(Platform *platform);
        void enroll(Courses *course);
        void leaveCourse(Courses *course);
};

class Courses{
    private:
        std::string title;
        std::string description;
        std::vector<User*>participants;
        std::vector<Lesson>courseParts;
    public:
    void createLesson(std::string title);
    void deleteLesson(std::string title);
    std::string getTitle() const;
    void setTitel(std::string title);
    std::string getDescription() const;
    void setDescription(std::string text);
    Courses(std::string title, std::string description): title(title), description(description){}
};

class Lesson{
    private:
        std::string title;
        std::vector<Content*> contents;
    public:
        void setTitle(std::string title);
        std::string getTitle()const;
        Content createContent(std::string type, std::string title);
        void deleteContent(Content content);
};

class Content{
    private:
        std::string type;
        std::string title;
    public:
        std::string getTitle() const;
        void setTitle(std::string title);
        void displayContent();
};

#endif