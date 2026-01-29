#include <stdio.h>

int main(){

    int row[10] = {8,7,6,5,4,3,2,1};
    char column[10]= {"ABCDEFGH"};

    for (int i=0; i<8; i ++){
        for (int j=0; j<8; j++){
            
            printf("%c",column[j]);
            printf("%d ",row[i]);
            
        }
        
            printf("\n");
    }



    return 0;
}