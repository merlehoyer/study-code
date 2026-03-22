#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


void copy_first_line(char *p_name, char *p_new_name){

    FILE *pFile = fopen(("%s",p_name), "r");

    assert(pFile!=NULL);
    char string[100];
    assert(fgets(string, sizeof(string), pFile)>=0);

    fclose(pFile);
        
    FILE *pFile2 = fopen(("%s", p_new_name), "a");

    assert(pFile2!=NULL);

    assert(fputs(string, pFile2)>=0);

    fclose(pFile2);

    return;
}


int main(){

    FILE *pFile = fopen("text.txt","a");

   char p_first_sentence[100];
   
    fputs("hellooo !\n", pFile);
    fputs("and not this\n", pFile);

    fclose(pFile);

    copy_first_line("text.txt", "text_new.txt" );

    FILE *p_file = fopen("text_new.txt", "r");
    
    
    fgets(p_first_sentence, sizeof(p_first_sentence), p_file);

    fclose(p_file);

    assert(strcmp(p_first_sentence, "hellooo !\n")==0);
    printf("%d", strcmp(p_first_sentence, "hellooo !\n"));

    return 0;
}