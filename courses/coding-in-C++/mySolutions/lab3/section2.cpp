#include <iostream>
#include <string>

class User{
    protected: //so that child classes can use the parameters
        std::string name;
        int id;

    public:
        User(std::string name, int id): name(name), id(id){};
        void printInfo(){
            std::cout<<"Name: "<<name <<"id: "<<id<< std::endl;
        }
};

class Student : public User{
    private:
        double average;
    public:
        void printRole(){
             std::cout<<"Name: "<<name <<"id: "<<id<< "average: "<<average<<std::endl;
             return;
        }
        Student(double average, std::string name, int id): average(average), User(name, id){}
};

class Instructor: public User{
    private:
        int number_of_classes_taught;
    public:
        void printRole()const{
            std::cout<<"Name: "<<name <<"id: "<<id<<"Number classes taught: "<<number_of_classes_taught <<std::endl;
            return;
        }

        Instructor(int number_classes , std::string name, int id)
        :number_of_classes_taught(number_classes), User(name, id){}
    
};

int main(){

    Student student1(1.3,"emma", 34548734);
    Instructor Instructor1( 5 , "andera", 63850);

    student1.printInfo();
    Instructor1.printInfo();

    student1.printRole();
    Instructor1.printRole();
    
    return 0;
}