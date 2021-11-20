#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <kanlib/linked_list.h>

/*
* This simple program prints the given elements
* in the given linked list in reverse order.
*/

void init_ll(linked_list* ll) {
    linked_list_init(ll);
    for ( size_t i=0; i<10; ++i ) {
        linked_list_insert_end(ll, (int*) i);
    }
}

void print_ll(linked_list* ll) {
    size_t size = linked_list_size(ll);
    for ( int i=0; i<size; ++i ) {
        printf("%d ", (intptr_t) linked_list_pop_end(ll));
    }
}

int main(int argc, char const *argv[]) {
    linked_list linked_l;
    linked_list* ll = &linked_l;

    init_ll(ll);
    print_ll(ll);

    return 0;
}
