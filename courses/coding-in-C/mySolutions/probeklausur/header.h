#ifndef HEADER_H
#define HEADER_H 

typedef struct Action {
	int id;
	struct Acion* pnext;
} Action;

typedef struct {
	Action* p_top;

} Stack;

void init_stack(Stack* p_stack);
Action* create_action(int id);
void pop (Stack* p_stack);
void push(Stack* p_stack, Action* p_action);
void print_stack(Stack* p_stack);


#endif /*HEADER_H*/