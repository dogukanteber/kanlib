#include <CUnit/Basic.h>
#include "test.h"

#include "../include/dynamic_array.h"
#include <stdint.h>

static dynamic_array da;

int init_suite1(void) {
	dynamic_array_init(&da);

	return 0;
}

int clean_suite1(void) {
	dynamic_array_free(&da);

	return 0;
}

void test_add(void) {
	dynamic_array_add(&da, (int *) 10);
	dynamic_array_add(&da, (int *) 20);
	dynamic_array_add(&da, (int *) 30);

	CU_ASSERT( dynamic_array_size(&da) == 3 );
}

void test_get(void) {
	CU_ASSERT( (intptr_t) dynamic_array_get(&da, 0) == 10 );
	CU_ASSERT( (intptr_t) dynamic_array_get(&da, 1) == 20 );
	CU_ASSERT( (intptr_t) dynamic_array_get(&da, 2) == 30 );
}

void test_set(void) {
	dynamic_array_set(&da, 0, (int *) 100);
	dynamic_array_set(&da, 1, (int *) 200);
	dynamic_array_set(&da, 2, (int *) 300);

	CU_ASSERT( (intptr_t) dynamic_array_get(&da, 0) == 100 );
	CU_ASSERT( (intptr_t) dynamic_array_get(&da, 1) == 200 );
	CU_ASSERT( (intptr_t) dynamic_array_get(&da, 2) == 300 );
}

void test_delete(void) {
	dynamic_array_delete(&da, 0);
	dynamic_array_delete(&da, 1);

	CU_ASSERT( (intptr_t) dynamic_array_get(&da, 0) == 200 );
}

int dynamic_array_test(void) {
	CU_pSuite pSuite = NULL;

	if ( CUE_SUCCESS != CU_initialize_registry() )
		return CU_get_error();

	pSuite = CU_add_suite("Suite 1", init_suite1, clean_suite1);
	
	if ( pSuite == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ( CU_add_test(pSuite, "Test of dynamic_array_add()", test_add) == NULL ||
			CU_add_test(pSuite, "Test of dynamic_array_get()", test_get) == NULL ||
			CU_add_test(pSuite, "Test of dynamic_array_set()", test_set) == NULL ||
			CU_add_test(pSuite, "Test of dynamic_array_delete()", test_delete) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}