#ifndef KANLIB_LINKED_LIST
#define KANLIB_LINKED_LIST 1


typedef struct ll_node {
	void* data;
	ll_node* next;
	ll_node* prev;
} ll_node;


typedef struct linked_list {
	ll_node* head;
	ll_node* tail;
} linked_list;


void linked_list_init( linked_list* );

void linked_list_add( linked_list*, void* );

void linked_list_pop_end( linked_list* );

void linked_list_pop_start( linked_list* );

void linked_list_free( linked_list* );


#endif // KANLIB_LINKED_LIST