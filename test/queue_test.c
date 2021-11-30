#include <stdint.h>
#include <CUnit/Basic.h>
#include <kanlib/queue.h>

#include "test.h"


static queue q;

int init_suite_queue(void) {
	queue_init(&q);

	return 0;
}

int clean_suite_queue(void) {
	queue_free(&q);

	return 0;
}

void test_1(void) {
	queue_enqueue(&q, (int *) 10);
	queue_enqueue(&q, (int *) 20);
	queue_enqueue(&q, (int *) 30);
	queue_enqueue(&q, (int *) 40);

	CU_ASSERT( (intptr_t) queue_peek(&q) == 10 );

	queue_dequeue(&q);

	CU_ASSERT( queue_isempty(&q) == 0 )
	CU_ASSERT( (intptr_t) queue_peek(&q) == 20 );

	queue_dequeue(&q);
	queue_dequeue(&q);
	queue_dequeue(&q);

	CU_ASSERT( queue_isempty(&q) == 1 );
}


void test_2(void) {
	CU_ASSERT( queue_isempty(&q) == 1 );

	queue_enqueue(&q, (char *) "Alex");
	queue_enqueue(&q, (char *) "Bob");
	queue_enqueue(&q, (char *) "Candice");
	queue_enqueue(&q, (char *) "Dogukan");
	queue_enqueue(&q, (char *) "Emily");

	CU_ASSERT( (char *) queue_peek(&q) == "Alex" );

	queue_dequeue(&q);

	CU_ASSERT( (char *) queue_peek(&q) == "Bob" );	

	queue_dequeue(&q);

	CU_ASSERT( (char *) queue_peek(&q) == "Candice" );	

	queue_enqueue(&q, (char *) "Zack");

	CU_ASSERT( (char *) queue_peek(&q) == "Candice" );

	CU_ASSERT( queue_isempty(&q) == 0 );
}

int queue_test()
{
	CU_pSuite pSuite = NULL;

	if ( CUE_SUCCESS != CU_initialize_registry() )
		return CU_get_error();

	pSuite = CU_add_suite("Suite 1", init_suite_queue, clean_suite_queue);
	
	if ( pSuite == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ( CU_add_test(pSuite, "Test 1", test_1) == NULL ||
			CU_add_test(pSuite, "Test 2", test_2) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}