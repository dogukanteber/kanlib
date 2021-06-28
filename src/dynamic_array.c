#include <stdlib.h>
#include <stdio.h>


#include "../include/dynamic_array.h"


void dynamic_array_init(dynamic_array* da) {
	da->capacity = DYNAMIC_ARRAY_INIT_CAPACITY;
	da->size = 0;
	da->items = malloc(sizeof(void *) * da->capacity);
}

size_t dynamic_array_size(dynamic_array* da) {
	return da->size;
}

static void dynamic_array_resize(dynamic_array* da, size_t capacity) {
	#ifdef DEBUG_ON
	printf("dynamic_array_resize: %d to %d\n", da->capacity, capacity);
	#endif

	void** items = realloc(da->items, sizeof(void *) * capacity);
	if ( items ) {
		da->items = items;
		da->capacity = capacity;
	}
}

void dynamic_array_add(dynamic_array* da, void* item) {
	// resize if there is no space left
	if ( da->size >= da->capacity )
		dynamic_array_resize(da, da->capacity * 2);

	da->items[da->size++] = item;
}

void* dynamic_array_get(dynamic_array* da, size_t index) {
	// validate the given index
	if ( index >= 0 && index < da->size )
		return da->items[index];

	return NULL;
}

void dynamic_array_set(dynamic_array* da, size_t index, void* item) {
	if ( index >= 0 && index < da->size ) {
		da->items[index] = item;
	}
}

void dynamic_array_delete(dynamic_array* da, size_t index) {
	// if index is not valid, terminate the function call
	if ( index >= 0 && index >= da->size )
		return;

	da->items[index] = NULL;

	// move elements one index left
	for ( int i = index; i < da->size - 1; i++ ) {
		da->items[i] = da->items[i+1];
		da->items[i+1] = NULL;
	}

	da->size--;

	// if quarter of the array is full, reduce the capacity to half
	if ( da->size > 0 && da->size == da->capacity / 4 )
		dynamic_array_resize(da, da->capacity / 2);

}

void dynamic_array_free(dynamic_array* da) {
	free(da->items);
}