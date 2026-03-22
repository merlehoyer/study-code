#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Kontakt{

    char name[100];
    //int *tel_num;

    struct Kontakt *p_next; 

}Kontakt;


typedef struct Kontaktbuch {

    Kontakt *p_head;
    Kontakt *p_tail;

}Kontaktbuch;

Kontaktbuch *createKontaktbuch();

int addKontakt(Kontaktbuch *cur_kontaktbuch);
int deleteKontakt(Kontaktbuch *cur_kontaktbuch);

int syncKontacts(Kontaktbuch *cur_kontaktbuch, char *file);
int printKontacts(Kontaktbuch *cur_kontaktbuch, char *file);

int main(){

    Kontaktbuch *p_myKontaktbuch;

    p_myKontaktbuch= createKontaktbuch();
    if(p_myKontaktbuch==NULL){
        return -1;
    }
        
    if(addKontakt(p_myKontaktbuch)!=0){
        return -1;
    }
    if(deleteKontakt(p_myKontaktbuch)!=0){
        return -1;
    }

    if(syncKontacts(p_myKontaktbuch, "names.txt")!=0){
        return -1;
    }
    
    if(printKontacts(p_myKontaktbuch, "newnames.txt")!=0){
        return -1;
    }
    
    if(deleteKontakt(p_myKontaktbuch)!=0){
        return -1;
    }
    if(printKontacts(p_myKontaktbuch, "newnames.txt")!=0){
        return -1;
    }
    
    Kontakt *temp ;
    while(p_myKontaktbuch->p_head!=NULL){
        
        temp= p_myKontaktbuch->p_head;
        p_myKontaktbuch->p_head= temp->p_next;
        free(temp);
    
    }
    free(p_myKontaktbuch);

    return 0;
}

Kontaktbuch *createKontaktbuch(){

    Kontaktbuch *new_kontakbuch = malloc(sizeof(*new_kontakbuch));

    new_kontakbuch->p_head=NULL;
    new_kontakbuch->p_tail=NULL;


    return new_kontakbuch;
}

int addKontakt(Kontaktbuch *cur_kontaktbuch){

    Kontakt *new_kontakt = malloc(sizeof(*new_kontakt));
    if(new_kontakt==NULL){
        return -1;
    }

    //new_kontakt->name= calloc(100, sizeof(*new_kontakt->name));

    if(new_kontakt->name==NULL){
        return -1;
    }

    printf("Enter new Kontakts name: \n");
    if(fgets(new_kontakt->name, 100, stdin)==NULL){
        printf("EROR\n");
        return -1;
    }

    Kontakt *temp= cur_kontaktbuch->p_head;

    cur_kontaktbuch->p_head= new_kontakt;
    new_kontakt->p_next=temp;

    if(cur_kontaktbuch->p_tail==NULL){
        cur_kontaktbuch->p_tail= new_kontakt;
    }

    return 0;
}
int deleteKontakt(Kontaktbuch *cur_kontaktbuch){

    Kontakt *temp;
    Kontakt *temp_del;

    if(cur_kontaktbuch->p_head==NULL){
        printf("Playlist alredy empty\n");
    }else{

        printf("ENter Kontaks name to delte: ");

        char name_delet[100];

        if(fgets(name_delet, 100, stdin)==NULL){
            return -1;
        }

        temp= cur_kontaktbuch->p_head;
        
        if(strcmp(name_delet, cur_kontaktbuch->p_head->name)==0){
            temp_del= cur_kontaktbuch->p_head;
            cur_kontaktbuch->p_head= temp_del->p_next;
            free(temp_del);

            return 0;
        }
       
        while(strcmp(name_delet, temp->p_next->name)!=0){
            
            temp=temp->p_next;
            if(temp->p_next==NULL){
                printf("no name found\n");
                return -1;
            }
        }

        temp_del= temp->p_next;
        if(cur_kontaktbuch->p_tail==temp_del){
            cur_kontaktbuch->p_tail= temp;
        }
        
        temp->p_next= temp_del->p_next;

        free(temp_del);
        

    }

    return 0; 
}

int syncKontacts(Kontaktbuch *cur_kontaktbuch, char *file){

    FILE *p_file = fopen( file, "r");
    if(p_file==NULL){
        return -1;
    }
    char new_name[100];
    //printf("%s", fgets(new_name, 100, p_file));
   
    while(fgets(new_name, 100, p_file)!=NULL){
        //printf("%s", new_name);
        Kontakt *new_kontakt = malloc(sizeof(*new_kontakt));
        if(new_kontakt==NULL){
            return -1;
        }
        //new_kontakt->name= calloc(100, sizeof(*new_kontakt->name));
        if(new_kontakt->name ==NULL){
            return -1;
        }
        strcpy(new_kontakt->name, new_name);

        Kontakt *temp= cur_kontaktbuch->p_head;
        
        cur_kontaktbuch->p_head= new_kontakt;
        new_kontakt->p_next=temp;

        if(cur_kontaktbuch->p_tail==NULL){
            cur_kontaktbuch->p_tail= new_kontakt;
        }
    }

    fclose(p_file);

    return 0;
}
int printKontacts(Kontaktbuch *cur_kontaktbuch, char *file){

    FILE *p_file = fopen( file, "w");
    if(p_file==NULL){
        return -1;
    }
    char name[100];
    
    Kontakt *temp= cur_kontaktbuch->p_head;
    while(temp!=NULL){
        printf("%s", temp->name);
        //strcpy(name, temp->name);
       
        if(fputs(temp->name , p_file)==0){
            return-1;
        }
        temp = temp->p_next;
    }
    printf("-----------\n");


    fclose(p_file);
    return 0;
}
