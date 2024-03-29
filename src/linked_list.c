#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "../include/linked_list.h"

// Take a look at inserting and popping function deeply

void linked_list_init(linked_list* ll) {
	ll->head = NULL;
	ll->tail = NULL;
}

size_t linked_list_size(linked_list* ll) {
	ll_node* temp_head = ll->head;
	size_t size = 0;
	while ( temp_head != NULL ) {
		size++;
		temp_head = temp_head->next;
	}
	return size;
}

size_t linked_list_count(linked_list* ll, void* item) {
	size_t count = 0;
	ll_node* temp_head = ll->head;
	while ( temp_head != NULL ) {
		if ( temp_head->data == item )
			count++;
		temp_head = temp_head->next;
	}
	return count;
}

void* linked_list_getnth(linked_list* ll, size_t index) {
	size_t size = linked_list_size(ll);
	if ( index < 0 || index >= size ) {
		printf("%s\n", "Out of bounds in linked_list_getnth.");
		exit(EXIT_FAILURE);
	}

	ll_node* temp_head = ll->head;
	for ( int i=0; i<size; ++i ) {
		if ( i == index ) 
			return temp_head->data;
		temp_head = temp_head->next;
	}
}

void linked_list_dummy(linked_list* ll) {
	linked_list_insert_start(ll, (int*) 1);
	linked_list_insert_start(ll, (int*) 2);
	linked_list_insert_start(ll, (int*) 3);
}

void linked_list_print(linked_list* ll) {
	ll_node* temp_head = ll->head;
	while ( temp_head != NULL ) {
		printf("%ld ", (intptr_t) temp_head->data);
		temp_head = temp_head->next;
	}
	printf("\n");
}

static ll_node* linked_list_create_node(void* item) {
	ll_node* new_node = malloc( sizeof(ll_node) );
	new_node->data = item;
	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;
}

void linked_list_insert_start(linked_list* ll, void* item) {
	ll_node* new_node = linked_list_create_node(item);

	if ( ll->head == NULL ) {
		ll->head = new_node;
	}

	if ( ll->tail == NULL ) {
		ll->tail = new_node;
	}

	else {
		new_node->next = ll->head;
		ll->head->prev = new_node;
		ll->head = new_node;
	}
}

void linked_list_insert_end(linked_list* ll, void* item) {
	// create a ll_node
	ll_node* new_node = linked_list_create_node(item);

	// check if head is empty
	if ( ll->head == NULL ) {
		ll->head = new_node;
	}

	// check if tail is empty
	if ( ll->tail == NULL ) {
		ll->tail = new_node;
	}
	// add the element to the end
	else {
		ll->tail->next = new_node;
		new_node->prev = ll->tail;
		ll->tail = new_node;
	}
}


void linked_list_insert_nth(linked_list* ll, void* item, size_t index) {
	size_t size = linked_list_size(ll);
	if ( size < index ) {
		fprintf(stdout, "Index cannot be greater than size. (linked_list_insert_nth)\n");
		return;
	}

	if ( index == 0) {
		linked_list_insert_start(ll, item);
		return;
	}

	if ( size == index ) {
		linked_list_insert_end(ll, item);
		return;
	}

	ll_node* new_node = linked_list_create_node(item);


	ll_node* current = ll->head;
	ll_node* following = ll->head->next;

	while ( following != NULL ) {
		if ( index == 1 ) {
			current->next = new_node;
			new_node->next = following;
			following->prev = new_node;
			new_node->prev = current;
		}
		current = following;
		following = following->next;
		index--;
	}
}

void* linked_list_pop_start(linked_list* ll) {
	void* value = NULL;
	if ( ll->head != NULL ) {
		ll_node* temp = ll->head;
		value = temp->data;
		ll->head = ll->head->next;
		ll->head->prev = NULL;
		free(temp);
	}
	return value;
}

// check the condition when there is one element left 
// and the tail is NULL while head is assigned to something
void* linked_list_pop_end(linked_list* ll) {
	void* value = NULL;
	if ( ll->tail != NULL ) {
		ll_node* temp = ll->tail;
		value = temp->data;
		ll->tail = ll->tail->prev;
		ll->tail->next = NULL;
		free(temp);
	}
	if ( linked_list_size(ll) == 1 ) {
		ll_node* temp = ll->head;
		value = temp->data;
		ll->head = NULL;
		ll->tail = NULL;
		free(temp);
	}
	return value;
}


