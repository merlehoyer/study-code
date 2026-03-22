#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGHT 100
#define MAX_TELNUM_LENGHT 50
#include <assert.h>

typedef struct Contact{
    char name[MAX_NAME_LENGHT];
    char* p_tel_num;
    struct Contact *p_next;
}Contact;

typedef struct{
    Contact *p_head;
    Contact *p_tail;
} ContactBook;

ContactBook *initiialise_COntact_book(){
    ContactBook *new_contact_book = malloc(sizeof(*new_contact_book));
    new_contact_book->p_head=NULL;
    new_contact_book->p_tail=NULL;

    return new_contact_book;
}

Contact *create_new_contact(char *p_name, char *p_tel_num){
    
    Contact *new_contact = malloc(sizeof(*new_contact));

    if(strcpy(new_contact->name, p_name)==NULL){
        return NULL;
    }

    int i_length_telnum = strlen(p_tel_num);
    //printf("%d", i_length_telnum);

    new_contact->p_tel_num= malloc(i_length_telnum* sizeof(*new_contact->p_tel_num));

    strcpy(new_contact->p_tel_num, p_tel_num);

    new_contact->p_next=NULL;

    return new_contact;
}

void add_contact(Contact *my_contact, ContactBook *my_Book){
    if(my_Book->p_head==NULL && my_Book->p_tail==NULL){
        my_Book->p_head= my_contact;
        my_Book->p_tail= my_contact;
    }else{
        my_Book->p_tail->p_next= my_contact;
        my_Book->p_tail= my_contact;
    }

    return;
}

int delete_contact(ContactBook *p_my_Book){

    //in main check for 0 /1 or -1 
    
    printf("enter name to delete: ");
    char name_del[MAX_NAME_LENGHT];

    if(fgets(name_del, MAX_NAME_LENGHT, stdin)==NULL){
        return -1;
    }
    
    name_del[strcspn(name_del, "\n")]='\0';

    Contact *temp = p_my_Book->p_head;

    if(strcmp(name_del, temp->name)==0){
        p_my_Book->p_head= temp->p_next;
        free(temp->p_tel_num);
        free(temp);
        return 0;
    }

    while(temp->p_next!=NULL && strcmp(name_del, temp->p_next->name)!=0){
        temp= temp->p_next;
    }
    if(temp->p_next==NULL){
        printf("no entry found\n");
        return 1;
    }else{
        Contact *p_del_temp = temp->p_next;
        temp->p_next= p_del_temp->p_next;
        free(p_del_temp->p_tel_num);
        free(p_del_temp);
    }

    return 0; 
}

int sync_contact_book(ContactBook *p_myBook, char *p_fileName){
    FILE *p_file = fopen(p_fileName, "r");
    if(p_file==NULL){
        return -1;
    }

    Contact *p_temp = p_myBook->p_head;
    char name[MAX_NAME_LENGHT];
    char tel_num[MAX_TELNUM_LENGHT];

    while(fscanf(p_file, "%s %s", name, tel_num)==2){
        name[strcspn(name, "\n")]= '\0';
        Contact *new_contact = create_new_contact(name, tel_num);
        add_contact(new_contact, p_myBook);
        
    }

    fclose(p_file);

    return 0;
}

int print_contact_book(ContactBook *p_myBook, char *p_fileName){
    
    FILE *p_file = fopen(p_fileName,"w");
    if(p_file==NULL){
        return -1;
    }

    Contact *p_temp = p_myBook->p_head;

    while(p_temp!=NULL){
        printf("%s\n", p_temp->name);
        if(fputs(p_temp->name, p_file)==EOF){
            return-1;
        }

        if(fputc(' ', p_file)==EOF){
            return -1;
        }

        printf("%s\n", p_temp->p_tel_num);
        if(fputs(p_temp->p_tel_num, p_file)==EOF){
            return-1;
        }

        if(fputc('\n', p_file)==EOF){
            return -1;
        }

        p_temp= p_temp->p_next;
    }

    printf("------------\n");

    fclose(p_file);

    return 0;
}


int main(){

    ContactBook *myBook = initiialise_COntact_book();
    
    if(sync_contact_book(myBook, "names.txt")!=0){
        return -1;
    }
    char new_name[MAX_NAME_LENGHT];
    char new_telnum[MAX_TELNUM_LENGHT];

    printf("Enter new Contacts name: ");
    if(fgets(new_name, MAX_NAME_LENGHT, stdin)==NULL){
        return -1;
    }
    printf("Enter new Contacs telnum: ");
    if(fgets(new_telnum, MAX_TELNUM_LENGHT, stdin)==NULL){
        return -1;
    }
    new_name[strcspn(new_name, "\n")]= '\0';
    new_telnum[strcspn(new_telnum, "\n")]= '\0';
    Contact *new_contact = create_new_contact(new_name, new_telnum);
    add_contact(new_contact, myBook);

    

    if(print_contact_book(myBook, "newnames.txt")!=0){
        return -1;
    }

    int i_check = 1;
    while(i_check ==1){
        i_check = delete_contact(myBook);
       
    }
     
    if(i_check==-1){
        return -1;
    }

    if(print_contact_book(myBook, "newnames.txt")!=0){
        return -1;
    }

    


    //delete contact book
    
    while(myBook->p_head!=NULL){
        if(myBook->p_head== myBook->p_tail){
            myBook->p_tail=NULL;
        }
        Contact *p_temp = myBook->p_head;
        myBook->p_head= p_temp->p_next;
        free(p_temp->p_tel_num); 
        free(p_temp);
    }
    free(myBook);

    return 0;
}

// queue as contact book with names 