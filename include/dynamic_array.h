/**
*	@file 			dynamic_array.h
*	@author 		Doğukan Teber
*	@date 			18/06/2021
*
*
*	@brief Header file for the dynamic array.
*/


#ifndef KANLIB_DYNAMIC_ARRAY
#define KANLIB_DYNAMIC_ARRAY 1

#define DYNAMIC_ARRAY_INIT_CAPACITY 4 ///< Default length of the dynamic array


#define DYNAMIC_ARRAY_INIT(da) dynamic_array da; dynamic_array_init(&da)
#define DYNAMIC_ARRAY_ADD(da, item) dynamic_array_add(&da, (void *) item);
#define DYNAMIC_ARRAY_SIZE(da) dynamic_array_size(&da);
#define DYNAMIC_ARRAY_GET(da, type, index) (type) dynamic_array_get(&da, index)
#define DYNAMIC_ARRAY_SET(da, index, item) dynamic_array(&da, index, (void *) item)
#define DYNAMIC_ARRAY_DELETE(da, index) dynamic_array_delete(&da, index)
#define DYNAMIC_ARRAY_FREE(da) dynamic_array_free(&da)


/// dynamic_array is a struct that holds the items, size and the capacity of the dynamic array
typedef struct dynamic_array {
	void** items; 		///< contains items in other words, array
	size_t size;  		///< current size of the dynamic array
	size_t capacity;	///< total size of the dynamic array ie. capacity
} dynamic_array;


/**
*	@brief Initializes the dynamic_array with initial capacity of 4
*
*	@param dynamic_array* da
*
*	@returns Nothing
*
*	@attention Call this function before calling other dynamic_array functions
*
*	@warning Omitting to call this function has severe consequences
*
*	@see DYNAMIC_ARRAY_INIT_CAPACITY dynamic_array dynamic_array_free(dynamic_array*)
*/
void dynamic_array_init(dynamic_array *);





/**
*	@brief Returns size of the dynamic_array
*
*	@param dynamic_array* da
*
*	@returns Size of the dynamic_array
*/
size_t dynamic_array_size(dynamic_array *);




/**
*	@brief Returns the element which is specified by index
*
*	@param dynamic_array* da
*	@param size_t index
*
*	@returns ( void * ) to the element
*
*	@attention Since the function returns ( void * ), it is user's responsibility to cast the return value.
*	Casting directly to int* gives compilation error. Instead, use intptr_t which is declared in stdint.h
*
*
*
*/ 
void* dynamic_array_get(dynamic_array *, size_t);





/**
*	@brief Sets the element specified by index to another value
*
*	@param dynamic_array* da 
*	@param size_t index 
*	@param ( void * ) item
*
*	@returns Nothing
*
* 	@attention Like in dynamic_array_get function, third parameter requires casting.
*
*	@see dynamic_array_get(dynamic_array* da, size_t)
*
*/
void dynamic_array_set(dynamic_array *, size_t, void *);




/**
*	@brief Resizes the array's capacity
*
*	@param dynamic_array* da 
*	@param size_t capacity
*
*	@note The reason why this function is static is to add accessibility control to the function.
*
*	@returns Nothing
*
*/
static void dynamic_array_resize(dynamic_array *, size_t);





/**
*	@brief Adds the given element to the given dynamic_array
*
*	@param dynamic_array* da
*	@param ( void * ) item
*	
*	@attention Same casting rules in dynamic_array_get and dynamic_array_set applies here too.
*
*	@see dynamic_array_delete(dynamic_array*, size_t) dynamic_array_get(dynamic_array* da, size_t) dynamic_array_set(dynamic_array* da, size_t, void*)
*
*/
void dynamic_array_add(dynamic_array *, void *);



/**
*	@brief Deletes the element by the given index from the dynamic_array
*
*	@param dynamic_array* da
*	@param size_t index
*
*	@note The function resizes the dynamic_array into half if quarter of the dynamic_array is full.
*
*	@see dynamic_array_add(dynamic_array*, void *) dynamic_array_resize(dynamic_array*, size_t)
*
*/
void dynamic_array_delete(dynamic_array *, size_t);


/**
*	@brief Frees the dynamic_array
*
*	@param dynamic_array* da
*
*	@warning Do not forget to free the dynamic_array when you are done using it. Omitting to free the dynamic array will cause memory leaks.
*
*	@see dynamic_array_init(dynamic_array*);
*
*/
void dynamic_array_free(dynamic_array *);


#endif // KANLIB_DYNAMIC_ARRAY