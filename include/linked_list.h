/**
*	@file 			linked_list.h
*	@author 		Doğukan Teber
*	@date 			19/09/2021
*
*
*	@brief Header file for linked_list.
*/

#ifndef KANLIB_LINKED_LIST
#define KANLIB_LINKED_LIST 1


/// single node in the linked_list struct
typedef struct ll_node {
	void* data;
	struct ll_node* next;
	struct ll_node* prev;
} ll_node;

/// actual linked_list, holds head and tail nodes
typedef struct linked_list {
	ll_node* head;	///< holds head node as pointer
	ll_node* tail;	///< holds tail node as pointer
} linked_list;


/**
*	@brief Initializes the given linked_list.
*
*	@param linked_list* ll
*
*	@returns Nothing
*
*	@attention Call this function before calling other dynamic_array functions
*
*	@see linked_list_free(linked_list*)
*/
void linked_list_init(linked_list*);


/**
*	@brief Returns the size of the given linked_list.
*
*	@param linked_list* ll
*
*	@returns Size of a linked_list
*
*/
size_t linked_list_size(linked_list*);


/**
*	@brief Counts the given item in the given linked_list and returns the result.
*
*	@param linked_list* ll
* 	@param void* item (the caller must cast this parameter)
*
*	@returns How many of item is in linked_list
*
*/
size_t linked_list_count(linked_list*, void*);


/**
*	@brief Returns the nth element in the linked_list. The retuned value must be casted.
*
*	@param linked_list* ll
*	@param size_t index
*
*	@returns nth element. Cast the result value.
*
*/
void* linked_list_get_nth(linked_list*, size_t);


/**
*	@brief Inserts the given element to the head of the given linked_list.
*
*	@param linked_list* ll
*	@param void* item (the caller must cast this parameter)
*
*	@returns nothing
*
*/
void linked_list_insert_start(linked_list*, void*);


/**
*	@brief Inserts the given elemenet to the tail of the given linked_list.
*
*	@param linked_list* ll
*	@param void* item (the caller must cast this parameter)
*
*	@returns nothing
*
*/
void linked_list_insert_end(linked_list*, void*);


/**
*	@brief Inserts the given elemenet to the nth position of the given linked_list.
*
*	@param linked_list* ll
*	@param void* item (the caller must cast this parameter)
*	@param size_t index
*
*	@returns nothing
*
*/
void linked_list_insert_nth(linked_list*, void*, size_t);


/**
*	@brief Removes first element of the given linked_list.
*
*	@param linked_list* ll
*
*	@returns nothing
*
*/
void* linked_list_pop_start(linked_list*);


/**
*	@brief Removes last element of the given linked_list.
*
*	@param linked_list* ll
*
*	@returns nothing
*
*/
void* linked_list_pop_end(linked_list*);


/**
*	@brief Merges to lists and assigns the second list to NULL.
*
*	@param linked_list* l1
*	@param linked_list* l2
*
*	@returns nothing
*
*/
void linked_list_concatenate(linked_list*, linked_list*);


/**
*	@brief Divides the given list into the middle.
*
*	@param linked_list* src
*	@param linked_list* dest1
*	@param linked_list* dest2
*
*	@note If the size of src list is odd, dest1's size will be 
*	greater than size of dest2. For example, let size of src be 7. 
*	After the function call, the size of dest1 will be 4 and 
*	dest2's will be 3.
*
*	@returns nothing
*
*/
void linked_list_divide_half(linked_list*, linked_list*, linked_list*);


/**
*	@brief Takes a sorted list and removes duplicated values.
*
*	@param linked_list* ll (sorted)
*
*	@returns nothing
*
*/
void linked_list_remove_duplicates(linked_list*);


/**
*	@brief Frees up the memory and does necessary deallocations.
*
*	@param linked_list* ll
*
*	@returns nothing
*
*	@see linked_list_init(linked_list*)
*/
void linked_list_free(linked_list*);


#endif // KANLIB_LINKED_LIST