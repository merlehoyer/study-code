#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insert_sort(int *array, int size);
void selection_sort(int *array, int size);
void bubble_sort(int *array, int size);

int main(){

    srand(time(NULL));

    int to_sort_list[10]={0};
    int array_size = 10;

    for(int i= 0; i<10; i++){
        to_sort_list[i]= (rand()%10);
        printf("%d\t", to_sort_list[i]);
    }
    printf("\n");

    //insert_sort(to_sort_list, array_size);
    //selection_sort(to_sort_list, array_size);
    bubble_sort(to_sort_list, array_size);

    for(int j=0; j<array_size; j++){
        printf("%d\t", to_sort_list[j]);
    }

    return 0;
}

void insert_sort(int *array, int size){

    for(int j= 1; j<=size; j++){
        
        int temp= array[j];

        int i = j -1;

        while(i>=0 && array[i]>temp){
            array[i+1]= array[i];
            array[i] = temp;

            i--;
        }
        
    }

    return;
}

void selection_sort(int *array, int size){

    for(int i=0; i<size; i++){
        int min = i;

        
        for(int k= i+1; k < size; k++){
            if(array[min]> array[k]){
                min = k;
            }
        }
        int temp= array[min];
        array[min]= array[i];
        array[i]= temp;
        
    }

    return;
}

void bubble_sort(int *array, int size){

    for(int i = size; i>=0; i--){
        
        for(int j= 0; j<i; j++){
           
            if(array[j]>array[j+1]){
                int temp= array[j];
                array[j]= array[j+1];
                array[j+1]= temp;
            }
        }
    }

    return;
}