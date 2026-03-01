#include <stdio.h>
#include <stdlib.h>


void push();
int pop();
void delete_Stack();
void print_Stack();

struct StackElement {

    int key;
    struct StackElement *next;

};

typedef struct {
   struct StackElement *top;
    
} Stack;


int main(){

    Stack *myStack = malloc (sizeof(*myStack));
    myStack->top= NULL;

    print_Stack(myStack);

    push(1, myStack);
    push(2, myStack);
    push(3, myStack);

    print_Stack(myStack);

    pop(myStack);

    print_Stack(myStack);

    delete_Stack(myStack);

    print_Stack(myStack);


    return 0;
}


void push(int key, Stack *Stack){
    
    struct StackElement *newElm = (struct StackElement*) malloc(sizeof(*newElm));
    newElm->key= key;

    newElm->next= Stack->top;
    Stack->top= newElm; 

    return;
}

int pop(Stack *Stack){

    

    struct StackElement *temp;

    temp= Stack->top;
    int key;
    key = Stack->top->key;

    Stack->top = Stack->top->next;
    

    free(temp);

    return key;
}

void delete_Stack(Stack *Stack){
    
    struct StackElement *temp;
    temp= Stack->top;
    

    while(temp!=NULL){
        pop(Stack);
        temp=Stack->top;
    }

    free(Stack);
    free(temp);

    //oder ohne temp => einfacher

    return;
}

void print_Stack(Stack *Stack){

    struct StackElement *temp;
    temp= Stack->top;

    while(temp!=NULL){
        printf("%d\n", temp->key);

        temp= temp->next;
    }

    printf("------------\n");
    return;
}