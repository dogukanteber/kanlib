### What is linked_list?

linked_list is an implementation of doubly linked list. Each element in a linked_list is called a node. Nodes keep actual data, previous node and next node. Each node unites and makes linked_list data structure who keeps head node and tail node.

### API

```c
typedef struct ll_node {
	void* data;
	struct ll_node* next;
	struct ll_node* prev;
} ll_node;

typedef struct linked_list {
	ll_node* head;
	ll_node* tail;
} linked_list;
```

```c
void linked_list_init(linked_list* ll);
```

Initializes the given linked_list. Call it before working on with linked_list.

```c
size_t linked_list_size(linked_list* ll);

Returns the size of the given linked_list.

```c
size_t linked_list_count(linked_list* ll, void* item);
```

Counts the given element in the given list. Cast the second parameter when calling the function.

```c
void* linked_list_get_nth(linked_list* ll, size_t index);
```

Returns the nth value in the given linked_list. If the index is negative or greater than the linked_list's size, it returns an error. Cast the returned value.

```c
void linked_list_insert_start(linked_list* ll, void* item);
```

Inserts the given item to the head of the given linked_list. Cast the second argument when calling the function.

```c
void linked_list_insert_end(linked_list* ll, void* item);
```

Inserts the given item to the end (tail) of the given linked_list. Cast the second argument when calling the function.

```c
void linked_list_insert_nth(linked_list* ll, void* item, size_t index);
```

Inserts the given element to the nth index of the given list. Cast the second parameter(item) when calling the function.

```c
void linked_list_pop_start(linked_list* ll);
```

Removes the first element of the given list and returns the removed element.

```c
void linked_list_pop_end(linked_list* ll);
```

Removes the last element of the given list and returns the removed element.

```c
void linked_list_concatenate(linked_list* l1, linked_list* l2);
```

Merges the second list to the first list and frees l2.

```c
void linked_list_remove_duplicates(linked_list* ll);
```

Takes a sorted list as an argument and removes the duplicated values.

```c
void linked_list_divide_half(linked_list* src, linked_list* dest1, linked_list* dest2);
```

Divides the given list into the middle. If the size of src list is an odd number, left part's size is greater than right part. For example, size of src is 9 then size of dest1 will be 5 and dest2 wiill be 4.

```c
void linked_list_reverse(linked_list* ll);
```

Reverses the given linked_list.

```c
void linked_list_reverse_recursive(linked_list* ll, ll_node* current);
```

Reverses the given linked_list, recursively.

```c
void linked_list_free(linked_list* ll);
```

Frees up the memory that is held by the given linked_list.