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

int main(int argc, char const *argv[]) {
    char string[] = "hello world this is my string library.";
    char** splitted = string_split(string, " ");

    for ( size_t i=0; splitted[i] != NULL; ++i ) {
        printf("%s\n", splitted[i]);   
    }

    char lower[] = "lowercase string, right?";
    printf("%s\n", string_upper(lower));
    printf("%s\n", string_lower(lower));
    
    char* reversed = string_reverse(lower);

    printf("%s\n", reversed);

    printf("%s\n", lower);
    printf("%s\n", string);

    free(splitted);
    free(reversed);

    return 0;
}
