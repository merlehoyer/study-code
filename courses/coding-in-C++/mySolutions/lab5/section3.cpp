#include "section3.hpp"
#include <iostream>
#include <vector>
#include <array>

int main(){

    std::vector<int> i_vector= {1,2,3,4,5,6,7,8,9};
    std::vector<double> d_vector={0.1,0.2,0.3,0.4,0.5};

    int int_largest=0;
    int int_average=0;
    int int_sum =0;

    double d_largest=0;
    double d_average=0;
    double d_sum =0;

    analysis_values(i_vector, int_largest, int_sum, int_average );
    analysis_values(d_vector, d_largest, d_sum, d_average);

    printing_values(int_largest, int_sum, int_average );
    printing_values(d_largest, d_sum, d_average);

    std::array<int,8> record_samples ={42,17,42,5,99,17,63,12};

    
    std::vector<int> dataset = {}; 
    array_to_vector(dataset,record_samples);

    for(int x : dataset){
        std::cout << x << " ";
    }

    std::array<bool,8> true_array ={false,true,true,true,true,true,false,true};
    bool true_average= false;
    bool true_sum = false;

    std::vector<bool> true_vector;

    array_to_vector(true_vector,true_array);

    determing_average_and_sum(true_vector,true_average, true_sum);
    //std::cout<<"hello im here";

    printing_values(true_average, true_sum, true_average);

    return 0;
} 