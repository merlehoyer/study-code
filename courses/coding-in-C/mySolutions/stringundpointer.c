#include <stdio.h>
#include <string.h>

void string_taker(char *ptr){

    //char string[50]={};

    fgets(ptr, sizeof(ptr), stdin);
    *(ptr+(strcspn(ptr, "\n")))='\0';

    *(ptr+1)='c';

    printf("%s", ptr);


    return;
}


int main(){
    
    char string[50]="Curly bird catches worm";
    char *pstr = string;

    printf("%s\n",string);
    printf("%s\n", pstr);

    *pstr = 'E';
    *(pstr+1)= 'a' ;

    printf("%s\n", pstr);

    string_taker(pstr);








    return 0;
}