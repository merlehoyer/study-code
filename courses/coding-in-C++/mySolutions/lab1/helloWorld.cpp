#include <iostream>
#include "header.hpp"


int main(){

    std::cout<< "Hello World!" << std::endl;

    printFromHeader();

    return 0;
}

void printFromHeader(){

    std::cout<< "Hello World from .hpp" << std::endl;

    return;
}