#ifndef KANLIB_QUEUE
#define KANLIB_QUEUE 1

#include <stdbool.h>

typedef struct q_node q_node;
typedef struct queue queue;

struct q_node {
	void* item;
	q_node* prev;
	q_node* next;
};


struct queue {
	q_node* front;
	q_node* rear;
};


void queue_init( queue* );

void queue_enqueue( queue*, void* );

void queue_dequeue( queue* );

void* queue_peek( queue* );

bool queue_isempty( queue* );

void queue_free( queue* );


#endif // KANLIB_QUEUE