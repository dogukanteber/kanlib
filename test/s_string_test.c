#include <CUnit/Basic.h>

#include "test.h"
#include "../include/s_string.h"

int init_suite1(void) {
	return 0;
}

int clean_suite1(void) {
	return 0;
}

void test_string_split(void) {
    
}

void test_string_reverse(void) {
    char str1[] = "reverse";
    CU_ASSERT_STRING_EQUAL("esrever", string_reverse(str1));

    char str2[] = "";
    CU_ASSERT_STRING_EQUAL("", string_reverse(""));

    char str3[] = "a";
    CU_ASSERT_STRING_EQUAL("a", string_reverse("a"));

    char str4[] = "Hello, World!";
    CU_ASSERT_STRING("!dlroW ,olleH", string_reverse(str4));
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