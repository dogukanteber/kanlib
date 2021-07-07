#include <CUnit/Basic.h>
#include <stdint.h>

#include "test.h"
#include "../include/stack.h"

static stack s;

int init_suite1(void) {
	stack_init(&s);

	return 0;
}

int clean_suite1(void) {
	stack_free(&s);

	return 0;
}

void test_push(void) {
	stack_push(&s, (int *) 1);
	stack_push(&s, (int *) 2);
	stack_push(&s, (int *) 3);
	stack_push(&s, (int *) 4);
	stack_push(&s, (int *) 5);

	CU_ASSERT( (intptr_t) stack_top(&s) == 5 );
	CU_ASSERT( stack_empty(&s) == 0 );
}

void test_pop(void) {
	stack_pop(&s);
	stack_pop(&s);

	CU_ASSERT( (intptr_t) stack_top(&s) == 3 );

	stack_pop(&s);
	stack_pop(&s);
	stack_pop(&s);

	CU_ASSERT( stack_empty(&s) == 1 );
}


int stack_test(int argc, char const *argv[])
{
	CU_pSuite pSuite = NULL;

	if ( CUE_SUCCESS != CU_initialize_registry() )
		return CU_get_error();

	pSuite = CU_add_suite("Suite 1", init_suite1, clean_suite1);
	
	if ( pSuite == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ( CU_add_test(pSuite, "Test 1", test_push) == NULL ||
			CU_add_test(pSuite, "Test 2", test_pop) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}