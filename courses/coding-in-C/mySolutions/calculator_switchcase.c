#include <stdio.h>

float addition(float summand1, float summand2){

    float answer= summand1+summand2;
    
    return answer;
}

void subtract(float sub1, float sub2){
    float answer= sub1 - sub2;
    printf("%.2f-%.2f=%.2f\n",sub1, sub2, answer);
    return;
}

void divide(float divid1, float divid2){
    if(divid2==0){
        printf("critical error");
    } else{
        float answer= divid1/divid2;
        printf("%.2f/%.2f= %.2f \n", divid1, divid2, answer);
    }
    return;
}

void multiply(float multi1, float multi2){
    float answer= multi1*multi2;
    printf("%.2f x %.2f = %.2f \n", multi1, multi2, answer);
}

int main(){

    char iChoiceOperant;
    float fNumber1;
    float fNumber2;
    
    printf("--Calculator--\n");
    printf("Number 1: ");
    scanf("%f", &fNumber1);
    printf("%.2f\n", fNumber1);

    printf("Number 2: ");
    scanf("%f", &fNumber2);
    printf("%.2f\n",fNumber2);

    printf("choose your operant\n");
    printf(" 1. (+) | 2. (-) | 3. (x) | 4. (/) \n "); 

    scanf("%s", &iChoiceOperant);
    //int size = sizeof(iChoiceOperant);
   // printf("%d", size);

    printf("\n ");
        
    
    switch(iChoiceOperant){
        case'+':
            printf("%.2f + %.2f = %.2f\n",fNumber1, fNumber2, addition(fNumber1, fNumber2));
            break;
        case '-':
            subtract(fNumber1, fNumber2);
            break;
        case '/':
            divide(fNumber1, fNumber2);
            break;
        case 'x':
            multiply(fNumber1, fNumber2);
            break;

        default:
        
        printf("invalid choice of operant");
    }
        






    return 0;
}