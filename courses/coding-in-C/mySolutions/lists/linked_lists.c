#include <stdio.h>
#include <stdlib.h>

struct ListElement {
    int key;

    struct ListElement *p_next;
};

struct list{
    struct ListElement *first;
};

void add_Element(struct ListElement *newElement, struct list *list){
    struct ListElement *temp;
    temp=list->first;

    while(temp->p_next != NULL){ // ende der liste gesucht
        temp=temp->p_next; 
    }

    temp->p_next= newElement; // am ende eingefügt
}

void delElement(struct ListElement *deletetElement, struct list *list){
    struct ListElement *temp;
    struct ListElement *del; // hilspointer um zeiger zu verschieben 
    temp= list->first;

    if(temp== deletetElement){
        list->first= temp->p_next;
        free(temp);
        return;
    }

    while(temp != NULL){ // durch iterieren bis ende der Liste erreicht
        
        if(temp->p_next==deletetElement){
            del=temp->p_next; //hilfspointer zeigt auf zulöschende Element
            temp->p_next= del->p_next; // der pointer der vorher auf das zulöschende Element zeigte soll jetzt auf den nach dem zulöschenden zeigen
            free(del);
        }

        temp=temp->p_next;
    }
}

void printList(struct list *list){

    struct ListElement *temp = list->first;

    while(temp != NULL){
        printf("%d\n", temp->key);

        temp= temp->p_next;
    }

    printf("----------\n");
    return;
}

int main(){

    struct list myList;
    struct ListElement *Elm1 = (struct ListElement*)malloc(sizeof(*Elm1));
    Elm1->key=1;
    struct ListElement *Elm2= (struct ListElement*)malloc(sizeof(*Elm2)); 
    Elm2->key=2;
    struct ListElement *Elm3 = (struct ListElement*) malloc(sizeof(*Elm3));
    Elm3->key=3;

    myList.first= Elm1;

    printList(&myList);

    add_Element(Elm2, &myList);
    add_Element(Elm3, &myList);

    printList(&myList);

    delElement(Elm2, &myList);

    printList(&myList);

    return 0;


}