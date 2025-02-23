#include "hash_table.h"
#include <stdio.h>
#include <string.h>

// Returns NULL in case of error, otherwise returns a pointer to dynamically
// allocated hash table
HashTable *create_hash_table(size_t size) {
  HashTable *hash_table = malloc(sizeof(HashTable));
  if (hash_table == NULL) {
    return NULL;
  }

  hash_table->items = malloc(sizeof(ListNode *) * size);
  if (hash_table->items == NULL) {
    free(hash_table); // In case of fail for items allocation, free the memory
                      // in use by the hash_table
    return NULL;
  }

  // Initializing each hash table head with NULL
  for (size_t i = 0; i < size; i++) {
    hash_table->items[i] = NULL;
  }

  hash_table->size = size;

  return hash_table;
}

size_t djb2_hash(size_t size, char *key) {
  unsigned long hash = 5381;
  for (size_t i = 0; key[i] != '\0'; i++) {
    hash = (hash << 5) + hash + key[i];
  }

  return hash % size;
}

// Returns 1 in case of erorr, else 0
int add_key_value(HashTable *hash_table, char *key, char *value) {
  if (hash_table == NULL || key == NULL || value == NULL) {
    return 1;
  }

  ListNode *new_node = malloc(sizeof(ListNode));
  if (new_node == NULL) {
    return 1;
  }

  size_t index = djb2_hash(hash_table->size, key);

  new_node->key = malloc(strlen(key) + 1);
  if (new_node->key == NULL) {
    free(new_node);
    return 1;
  }
  strcpy(new_node->key, key); // Creating a copy of the key

  new_node->value = malloc(strlen(value) + 1);
  if (new_node->value == NULL) {
    free(new_node->key);
    free(new_node);
    return 1;
  }
  strcpy(new_node->value, value); // Creating a copy of the value

  // Occurs when there is no collision
  if (hash_table->items[index] == NULL) {
    new_node->next = NULL;
    hash_table->items[index] = new_node;
    return 0;
  }

  ListNode *current = hash_table->items[index];
  while (current->next != NULL) {
    if (strcmp(current->key, key) == 0) {
      return 1;
    }
    current = current->next;
  }

  // Appending the new node
  current->next = new_node;
  new_node->next = NULL;

  return 0;
}

// Return NULL if the key is not found or other error, otherwise, returns the
// associated value
char *get_value(HashTable *hash_table, char *key) {
  if (hash_table == NULL || key == NULL) {
    return NULL;
  }

  // Getting where the key is supposed to be
  int index = djb2_hash(hash_table->size, key);

  ListNode *current = hash_table->items[index];
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      return current->value;
    }
    current = current->next;
  }
  return NULL;
}
