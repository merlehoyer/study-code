#include <stdio.h>
#include <stdlib.h>

struct QueueElement{
    int var;

    struct QueueElement *next;
};

struct Queue {
    struct QueueElement *head; //lesen + löschen am head
    struct QueueElement *tail; //einfügen am tail
};

struct Queue *initialise_Queue(){
    
    struct Queue * myQueue = malloc(sizeof(*myQueue));

    myQueue->head =NULL;
    myQueue->tail =NULL;

    return myQueue;
}

void enqueue(int this_var, struct Queue *this_Queue){

    struct QueueElement *Elm = malloc(sizeof(*Elm));

    Elm->var = this_var;
    Elm->next= NULL;

    
    if(this_Queue->head==NULL && this_Queue->tail==NULL){ 
        
        // wenn Liste leer 
        
        this_Queue->head = Elm;
        this_Queue->tail =Elm;
    
    } else { 
        this_Queue->tail->next= Elm;
        this_Queue->tail=Elm;
    }

    return;
}

int dequeue(struct Queue *this_Queue ){

    int var_back = this_Queue->head->var;
    struct QueueElement *out;

    if(this_Queue->head ==NULL){
        // schaut ob Queue leer
        return -1;
    }else{
        out=this_Queue->head;
        this_Queue->head = out->next;

        free(out);
    }

    return var_back;

}

void delete_Queue(struct Queue *this_Queue){
    while(this_Queue->head!=NULL){
        // während Elemente noch drinn sind

        dequeue(this_Queue);

    }
    free(this_Queue);

    return;
}

void print_Queue(struct Queue *this_Queue){

    struct QueueElement *temp = this_Queue->head;
    
    if(this_Queue->head==NULL && this_Queue->tail==NULL){
        printf("Queue is empty\n-------------\n");

        return;
    }
    
    while(temp!=NULL){
        printf("%d\n", temp->var);

        temp= temp->next;

    }

    printf("--------------\n");

    return;
}


int main(){

    struct Queue *myQueue = initialise_Queue();

    print_Queue(myQueue);

    enqueue(1, myQueue);
    enqueue(2, myQueue);
    enqueue(3, myQueue);

    print_Queue(myQueue);

    if(dequeue(myQueue)==-1){
        printf("List is empty nothing to dequeue");
    }

    print_Queue(myQueue);

    return 0;
}