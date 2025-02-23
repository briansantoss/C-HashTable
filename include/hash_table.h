#ifndef HASHTABLE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct ListNode {
  char *key;
  char *value;
  struct ListNode *next;
} ListNode;

typedef struct {
  ListNode **items;
  size_t size;
} HashTable;

HashTable *create_hash_table(size_t size);
int add_key_value(HashTable *hash_table, char *key, char *value);
char *get_value(HashTable *hash_table, char *key);
void free_hash_table(HashTable *hash_table);

#endif
