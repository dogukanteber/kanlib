### API

```c
struct q_node {
	void* item;
	q_node* prev;
	q_node* next;
};

struct queue {
	q_node* front;
	q_node* rear;
};
```

```c
void queue_init(queue* q);
```

Initializes the given queue.

```c
void queue_enqueue(queue* q, void* data);
```

Inserts the given data to the end of the queue. You must cast the data when passing to the function.

```c
void queue_dequeue(queue* q);
```

Removes the front element of the given queue.

```c
void* queue_peek(queue* q);
```

Returns the front element of the given queue.

```c
bool queue_isempty(queue* q);
```

Returns true if the given queue is empty, false otherwise.

```c
void queue_free(queue* q);
```

Frees the memory allocated by the given queue. You must call after you are done with using the given stack.