void linked_list_free(linked_list* ll) {
	ll_node* head = ll->head;
	ll_node* temp = ll->head;

	while ( temp != NULL ) {
		head = temp;
		temp = temp->next;
		free(head);
	}
}

// does not check if the head is empty
// check again, there are some issues with void pointers and sizes
void linked_list_insert_inorder(linked_list* ll, ll_node* node) {
	ll_node* current = ll->head;
	ll_node* following = ll->head->next;

	int flag = 0;
	while ( following != NULL ) {
		if ( current->data < node->data && following->data > node->data ) {
			current->next = node;
			node->next = following;
			node->prev = current;
			following->prev = node;
			flag = 1;
		}
		current = following;
		following = following->next;
	}
	// there is no insertion above
	if ( !flag ) {
		current->next = node;
		node->prev = current;
		ll->tail = node;
	}
}

void linked_list_concatenate(linked_list* l1, linked_list* l2) {
	ll_node* l1_runner = l1->tail;
	ll_node* l2_runner = l2->head;
	
	while ( l2_runner != NULL ) {
		l1_runner->next = l2_runner;
		l2_runner->prev = l1_runner;

		l1_runner = l1_runner->next;
		l2_runner = l2_runner->next;
	}
	l1->tail = l1_runner;

	l2->head = NULL;
	l2->tail = NULL;
}


void linked_list_divide_half(linked_list* src, linked_list* dest1, linked_list* dest2) {
	size_t size = linked_list_size(src);

	linked_list_init(dest1);
	linked_list_init(dest2);


	if ( size < 2 ) {
		dest1->head = src->head;
		dest2->head = NULL;
		return;
	}
	
	size_t move = (size - 1) / 2;

	ll_node* runner = src->head;

	while ( move-- ) {
		runner = runner->next;
	}
	
	dest1->head = src->head;
	dest1->tail = runner;

	dest2->head = runner->next;
	dest2->tail = src->tail;

	runner->next = NULL;
}

void linked_list_remove_duplicates(linked_list* ll) {
	assert(ll->head != NULL);

	ll_node* runner = ll->head;
	while ( runner->next != NULL ) {
		if ( runner->data == runner->next->data ) {
			ll_node* to_removed = runner->next;
			runner->next = to_removed->next;
			free(to_removed);
		}
		else 
			runner = runner->next;
	}
}

void linked_list_move_node(linked_list* l1, linked_list* l2) {
	if ( l2 == NULL ) {
		printf("%s\n", "Second list is empty. No element to pop.");
		exit(EXIT_FAILURE);
	}

	void* l2_head = linked_list_pop_start(l2);
	linked_list_insert_start(l1, l2_head);
}

void linked_list_reverse(linked_list* ll) {
	ll_node* head = ll->head;
	ll_node* tail = ll->tail;

	ll_node* front = NULL;
	ll_node* middle = ll->head;
	ll_node* back = NULL;

	while ( middle != NULL ) {
		front = middle->next;
		middle->next = back;
		back = middle;
		middle = front;
	}

	ll->head = tail;
	ll->tail = head;
}

void linked_list_reverse_recursive(linked_list* ll, ll_node* current) {
	if ( current == NULL )
		return;

	// we are at the end of the list
	if ( current->next == NULL ) {
		// make the current node head
		ll->head = current;
		return;
	}

	linked_list_reverse_recursive(ll, current->next);
	current->next->next = current;
	current->next = NULL;

	ll->tail = current;
}

int main(int argc, char const *argv[]) {
	linked_list linked_l1, linked_l2;
	linked_list* l1 = &linked_l1;
	linked_list* l2 = &linked_l2;

	linked_list_init(l1);
	linked_list_init(l2);

	linked_list_insert_end(l1, (int*) 1);
	linked_list_insert_end(l1, (int*) 2);
	linked_list_insert_end(l1, (int*) 3);
	linked_list_insert_end(l1, (int*) 4);

	linked_list_insert_end(l2, (int*) 4);
	linked_list_insert_end(l2, (int*) 3);
	linked_list_insert_end(l2, (int*) 2);
	linked_list_insert_end(l2, (int*) 1);

	linked_list_reverse_recursive(l1, l1->head);
	linked_list_reverse_recursive(l2, l2->head);

	linked_list_print(l1);
	linked_list_print(l2);


	linked_list_free(l1);
	linked_list_free(l2);

	return 0;
}
