### What is dynamic_array?

dynamic_array is dynamically allocated array. It is known as vector in C++, ArrayList in Java and some other names in other languages. Its feature is whenever there is no space for future elements, it allocates new space for future elements. If there is too little elements compared to its capacity, it shrinks. To learn more information about these functionalities, take a look at dynamic_array_add and dynamic_array_delete functions.

### API

```c
typedef struct dynamic_array {
	void** items;
	size_t size;
	size_t capacity;
} dynamic_array;
```

```c
void dynamic_array_init(dynamic_array* da)
```

Initializes the given dynamic_array. Call it before working on dynamic_array.

```c
size_t dynamic_array_size(dynamic_array* da)
```

Returns the size of the given dynamic_array.

```c
void* dynamic_array_get(dynamic_array* da, size_t index)
```

Returns a void pointer to the requested item.

```c
void dynamic_array_set(dynamic_array* da, size_t index, void* item)
```

Assigns the element that is the given index to the given item.

```c
void dynamic_array_add(dynamic_array* da, void* item)
```

Adds the given element at the end of the dynamic_array.

```c
void dynamic_array_delete(dynamic_array* da, size_t index)
```

Deletes the element that lives in the given index of the dynamic_array.

```c
void dynamic_array_free(dynamic_array* da)
```

Frees up the allocated space for dynamic_array and cleans up the memory.
