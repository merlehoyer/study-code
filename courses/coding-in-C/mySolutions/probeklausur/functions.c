#include "header.h"
#include <stdio.h>
#include <stdlib.h>

/* gives top pointer to stack NULL pointer (stack empty)
* mitgabe: pointer to stack
* no return value
*/

void init_stack(Stack* p_stack) {

	p_stack->p_top = NULL;

	return;
}

/* creates new action 
* mitgabe: id of action
* return: pointer to struct action
*/

Action* create_action(int id) { 

	//check in main value of *p_new_action
	Action* p_new_action = malloc(sizeof(*p_new_action));
	if (p_new_action == NULL) {
		printf("ERROR CREATING NEWACTION\n");
	}

	p_new_action->id = id;

	return p_new_action;
	
}

/* removes action from stack bei R�ckg�ngig 
* mitgabe: pointer to struct
* return: no return value
*/
void pop(Stack* p_stack) {
	
	Action* p_temp = p_stack->p_top;
	p_stack->p_top = p_stack->p_top->pnext;

	printf("removed action id: %d\n", p_temp->id);

	free(p_temp);

	return;
}

/* adds new action to top of stack
* mitgabe: pointer to new action / pointer to stack
* no return value
*/
void push(Stack* p_stack, Action* p_action) {

	p_action->pnext = p_stack->p_top;
	p_stack->p_top = p_action;

	return;
}

/* prints all elements of stack
* mitgabe: pointer to stack
* no return value
*/
void print_stack(Stack* p_stack) {

	Action* p_temp = p_stack->p_top;
	int iterator = 0;
	if (p_temp == NULL) {
		printf("empty stack\n");
	}
	while (p_temp != NULL) {

		printf("%dte Element (from top) in Stack with id: %d \n", iterator, p_temp->id);
		iterator++;
		p_temp = p_temp->pnext;
	}

	printf("--------------\n");

	return;
}