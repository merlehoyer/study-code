#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    double value;
    struct Node *p_next;
} Node;

Node *creating_new_node(double var){

    //in main checking nach NULL pointer!!!
   
    Node *new_node = malloc (sizeof(*new_node));

    new_node->value= var;
    new_node->p_next=NULL;

    return new_node;
}

// hier wichtig: kein free() von pointern da sonst element gelöscht wird 
// *head nur kopie von zeiger -> keine wirkliche veränderung -> bei new_node anders: kopierte Addrese wird in Liste eingehängt == keine Veränderung des kopierten Wertes

void adding_notes_to_list_end(Node **head, Node* new_node){
    Node *temp=*head; //bekommt adresse von head

    if(*head==NULL){

        *head= new_node;

        return;
    }

    while(temp!=NULL){

        if(temp->p_next==NULL){
            temp->p_next= new_node; // der pointer des elements auf das die kopie zeigt(nicht die kopie selber) bekommt adresse von new_node
            return;
        }

        temp= temp->p_next;
    }
    
    return;
}

void adding_notes_to_list_start(Node **head, Node *new_node){
    //double pointer auf head sodass eigentliche wert vom pointer geändert wird -> speicheradresse von head mitgegeben + mit einfacher refferenzierung wird wert worauf head zeigt verändert

    new_node->p_next=*head;
    *head = new_node;

    return;
}

void freeing_memory(Node *head){
    Node *tmp = head;
    Node *tmp2;

    while(tmp!=NULL){
        
        tmp2=tmp->p_next;
        free(tmp);

        tmp=tmp2;

    }

    return;
}

void print_list(Node *head){
    Node *temp=head;

    if(head==NULL){
        printf("List empty\n--------------\n");

        return;
    }

    while(temp!=NULL){
        
        printf("%lf ", temp->value);

        temp=temp->p_next;
    }

    printf("\n-----------\n");

    return;
}

void adding_nodes_determinde_space(int place, Node **head, Node *new_node){
    Node *temp = *head; //adresse von head

    if(place ==1){
        new_node->p_next= *head;
        *head=new_node;
        return;
    }
    
    for( int i =0; i<(place-2); i++){
    
        temp= temp->p_next;
    }

    new_node->p_next = temp->p_next;
    temp->p_next= new_node;

    return;
}

int main(){

    Node *head =NULL;

    srand(time(NULL));
    
    for(int i=0; i<50; i++){
      
        Node *node= creating_new_node(rand()%300);  
        printf("%lf\n", node->value);

        if(node==NULL){
            printf("Error withh creating node\n");
            return -1;
        }

        adding_notes_to_list_end(&head, node);
        
    } 

    Node *node1 = creating_new_node(1);
    //Node *node2 = creating_new_node(2);

    

    //head= node1;

    //adding_notes_to_list_start(head, node1);
    //adding_notes_to_list_end(head, node2);

    //printf("%lf", head->value);
    //printf("%d", head->p_next->value);

    adding_nodes_determinde_space(1, &head, node1);

    print_list(head);
    

    


    freeing_memory(head);
    
    return 0;
}


// wichtig ist :
// auf passen bei speicherfreigabe -> wirklich nur benötigt wenn ich elemente löschen möchte -> temporäre pointer dürfen/ müssen nicht freigegeben werden 