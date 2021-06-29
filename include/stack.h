/**
*	@file 			stack.h
*	@author 		Doğukan Teber
*	@date 			29/06/2021
*
*
*	@brief Header file for the stack data structure.
*/


#ifndef KANLIB_STACK
#define KANLIB_STACK 1


#include <stdbool.h>


#define KANLIB_INIT_CAPACITY 4 ///< Default length of the stack


#define STACK_INIT(s) stack_init(&s)
#define STACK_PUSH(s, type, item) stack_push(&s, (type) item)
#define STACK_POP(s) stack_pop(&s)
#define STACK_TOP(s) stack_top(&s)
#define STACK_EMPTY(s) stack_empty(&s)
#define STACK_FREE(s) stack_free(&s)




/// Forward declaration of typedef for stack struct
typedef struct stack stack;




/// stack is a struct that holds the items, size and the capacity of the stack similiar to dynamic_array
struct stack {
	void** items;		///< holds items
	size_t top;			///< points to the top of the stack
	size_t capacity;	///< total size
};





/**
*	@brief Initializes the stack with initial capacity 4
*	
*	@param stack* s
*
*	@returns Nothing
*	
*	@attention Call this function before calling other stack functions
*
*	@warning Omitting to call this function has severe consequences
*
*	@see KANLIB_INIT_CAPACITY stack stack_free(s*)
*/
void stack_init(stack*);






/**
*	@brief Pushes the given element to the given stack.
*
*	@param stack* s
*	@param void* item
*
*	@returns Nothing
*
*	@attention Since the second function of this function is void pointer, the programmer must cast the type of the item.
*	
*	@note If current capacity is not enough to hold the elements, stack expands itself by multiplying the capacity by 2.
*
*	### Example
*	stack_push(&s, (char*) "John Doe");
*
*	@see stack_pop(s*)
*/
void stack_push(stack*, void*);







/**
*	@brief Pops the top element.
*
*	@param stack* s
*
*	@returns Nothing
*
*	@see stack_push(stack* s, void* item)
*/
void stack_pop(stack*);







/**
*	@brief Returns the top element in the stack.
*
*	@param stack* s
*
*	@returns void pointer to the top element
*
*	@attention Since this function returns void pointer to the element, it is programmer's responsibility to cast before using it.
*
*	### Example
*	char* top_name = ( char* ) stack_top(&s);
*	intptr_t number = ( intptr_t )stack_top(&s);
*/
void* stack_top(stack*);






/**
*	@brief Returns TRUE if the stack is empty, otherwise FALSE.
*
*	@param stack* s
*
*	@returns TRUE if stack is empty, FALSE otherwise
*/
bool stack_empty(stack *);





/**
*	@brief Frees the stack
*
*	@param stack* s
*
*	@returns Nothing
*
*	@attention If you are done with using stack, you should call this function to free the allocated memory. Omitting to call this function causes memory leaks.
*
*	@see stack_init(stack*)
*/
void stack_free(stack*);



#endif // KANLIB_STACK