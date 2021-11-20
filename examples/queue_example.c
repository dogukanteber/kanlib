#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <kanlib/queue.h>

/*
* This simple program prints the elements
* in the given queue.
*/

void init_queue(queue* q) {
    queue_init(q);

    for ( size_t i=0; i<10; ++i ) {
        queue_enqueue(q, (int*) i+1);
    }
}

void print_queue(queue* q) {
    while ( !queue_isempty(q) ) {
        printf("%ld ", (intptr_t) queue_peek(q));
        queue_dequeue(q);
    }
}

int main(int argc, char const *argv[]) {
    queue my_queue;
    queue* q = &my_queue;

    printf("Front of the queue -> ");
    init_queue(q);
    print_queue(q);
    printf("<- Rear of the queue");
    printf("\n");


    return 0;
}
