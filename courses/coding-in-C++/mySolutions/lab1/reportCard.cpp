#include <iostream>
#include <string>
#include <cstdint>
#include <iomanip>
#include <limits>
#include "reportCard.hpp"

void readStudentData(std::string &name,
                     int16_t &homework,
                     int16_t &midterm,
                     int16_t &finalExam){

    const int8_t LOWER_LIMIT_GRADE = 0;
    const int8_t UPPER_LIMIT_GRADE = 100;

    std::cout <<"Enter student name:" ;
    std::getline(std::cin, name);

    std::cout <<"Homework score: ";
    while(!(std::cin >> homework) || homework<LOWER_LIMIT_GRADE|| homework>UPPER_LIMIT_GRADE){
        std::cout << "Error not a valid number, please enter it again"<<std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout <<"Midterm score: ";
    while(!(std::cin >> midterm) || midterm<LOWER_LIMIT_GRADE|| midterm>UPPER_LIMIT_GRADE){
        std::cout << "Error not a valid number, please enter it again"<<std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout <<"Final exam score: ";
    while(!(std::cin >> finalExam) || finalExam<LOWER_LIMIT_GRADE|| finalExam>UPPER_LIMIT_GRADE){
        std::cout << "Error not a valid number, please enter it again"<<std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return;

}


void calculateGrade(int16_t &homework,
                    int16_t &midterm,
                    int16_t &finalExam,
                    float &finalGrade,
                    std::string &letterGrade){
    
    finalGrade= 0.4*(static_cast<float>(homework))+ 0.25*(static_cast<float>(midterm))+ 0.35*(static_cast<float>(finalExam));
    determinLetterGrade(finalGrade,letterGrade);

    return;
}

void determinLetterGrade(float &finalGrade, std::string &letterGrade){

    if(finalGrade>= 90){
        letterGrade="A";
    } else if( finalGrade >=80){
        letterGrade="B";
    }else if( finalGrade >=70){
        letterGrade="C";
    }else if( finalGrade >=60){
        letterGrade="D";
    }else if( finalGrade >=50){
        letterGrade="E";
    }else {
        letterGrade="F";
    }

    return;
}

void printReport(std::string name,
                 int16_t &homework,
                 int16_t &midterm,
                 int16_t &finalExam,
                 float &finalGrade,
                 std::string &letterGrade)
{
    std::string status= " ";
    //calculating pass or not
    if(letterGrade=="A"|| letterGrade== "B"|| letterGrade=="C"){
        status="PASS";
    }else if(letterGrade=="D"||letterGrade=="E"){
        status = "CONDITIONAL PASS";
    } else{
        status="FAIL";
    }




    std::cout<< "------------------"<<std::endl;
    std::cout<< "Student Report"<<std::endl;
    std::cout<< "------------------"<<std::endl;

    std::cout << "Name: "<< name << std::endl <<std::endl;
    std::cout <<"scores"<<std::endl;
    std::cout<< "------------------"<<std::endl;

    std::setprecision(2);

    std::cout << std::left << std::setw(15) <<"Homework"; 
    std::cout << std::right <<": " <<homework<< std::endl;
    std::cout << std::left << std::setw(15) <<"Midterm" ;
    std::cout << std::right<<": " <<midterm<< std::endl;
    std::cout << std::left << std::setw(15) <<"Final Exam" << std::right <<": "<<finalExam<< std::endl<<std::endl;

    std::cout << std::left << std::setw(15)  <<"Final Grade" << std::right <<": "<<finalGrade<< std::endl;
    std::cout << std::left << std::setw(15) <<"Letter Grade" << std::right <<": " <<letterGrade<< std::endl;
    std::cout << std::left << std::setw(15)<<"Status"<<std::right <<": "<<status<<std::endl;
    std::cout<< "------------------"<<std::endl;


    return;
}