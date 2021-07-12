/**
*	@file 			queue.h
*	@author 		Doğukan Teber
*	@date 			12/07/2021
*
*
*	@brief Header file for the queue data structure.
*/

#ifndef KANLIB_QUEUE
#define KANLIB_QUEUE 1

#include <stdbool.h>

typedef struct q_node q_node;
typedef struct queue queue;

// Each item in the queue is represented as q_node
struct q_node {
	void* item;		///< Points to the item
	q_node* prev;	///< Points to the previous q_node
	q_node* next;	///< Points to the next q_node
};

// General structure for holding items
struct queue {
	q_node* front;	///< Points to the front q_node ie. first node
	q_node* rear;	///< Points to the rear q_node ie. last node
};


/**
*	@brief Initializes the queue
*
*	@param queue* q
*
*	@returns Nothing
*
*	@attention Call this function before calling other queue functions
*
*	@warning Omitting to call this function has severe consequences
*
*	@see queue_free(queue*)
*/
void queue_init( queue* );




/**
*	@brief Pushes the given element to the rear of the queue and moves rear pointer.
*
*	@param queue* q
*
*	@param (void *) item
*
*	@returns Nothing
*
*	@attention The programmer has to cast the type of the item s/he is passing. Omitting casting causes compiler error.
*
*	@see queue_dequeue(queue*)
*/
void queue_enqueue( queue*, void* );



/**
*	@brief Pops/removes the front node and moves the front pointer.
*
*	@param queue* q
*
*	@returns Nothing
*
*	@attention If there is no element left to be removed, the function returns nothing.
*
*	@see queue_enqueue(queue*, void*)
*/
void queue_dequeue( queue* );


/**
*	@brief Retrieves a void pointer the front element.
*
*	@param queue* q
*
*	@returns ( void * ) to the first element
*
*	@attention The caller of this function has to cast it before using it. Using intptr_t for integers is recommended which is declared in <stdint.h>
*
*	@warning Omitting to cast the return value causes a compilation error.
*
*/
void* queue_peek( queue* );


/**
*	@brief Checks if the given queue is empty or not.
*
*	@param queue* q
*
*	@returns True if the queue is empty, false otherwise
*
*/
bool queue_isempty( queue* );


/**
*	@brief Frees the allocated memory by the given queue.
*
*	@param queue* q
*
*	@returns Nothing
*
*	@attention After you are done with using the queue, you have to call this function to free the allocated memory.
*
*	@warning Omitting to call this function causes memory leaks.
*
*	@see queue_init(queue*)
*/
void queue_free( queue* );


#endif // KANLIB_QUEUE