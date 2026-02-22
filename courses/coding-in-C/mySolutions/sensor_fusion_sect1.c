#include <stdio.h>
#include <string.h>

int main(){

    FILE *datei= fopen("file.txt","r");
    char character;
    char line[100];

    if(datei==NULL){
        printf("problematic text file");
        return 1;
    }

   //muss gelesene zeichen zwischenspeichern sonst jedes zweite zeichen nur ausgegeben -> fgetc springt bei jedem zeichen weiter
    while((character=fgetc(datei))!=EOF){
    
        printf("%c", character);
   
    }

    printf("\n");
    rewind(datei);
    
    // no additional saving needed -> automatically written in array befor jump into next collumn
    while(fgets(line, 20, datei)!=NULL){
        printf("%s", line);
    }

    //sets pointer to beginning of text file 
    rewind(datei);


    if(fclose(datei)!=0){
        printf("ERROR");
    }


    datei= fopen("file.txt", "w+");

    char new_txt[10]="star";

    for(int i=0; i<(strlen(new_txt)); i++){
    fputc(*(new_txt+i), datei);

    }

    while(fgets(line, 20, datei)!=NULL){
        printf("%s", line);
    }

    if(fclose(datei)!=0){
        printf("Error with writing");
    }
    return 0;
}
