#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "../include/hash_table.h"



void hash_table_init(hash_table* ht) {
    for ( int i=0; i<HASH_TABLE_SIZE; ++i ) {
        ht->arr[i] = NULL;
    }
}

void hash_table_print(hash_table* ht) {
    for ( int i=0; i<HASH_TABLE_SIZE; ++i ) {
        if ( ht->arr[i] == NULL )
            printf("\t%i\t---\t---\t---\n", i);
        else {
            ht_node* temp = ht->arr[i];
            while ( temp != NULL ) {
                printf("\t%d\tkey:%s\tvalue:%d ---", i, temp->key, temp->value);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

ht_node* create_hash_node(char* key, int value) {
    ht_node* new = malloc( sizeof(ht_node) );
    new->key = key;
    new->value = value;
    new->next = NULL;

    return new;
}

unsigned long hash(unsigned char* str) {
    unsigned long hash = 5381;
    int c;

    while ( c = *str++ ) {
        hash = ( (hash << 5) + hash ) +c;
    }

    return hash % HASH_TABLE_SIZE;
}

void hash_table_put(hash_table* ht, char* key, int value) {
    ht_node* node = create_hash_node(key, value);
    int c = hash(key);

    if ( ht->arr[c] == NULL ) {
        ht->arr[c] = node;          
    }
    else {
        node->next = ht->arr[c];
        ht->arr[c] = node;
    }
}

int hash_table_get(hash_table* ht, char* key) {
    int c = hash(key);

    ht_node* curr = ht->arr[c];
    while ( curr != NULL ) {
        if ( strcmp(curr->key, key) == 0 )
            return curr->value;
        curr = curr->next;
    }
    printf("%s\n","Requested key-value pair is not on the hash table.");
    return INT_MIN;
}

void hash_table_delete(hash_table* ht, char* key) {
    int c = hash(key);

    ht_node* deleted = ht->arr[c];

    // remove if there is no chain
    if ( deleted->next == NULL ) {
        free(deleted);
        ht->arr[c] = NULL;
        return;
    }
    else {
        // removing first element of the chain
        if ( strcmp(deleted->key, key) == 0 ) {
            ht->arr[c] = deleted->next;
            free(deleted);
            deleted = NULL;
            return;
        }
        else {
            ht_node* temp = deleted;
            while( deleted->next != NULL ) {
                deleted = deleted->next;
                if ( strcmp(deleted->key, key) == 0 ) {
                    temp->next = deleted->next;
                    free(deleted);
                    deleted = NULL;
                    return;
                }
                temp = deleted;
            }
        }
    }
    printf("%s\n", "Requested key is not present.");
}

void hash_table_free(hash_table* ht) {
    for ( int i=0; i<HASH_TABLE_SIZE; ++i ) {
        ht_node* temp = ht->arr[i];
        while ( temp != NULL ) {
            ht_node* temp_list = temp;
            temp = temp->next;
            free(temp_list);
        }
        ht->arr[i] = NULL;
    }
}