#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	//printf("hello World!");

	Stack* p_stack = malloc(sizeof(*p_stack));
	if (p_stack == NULL) {
		printf("ERROR CREATING STACK\n");
		return -1;
	}
	init_stack(p_stack);


	//10 steps -> first step is step 0 => first step is viewd as even 

	for (int i = 0; i < 10; i++) {
		
		int id = i * 100;
		

		//if i is even:
		if ((i % 2) == 0) {
			
			Action* p_new_action1 = create_action(id + 1);

			if ( p_new_action1 == NULL) {
				printf("ERROR\n");
				return -1;
			}
			
			Action* p_new_action2 = create_action(id + 2);

			if (p_new_action2 == NULL) {
				printf("ERROR\n");
				return -1;
			}

			push(p_stack, p_new_action1);
			push(p_stack, p_new_action2);
		} //if i is uneven:
		else if ((i % 2) == 1) {
			pop(p_stack);
		}

		print_stack(p_stack);
	}


	return 0;
}