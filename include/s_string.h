/**
*	@file           s_string.h
*	@author 		Doğukan Teber
*	@date 			19/09/2021
*
*
*	@brief Header file for common string functionalities. 
*       The name s_string.h is given so that it does not 
*       collapse with standard string library.
*/

#ifndef KANLIB_STRING
#define KANLIB_STRING

/**
*	@brief Splits the given string
*
*	@param char* string (splitted string)
*
*   @param char* delimeter
*
*	@returns char** of splitted strings
*
*   @note The function CHANGES the actual string that is passed as splitted_string.
*
*	@attention The caller of this function have to keep the returned value in a variable and after done using it, s/he must free the memory.
*
*/
char** string_split(char*, char*);

/**
*	@brief Reverses the given string
*
*	@param const char* string
*
*	@returns Reversed string (char*)
*
*	@attention The caller of this function have to keep the returned value in a variable and after done using it, s/he must free the memory.
*
*/
char* string_reverse(const char*);

/**
*	@brief Convert each character to uppercase
*
*	@param char* string
*
*	@returns String containing uppercase characters. 
*
*   @note The function mutates the given parameter.
*
*	@attention The caller of this function have to keep the returned value in a variable and after done using it, s/he must free the memory.
*
*/
char* string_upper(char*); // review

/**
*	@brief Convert each character to lowercase
*
*	@param char* string
*
*	@returns String containing lowercase characters. 
*
*   @note The function mutates the given parameter.
*
*	@attention The caller of this function have to keep the returned value in a variable and after done using it, s/he must free the memory.
*
*/
char* string_lower(char*); // review

/**
*	@brief Checks if the given string starts with the given prefix
*
*	@param const char* string
*   @param const char* prefix
*
*	@returns Returns 1 if the string starts with the prefix, 0 otherwise
*
*/
int string_starts_with(const char*, const char*);

/**
*	@brief Checks if the given string ends with the given postfix
*
*	@param const char* string
*   @param const char* postfix
*
*	@returns Returns 1 if the string ends with the postfix, 0 otherwise
*
*/
int string_ends_with(const char*, const char*);


/**
*	@brief Concatenates the given two strings and returns the newly created one.
*
*	@param const char* string1
*   @param const char* string2
*
*   @note The function dynamically allocates the concatenated string. Therefore, it is developer's responsibility to free the allocated resource
*
*	@returns Returns merged string1 and string2
*
*/
char* string_concatenate(const char*, const char*);

#endif // KANLIB_STRING