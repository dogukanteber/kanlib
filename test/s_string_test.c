#include <stdlib.h>
#include <CUnit/Basic.h>
#include <kanlib/s_string.h>

#include "test.h"


int init_suite_s_string(void) {
	return 0;
}

int clean_suite_s_string(void) {
	return 0;
}

void test_string_split(void) {
    char sentence[] = "Lorem ipsum sit amet.";
    char delim[] = " ";
    char** splitted = string_split(sentence, delim);
    CU_ASSERT_STRING_EQUAL("Lorem", splitted[0]);
    CU_ASSERT_STRING_EQUAL("ipsum", splitted[1]);
    CU_ASSERT_STRING_EQUAL("sit", splitted[2]);
    CU_ASSERT_STRING_EQUAL("amet.", splitted[3]);
}

void test_string_reverse(void) {
    char str1[] = "reverse";
    CU_ASSERT_STRING_EQUAL("esrever", string_reverse(str1));

    char str2[] = "";
    CU_ASSERT_STRING_EQUAL("", string_reverse(""));

    char str3[] = "a";
    CU_ASSERT_STRING_EQUAL("a", string_reverse("a"));

    char str4[] = "Hello, World!";
    CU_ASSERT_STRING_EQUAL("!dlroW ,olleH", string_reverse(str4));
}

void test_string_upper(void) {
    char str1[] = "aaa";
    CU_ASSERT_STRING_EQUAL("AAA", string_upper(str1));

    char str2[] = "This is a sentence.";
    CU_ASSERT_STRING_EQUAL("THIS IS A SENTENCE.", string_upper(str2));

    char str3[] = "";
    CU_ASSERT_STRING_EQUAL("", string_upper(str3));

    char str4[] = "A";
    CU_ASSERT_STRING_EQUAL("A", string_upper(str4));
}

void test_string_lower(void) {
    char str1[] = "AAAA";
    CU_ASSERT_STRING_EQUAL("aaaa", string_lower(str1));

    char str2[] = "This is also a sentence.";
    CU_ASSERT_STRING_EQUAL("this is also a sentence.", string_lower(str2));

    char str3[] = "A";
    CU_ASSERT_STRING_EQUAL("a", string_lower(str3));

    char str4[] = "";
    CU_ASSERT_STRING_EQUAL("", string_lower(str4));
}

void test_string_starts_with(void) {
    char* string_one = "hello, world";
    char* sub_string = "hel";
    CU_ASSERT_EQUAL(1, string_starts_with(string_one, sub_string));
    CU_ASSERT_EQUAL(0, string_starts_with(string_one, "rld"));

    char* string_two = "test starts with function";
    char* sub_string_two = "test";
    CU_ASSERT_EQUAL(1, string_starts_with(string_two, sub_string_two));
}

void test_string_ends_with(void) {
    char* string_one = "hello, world";
    char* sub_string = "rld";
    CU_ASSERT_EQUAL(1, string_starts_with(string_one, sub_string));
    CU_ASSERT_EQUAL(0, string_starts_with(string_one, "he"));

    char* string_two = "test starts with function";
    char* sub_string_two = "ction";
    CU_ASSERT_EQUAL(1, string_starts_with(string_two, sub_string_two));
}


void test_string_concatenate(void) {
    CU_ASSERT_EQUAL("hello, world", string_concatenate("hello, ", "world"));

    CU_ASSERT_EQUAL("", string_concatenate("", ""));
    CU_ASSERT_EQUAL("hello", string_concatenate("hello", ""));
    CU_ASSERT_EQUAL("hello", string_concatenate("", "hello"));
}

int s_string_test(void) {
	CU_pSuite pSuite = NULL;

	if ( CUE_SUCCESS != CU_initialize_registry() )
		return CU_get_error();

	pSuite = CU_add_suite("Suite 1", init_suite_s_string, clean_suite_s_string);
	
	if ( pSuite == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ( CU_add_test(pSuite, "Test of string_split()", test_string_split) == NULL ||
			CU_add_test(pSuite, "Test of string_reverse()", test_string_reverse) == NULL ||
			CU_add_test(pSuite, "Test of string_upper()", test_string_upper) == NULL ||
			CU_add_test(pSuite, "Test of string_lower()", test_string_lower) == NULL ||
			CU_add_test(pSuite, "Test of string_starts_with()", test_string_starts_with) == NULL ||
			CU_add_test(pSuite, "Test of string_ends_with()", test_string_ends_with) == NULL ||
			CU_add_test(pSuite, "Test of string_concatenate()", test_string_concatenate) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
