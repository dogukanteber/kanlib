#include <stdlib.h>
#include <stdio.h>

#include "../include/stack.h"


void stack_init(stack* s) {
	s->capacity = KANLIB_INIT_CAPACITY;
	s->top = 0;
	s->items = malloc( sizeof(void *) * s->capacity );
}

void stack_push(stack* s, void* item) {
	if ( s->top == s->capacity ) {
		void** items = realloc( s->items, sizeof(void*) * s->capacity * 2 );
		s->items = items;
		s->capacity = s->capacity * 2;
	}

	s->items[s->top++]  = item;
}

bool stack_empty(stack* s) {
	return s->top == 0;
}

void* stack_top(stack* s) {
	return s->items[s->top-1];
}

void stack_pop(stack* s) {
	if ( s->top > 0 ) {
		s->items[s->top] = NULL;
		s->top--;
	}
	else {
		printf("%s\n", "stack is empty");
	}
}


void stack_free(stack* s) {
	free(s->items);
}