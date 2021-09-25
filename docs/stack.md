### API

```c
struct stack {
	void** items;
	size_t top;
	size_t capacity;
};

typedef struct stack stack;
```

```c
void stack_init(stack* s);
```

Initializes the given stack. You must call it before you starting to work with the given stack.

```c
void stack_push(stack* s, void* data);
```

Pushes the given data to the given stack. You must cast the data parameter to the appropriate type.

```c
void stack_pop(stack* s);
```

Pops the top element from the given stack.

```c
void* stack_top(stack* s);
```

Returns the top element of the given stack.

```c
bool stack_empty(stack* s);
```

Returns true if the given stack is empty, false otherwise.

```c
void stack_free(stack* s);
```

Frees the memory allocated by the given stack. You must call it after you are done using the given stack.