#ifndef KANLIB_HASH_TABLE
#define KANLIB_HASH_TABLE 1

#define HASH_TABLE_SIZE 10

typedef struct ht_node ht_node;

struct ht_node{
    char* key;
    int value;
    ht_node* next;
};

typedef struct {
    ht_node* arr[HASH_TABLE_SIZE];
} hash_table;


void hash_table_init(hash_table*);
void hash_table_print(hash_table*);
ht_node* create_hash_node(char*, int);
unsigned long hash(unsigned char*);
void hash_table_put(hash_table*, char*, int);
int hash_table_get(hash_table*, char*);
void hash_table_delete(hash_table*, char*);
void hash_table_free(hash_table*);


#endif // KANLIB_HASH_TABLE