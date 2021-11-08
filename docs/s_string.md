### API

#### WARNING

<b>All the string functions below are operated on character arrays or allocated strings. Strings that are allocated on stack cause segmentation fault errors. Therefore, when using the below functions, create your strings like these:</b>

*   char my_string[] = "hello, my_string";
*   char another_string[100];
*   char* allocated_string = malloc(sizeof(char) * 100);

```c
char** string_split(char* string, char* delimeter);
```

Splits the given string with the given delimeter and returns array of splitted strings. Returned array ends with NULL pointer. The function mutates the string. The caller of this function must free the variable after s/he is done.

```c
char* string_reverse(const char* string);
```

Reverses the given strings and returns the reversed string. The function does not mutate the string. However, it allocates memory. Therefore, the caller must free the allocated memory.

```c
char* string_upper(char* string);
```

Converts each character to uppercase and returns. The function mutates the given string.

```c
int string_starts_with(const char* string, const char* sub_string);
```

Checks if the given string starts with sub_string. If so, returns 1. Otherwise, 0.

```c
int string_ends_with(const char* string, const char* sub_string);
```

Checks if the given string ends with sub_string. If so, returns 1. Otherwise, 0.

```c
char* string_concatenate(const char* string_one, const char* string_two);
```

Merges two strings and returns the merged string. The given strings are not mutated. The caller of the function must free the allocated memory.