#ifndef REPORT_CARD_H
#define REPORT_CARD_H

void readStudentData(std::string &name,
                     int16_t &homework,
                     int16_t &midterm,
                     int16_t &finalExam);


void calculateGrade(int16_t &homework,
                    int16_t &midterm,
                    int16_t &finalExam,
                    float &finalGrade,
                    std::string &letterGrade);

void determinLetterGrade(float &finalGrade, std::string &letterGrade);

void printReport(std::string name,
                 int16_t &homework,
                 int16_t &midterm,
                 int16_t &finalExam,
                 float &finalGrade,
                 std::string &letterGrade);


#endif /*REPORT_CARD_H*/