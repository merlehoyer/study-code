#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    Node *p_next;
} Node;

Node *creating_new_node(double var){

    //in main checking nach NULL pointer!!!
   
    Node *new_node = malloc (sizeof(*new_node));

    new_node->value= var;

    return new_node;
}

void adding_notes_to_list_end(Node *head, Node* new_node){
    Node *temp=head; 

    if(head==NULL){

        head= new_node;

        return;
    }

    while(temp!=NULL){

        if(temp->p_next==NULL){
            temp->p_next= new_node;
        }

        temp= temp->p_next;
    }

    free(temp);
    
    return;
}

void adding_notes_to_list_start(Node *head, Node *new_node){


    new_node->p_next=head;
    head = new_node;

    return;
}

void freeing_memory(Node *head){
    Node *tmp = head;
    Node *tmp2 =head;

    while(tmp!=NULL){
        
        tmp2=tmp;
        tmp=tmp->p_next;

        free(tmp2);

    }

    head=tmp;

    free(tmp);



    return;
}

int main(){

    Node *head =NULL;

    
    free(head);

    return 0;
}