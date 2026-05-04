#ifndef HEADERTEMPALTES_HPP
#define HEADERTEMPLATES_HPP

#include <iostream>
#include <string>


template <typename T>
void swapping_param(T &param1, T &param2){

    T temp = param1;
    param1= param2;
    param2= temp;

    return;
}

template<typename U, int N>
void printing_sensor_frames(U (&arr)[N]){
    for(int i=0; i<N; i++){
        std::cout<<arr[i]<<", ";
    }

    return;
}

template <typename T, int N>
T smallest_measurement(T (&arr)[N]){

    T minValue = arr[0];

    for(int i=0; i<N;i++){
        if(minValue>arr[i]){
            minValue=arr[i];
        }
    }

    return minValue;
}

template <typename T, typename U>
void tag_composer(std::string label1, T value1, std::string label2, U value2){

    std::cout<<label1<<": "<< value1<<" | "<<label2<< ": "<<value2<<std::endl;

    return;
}

#endif