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


    datei= fopen("file.txt", "a+");

    char new_txt[10]="\nstar";

    for(int i=0; i<(strlen(new_txt)); i++){
    fputc(*(new_txt+i), datei);

    }

    if(fputs(new_txt, datei)==0){
        printf("ERROR");
        return 1;
    }

   if( fprintf(datei,"hey ho")<0){
        printf("ERRORE");
        return 1;
   }

    rewind(datei);

    while(fgets(line, 20, datei)!=NULL){
        printf("%s", line);
    }

    if(fclose(datei)!=0){
        printf("Error with writing");
    }


    //FILE *text = fopen("rand_num.txt","r");
    FILE *text = fopen("sensor1.txt","r");
    float read_values[100]={0};
    float *p_rvalues= read_values;

    if(text==NULL){
        printf("Error opening senors values");
        return 0;
    }
   
   /*

    printf("%d", fscanf(text, "%d %*d %d", read_values, p_rvalues+1));

    for(int i=0; i<3; i++){
   
        //printf("hi");
       
          
        printf("%d", *(read_values+i));
        

    }

    
    */

    if(fscanf(text, "%f %f", read_values, read_values+1)==2){
        printf("%.2f\n",*(read_values+1));
    }

    if(fclose(text)!=0){
        printf("Error with closing sensor data");
    }


    return 0;
}
