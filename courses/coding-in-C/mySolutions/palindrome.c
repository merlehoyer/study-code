#include <stdio.h>
#include <string.h>

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

    printf("chosen word (only lowercase): ");
    fgets(a_word, sizeof(a_word), stdin);

    i_word_length = strcspn(a_word, "\n");
    a_word[i_word_length]='\0';

    
    for(int j=0; j<= i_word_length; j++){
        printf("%c",a_word[j]);
    }

    // checking for palindrome
    for(int k=0; k<= i_word_length; k++){
        *(pcomp_word+k)=*(pword+(i_word_length-k));
    }
    printf("\n");
    a_compare_word[i_word_length]='\0';

    printf("%d ", i_word_length);

    for(int l=0; l<= i_word_length; l++){
        printf("%c",a_compare_word[l]);
    }
    printf("\n");

    if(strcmp(a_word, a_compare_word)==1){
        printf("youre word is a palindrome");
    } else{
        printf("youre word is not a palindrom");
    }







    return 0;
}