#include <stdlib.h>
#include <stdio.h>

#include "../include/linked_list.h"


void linked_list_init(linked_list* ll) {
	ll->head = NULL;
	ll->tail = NULL;
}


void linked_list_add(linked_list* ll, void* data) {
	// create a ll_node
	ll_node* new_node = malloc( sizeof(ll_node*) );
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

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

void linked_list_pop_end(linked_list* ll) {
	if ( ll->tail != NULL ) {
		ll_node* temp = ll->tail;
		ll->tail = ll->tail->prev;
		ll->tail->next = NULL;
		free(temp);
	}
}

void linked_list_pop_start(linked_list* ll) {
	if ( ll->head != NULL ) {
		ll_node* temp = ll->head;
		ll->head = ll->head->next;
		ll->head->prev = NULL;
		free(temp);
	}
}


void linked_list_free(linked_list* ll) {
	ll_node* head = ll->head;
	ll_node* temp = ll->head;

	while ( temp != NULL ) {
		head = temp;
		temp = temp->next;
		free(head);
	}
	free(ll->head);
	free(ll->tail);
}

int main(int argc, char const *argv[]) {
	linked_list ll;

	linked_list_init(&ll);

	linked_list_add( &ll, "dogukan");
	linked_list_add( &ll, "teber");
	linked_list_add( &ll, "dogukan");
	linked_list_add( &ll, "teber");

	linked_list_pop_start(&ll);
	
	linked_list_pop_end(&ll);

	while ( ll.head != NULL ) {
		printf("%s\n", ll.head->data);
		ll.head = ll.head->next;
	}


	linked_list_free(&ll);
	

	return 0;
}