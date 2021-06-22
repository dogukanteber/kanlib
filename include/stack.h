#ifndef KANLIB_STACK
#define KANLIB_STACK 1

#include <stdbool.h>

#define KANLIB_INIT_CAPACITY 4

#define STACK_INIT(s) stack_init(&s)
#define STACK_PUSH(s, type, item) stack_push(&s, (type) item)
#define STACK_POP(s) stack_pop(&s)
#define STACK_TOP(s) stack_top(&s)
#define STACK_EMPTY(s) stack_empty(&s)
#define STACK_FREE(s) stack_free(&s)

typedef struct stack stack;

struct stack {
	void** items;		// holds items
	size_t top;			// points current position
	size_t capacity;	// total size
};


void stack_init(stack*);

void stack_push(stack*, void*);

void stack_pop(stack*);

void* stack_top(stack*);

bool stack_empty(stack *);

void stack_free(stack*);

#endif