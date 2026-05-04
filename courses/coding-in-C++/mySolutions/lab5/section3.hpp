#ifndef SECTION3_HPP
#define SECTION3_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <array>
#include <iterator>


#define CUT_OF_VALUE_TRUE_FALSE 0.5

template <typename T>
void analysis_values(std::vector<T> data, T &largest, T &sum, T &average){

    sum= std::accumulate(data.begin(), data.end(), T());

    largest= *(std::max_element(data.begin(), data.end()));

    average= sum/ data.size();

    return;
}

template <typename T>
void determing_average_and_sum(std::vector<T> data,T &average, T &sum){
    
    sum= std::accumulate(data.begin(), data.end(), T());
    average= sum/ data.size();
    return;
}

template<>
void determing_average_and_sum<bool>(std::vector<bool> data, bool &average, bool &sum){

    int counter =0;

    for( bool x : data){
        if(x==true){
            counter++;
        }
    }

    std::cout<<counter<<std::endl;

    double determin_value= static_cast<double> (counter) / data.size();

    if(determin_value>CUT_OF_VALUE_TRUE_FALSE){
        average= true ;
    }
    else {
        average= false;
    }
    

    return;
}

template <typename T>
void printing_values(T largest,T sum, T average){

    std::cout<<"----------- Analysis Data -----------"<<std::endl;
    std::cout<<std::left<<std::setw(20)<<"largest Element:"<<largest<<std::endl;
    std::cout<<std::setw(20)<<"Sum of all Elements:"<<sum<<std::endl;
    std::cout<<std::setw(20)<<"Averge:"<<average<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl<<std::endl;

    return;
}

template <>
void printing_values<bool>(bool largest,bool sum, bool average){

    std::cout<<"----------- Analysis Data -----------"<<std::endl;
    std::cout<<std::left<<std::setw(20)<<"largest Element:"<<largest<<std::endl;
    std::cout<<std::setw(20)<<"Sum of all Elements:"<<sum<<std::endl;
    std::cout<<std::setw(20)<<"Averge:"<<average<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl<<std::endl;

    return;
}

template <typename T> //darf nicht mehr haben als benutzt wird!!!!
void array_to_vector(std::vector<T> &vector ,std::array<T ,8> &array){
    
    std::copy(array.begin(), array.end(), std::back_inserter(vector) );

    return;
}
//sollen wir std::size_t benutzen?







#endif /*SECTION3_HPP*/