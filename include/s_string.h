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
char* string_upper(char*);

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
char* string_lower(char*);

#endif // KANLIB_STRING