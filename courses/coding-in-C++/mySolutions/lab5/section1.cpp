#include <iostream>
#include <string>
#include "headertemplates.hpp"


int main(){

    int ipar1= 10;
    int ipar2= 20;

    std::string string1 = "hello";
    std::string string2 = "world";

    int iarr[4]= {1,7,19,4};
    double darr[4]= {2.5,7.89,23.45,8.99};
    char carr[4]={'a','b','c','d'};

    std::string label1= "Channel";
    std::string label2= "Priority";

    std::string value1= "motor_temp";
    int value2= 2;

    std::cout<<"param1 before swap: "<< ipar1<<std::endl;
    std::cout<<"param2 before swap: "<< ipar2<<std::endl<<std::endl;

    swapping_param(ipar1, ipar2);

    std::cout<<"param1 after swap: "<< ipar1<<std::endl;
    std::cout<<"param2 after swap: "<< ipar2<<std::endl<<std::endl;

    std::cout<<"param1 before swap: "<< string1<<std::endl;
    std::cout<<"param2 before swap: "<< string2<<std::endl<<std::endl;

    swapping_param(string1, string2);

    std::cout<<"param1 after swap: "<< string1<<std::endl;
    std::cout<<"param2 after swap: "<< string2<<std::endl<<std::endl;

    std::cout<<"[";
    printing_sensor_frames(iarr);
    std::cout<<"]";

    std::cout<<"[";
    printing_sensor_frames(carr);
    std::cout<<"]"<<std::endl<<std::endl;

    std::cout<<smallest_measurement(iarr)<<std::endl;
    std::cout<<smallest_measurement(darr)<<std::endl<<std::endl;

    tag_composer(label1, value1, label2, value2);

    return 0;
}