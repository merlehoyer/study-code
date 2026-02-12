#include <stdio.h>
#include <string.h>
#include <ctype.h>

void checkingPalingdrome (char *ptrw, int i_length){

    char a_help_word[50];
    char *phelp_w = a_help_word;
    char a_compare_word[50];
    char *pcomp_word= a_compare_word;

    for(int i=0; i<= i_length; i++){
        *(phelp_w+i)=tolower(*(ptrw+i));
    }
    //printf("%s", phelp_w);

    for(int k=0; k<= i_length; k++){
        *(pcomp_word+k)=*(phelp_w+(i_length-(k+1))); // k+1 for exclusion \0
    }
    a_compare_word[i_length]='\0'; // for missing end of string in compare word

   // printf("%s\n", a_compare_word);
    

    if(strcmp(phelp_w, a_compare_word)==0){
        printf("%s is a palindrome", ptrw);
    } else{
        printf("%s is not a palindrome", ptrw);
    }
    
    return;
}

int main(){

    char a_word[50];
    char *pword= a_word;

    char a_compare_word[50];
    char *pcomp_word= a_compare_word;
   
    int i_word_length;
    
   /* //define word length
    printf("word length: ");
    scanf("%d \n", i_word_length);

    for(int i=0 ; i <= i_word_length; i++){
        scanf("%1c", a_word+i);
    }
    a_word[i_word_length+1]={'\0'};

    for(int j=0; j<= i_word_length; j++){
        printf("%c",a_word[j]);
    } */

    printf("chosen word: ");
    if(fgets(a_word, sizeof(a_word), stdin)!=NULL){

    

    i_word_length = strcspn(a_word, "\n");
    a_word[i_word_length]='\0';


    checkingPalingdrome(pword, i_word_length);
    }else{
        printf("ungültige Eingabe");
    }
    
    //printf("%s\n", a_word);






    return 0;
}