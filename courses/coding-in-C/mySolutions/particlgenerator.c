/*
* file: particlgenerator.c
* description: simulates in 1D particlcollision 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief moves particls right or left
 *
 * @param[in] ptr_field gives field array(Input)
 * @param[in] SIZE size of field
 * @return            Explanation of return value
 */

int moving_particl(int *ptr_field, int*ptr_h_field, const int SIZE){

    int moving_index=0;
    

    for(int i=0; i<SIZE; i++){
        if(*(ptr_field+i)==0){
            //nothing
        }else {
           
            moving_index= (rand()%2);
            //printf("%d\n", moving_index);

            if(moving_index==0 && i!=(SIZE-1)){ 
                //right shift of 1
                *(ptr_h_field+i)=0;
                *(ptr_h_field+i+1)=1;
            } else if(moving_index==1 && i!=0){
                // left shift
               
                *(ptr_h_field+i)=0;
                // checking collision
                if(*(ptr_h_field+i-1)==0){

                    *(ptr_h_field+i-1)=1;
                }else {
                    *(ptr_h_field+i-1)=0;
                    printf("collision on Index %d\n", (i));
                }
            }

        }
    }

    return 0;
}

int main(){
    
    srand(time(NULL));

    int field[10];
    int *p_field= field;
    
    int help_field[10]={0};
    int *p_help_field= help_field;
    
    const int FIELDSIZE=10;
    int field_value=0;
    int time_counter=0;



    for(int i=0; i<FIELDSIZE; i++){
       *(p_field+i)=0;
       printf("%d", *(p_field+i));
    }
    printf("\n");

    *(p_field+2)=1;
    *(p_field+4)=1;
    *(p_field+6)=1;

    printf("Time %d: ", time_counter);
    time_counter++;

    for(int i=0; i<FIELDSIZE; i++){

       printf("%d", *(p_field+i));
    }
    printf("\n");

    

    while(field_value!=1){
        
        moving_particl(p_field, p_help_field, FIELDSIZE);

        printf("Time %d: ", time_counter);

        for(int j =0; j<FIELDSIZE; j++){
        
            *(p_field+j)=*(p_help_field+j);

            printf("%d", *(p_field+j));
        }
        
        printf("\n");
        
        field_value=0;
        
        for(int i=0; i<FIELDSIZE; i++){
            field_value += *(p_field+i);
        }
        
         //printf("\n%d", field_value);
        time_counter++;
    }
    
  
    


    return 0;
}