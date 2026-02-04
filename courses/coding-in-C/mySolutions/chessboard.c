#include <stdio.h>

int main(){

    int row[10] = {8,7,6,5,4,3,2,1};
    char column[10]= {"ABCDEFGH"};
    int il=0;
    int iboardsize= 9;


    for (int i=0; i<(iboardsize+9); i ++){
       if(i%2==0){
        
        for (int j=0; j<iboardsize; j++){
           
            if(i==0&& j==0){
                printf(" ");
            }
            else if(i==0&& j!=0){
                printf(" ");
                printf(" %c ", column[(j-1)]);
                
            } else
            {
               
             if(j!=0){
                printf("|");
        
                    
                if ((il+j)%2==0){
                    printf("###");
                } 
                else {
                    printf("   ");
                }
             }else{
                printf("%d",il);
             }
            }
            //printf("%c",column[j]);
            //printf("%d ",row[i]);*/
            
        }
            
            if(i!=0){
            printf("|");
            printf(" %d",il);
            }
            il++;

        }else
        {
        
        for(int k=0; k<(iboardsize); k++){
            if(k!=0){
            printf("+---");
            } else{
                printf(" ");
            }
        }
        printf("+");
       }
        
            printf("\n");

               
    
    }
    

 for(int m=0; m < 8; m++){
        printf(" ");
        printf(" %c ", column[(m)]);

 }
    return 0;
}