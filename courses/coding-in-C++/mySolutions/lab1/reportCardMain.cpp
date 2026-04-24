#include <iostream>
#include <string>
#include <cstdint>
#include <iomanip>
#include "reportCard.hpp"

int main(){

    std::string name = " ";
    int16_t homework=0;
    int16_t midterm=0;
    int16_t finalExam =0;
    float finalGrade =0.0;
    std::string letterGrade=" ";

    readStudentData(name,homework,midterm,finalExam);
    calculateGrade(homework,midterm,finalExam,finalGrade,letterGrade);
    printReport(name,homework,midterm,finalExam,finalGrade,letterGrade);

    return 0;
}

