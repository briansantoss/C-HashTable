#include "hash_table.h"

HashTable* create_hash_table(size_t size) {
  HashTable* hash_table = malloc(sizeof (HashTable));
  if (hash_table == NULL) {
    return NULL;
  }

  hash_table->items = malloc(sizeof (ListNode) * size);
  if (hash_table->items == NULL) {
    return NULL;
  }

  // Initializing each hash table head to point to nothing (NULL)
  for (size_t i = 0; i < size; i++) {
    hash_table->items[i].next = NULL;
  }

  hash_table->size = size;

  return hash_table;
}
