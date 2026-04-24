#include <iostream>
#include <cstdint>
#include <limits>
//#define CUT_OF_AGE_ADULT 18
//#define CUT_OF_AGE_SENIOR 65

namespace validation{

bool isAdult(int16_t &age){

    const int8_t CUT_OF_AGE_ADULT =18;

    if(age < CUT_OF_AGE_ADULT){
        
        std::cout << "That means you are still a kid or an teenager."<<std::endl;
       
        return false;

    }else{
        return true;
    }


}

bool isSenior(int16_t &age){

    const int8_t CUT_OF_AGE_SENIOR = 65;

    if(age<CUT_OF_AGE_SENIOR){
        
        std::cout<<"that means You are an adult"<<std::endl;

        return false;
    } else{

        std::cout<<"that means you ar a senior citizen"<< std::endl;

        return true;
    }

}


}

int main(){


    int16_t my_age = 0;
    std::cout << "Please enter your age: ";
    while(!(std::cin >> my_age) || my_age <= 0 || my_age> 120){
        std::cout << "Error not a valid number, please enter it again"<<std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }



    if(validation::isAdult(my_age) == true){
        validation::isSenior(my_age);
    }

    return 0;
}