#include <stdio.h>

struct car{
    float fuel_level;
    float max_fuel_level;
    char model[100];
};

void refuel(struct car *p_current_car){

   float missing_fuel=( p_current_car->max_fuel_level - p_current_car->fuel_level);
   
    if( missing_fuel>10){
        p_current_car->fuel_level+=10;
    } else if(missing_fuel>5){
        p_current_car->fuel_level+=5;
    } else if(missing_fuel>0){
        p_current_car->fuel_level+=1;
    }
    
    return;
};


int main(){

    struct car mycar;
    struct car *p_mycar;

    p_mycar = &mycar;

    mycar.fuel_level= 1;
    mycar.max_fuel_level=48;

    while ((mycar.max_fuel_level-mycar.fuel_level)>0)
    {
        refuel(p_mycar);
        printf("%.2f\n", mycar.fuel_level);
    }
    

    

    return 0;
}