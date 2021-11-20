#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <kanlib/stack.h>

/*
* This simple program reverses the given
* string using kanlib functions.s
*/

void init_stack(stack* s, const char* phrase) {
    stack_init(s);
    size_t size = strlen(phrase);
    for ( size_t i=0; i<size; ++i ) {
        stack_push(s, (int*) phrase[i]);
    }
}

void reverse(stack* s) {
    while ( !stack_empty(s) ) {
        printf("%c ", (intptr_t) stack_top(s));
        stack_pop(s);
    }
}

int main(int argc, char const *argv[]) {
    stack my_stack;
    stack* s = &my_stack;

    init_stack(s, "reverse");
    reverse(s);


    return 0;
}
