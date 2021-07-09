#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/queue.h"

void queue_init(queue* q) {
	q->front = NULL;
	q->rear = NULL;
}

void queue_enqueue(queue* q, void* item) {
	q_node* node = malloc( sizeof(q_node*) );
	node->item = item;
	node->prev = NULL;
	node->next = NULL;

	if ( q->front == NULL && q->rear == NULL ) {
		q->front = node;
		q->rear = node;
	}

	else {
		node->next = q->rear;
		q->rear->prev = node;
		q->rear = node;
	}
}


void* queue_peek(queue* q) {
	return q->front->item;
}

void queue_dequeue(queue* q) {
	// if it is the only element
	if ( q->front == NULL && q->rear == NULL )
		return;

	else if ( q->front == q->rear ) {
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else {
		q_node* temp = q->front;
		q->front = q->front->prev;
		temp->prev = NULL;
		q->front->next = NULL;
		free(temp);
	}
}

bool queue_isempty(queue* q) {
	return q->front == NULL || q->rear == NULL;
}


void queue_free(queue* q) {
	while ( !queue_isempty(q) ) {
		queue_dequeue(q);
	}
}