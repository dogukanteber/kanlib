#include <stdint.h>
#include <CUnit/Basic.h>
#include <kanlib/stack.h>

#include "test.h"

static stack s;

int init_suite_stack(void) {
	stack_init(&s);

	return 0;
}

int clean_suite_stack(void) {
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


int stack_test() {
	CU_pSuite pSuite = NULL;

	if ( CUE_SUCCESS != CU_initialize_registry() )
		return CU_get_error();

	pSuite = CU_add_suite("Suite 1", init_suite_stack, clean_suite_stack);
	
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