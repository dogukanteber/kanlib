#ifndef KANLIB_QUEUE
#define KANLIB_QUEUE 1


typedef struct q_node {
	void* item;
	q_node* prev;
	q_node* next;
} q_node;


typedef struct queue {
	q_node* head;
	q_node* tail;
} queue;


void queue_init( queue* );

void queue_push( queue* , void* );

void queue_pop( queue* );

void* queue_head( queue* );

void* queue_tail( queue* );

void queue_free( queue* );


#endif // KANLIB_QUEUE