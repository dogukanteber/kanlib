#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "../include/s_string.h"

char** string_split(char* string, char* delimeter) {
    size_t buffer_len = 32;
    size_t pos = 0;

    char** tokens = malloc(sizeof(char*) * buffer_len);
    
    assert(tokens != NULL);

    char* token = strtok(string, delimeter);
    while ( token != NULL ) {
        tokens[pos] = token;
        pos++;

        if ( pos >= buffer_len ) {
            buffer_len *= 2;
            tokens = realloc(tokens, sizeof(char*) * buffer_len);

            assert(tokens != NULL);
        }
        token = strtok(NULL, delimeter);
    }
    tokens[pos] = NULL;

    return tokens;
}

char* string_reverse(const char* string) {
    size_t len = strlen(string);
    char* reversed_string = malloc(sizeof(char) * len);

    size_t i = len-1;
    size_t ri = 0;
    while ( ri <= len ) {
        reversed_string[ri++] = string[i--];
    }

    return reversed_string;
}

char* string_upper(char* string) {
    for ( size_t i=0; i<strlen(string); ++i ) {
        string[i] = toupper(string[i]);
    }

    return string;
}

char* string_lower(char* string) {
    for ( size_t i=0; i<strlen(string); ++i ) {
        string[i] = tolower(string[i]);
    }

    return string;
}

int string_starts_with(const char* string, const char* prefix) {
    size_t len_string = strlen(string);
    size_t len_prefix = strlen(prefix);

    if ( len_prefix > len_string )
        return 0;

    for ( size_t i=0; i<len_prefix; ++i ) {
        if ( string[i] != prefix[i] )
            return 0;
    }
    
    return 1;
}

int string_ends_with(const char* string, const char* prefix) {
    size_t len_string = strlen(string);
    size_t len_prefix = strlen(prefix);

    if ( len_prefix > len_string )
        return 0;

    size_t runner_string = len_string - len_prefix;
    size_t runner_prefix = 0;
    while ( runner_prefix < len_prefix ) {
        if ( string[runner_string] != prefix[runner_prefix] )
            return 0;

        runner_prefix++;
        runner_string++;
    }

    return 1;
}