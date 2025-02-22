#ifndef HASHTABLE_H

#include <stdlib.h>
#include <stdbool.h>

typedef union {
  char* string_val;
  int* int_val;
  float* float_val;
  double* double_val;
  bool* bool_val;
} DictValue;

typedef enum {
  STRING_TYPE,
  INT_TYPE,
  FLOAT_TYPE,
  DOUBLE_TYPE,
  BOOL_TYPE
} DictValueType;

typedef struct {
  char* key;
  DictValue value;
  DictValueType value_type;
} DictItem;

typedef struct ListNode {
  DictItem dict;
  struct ListNode* next;
} ListNode;

typedef struct {
  ListNode* items;
  size_t size;
} HashTable;

HashTable* create_hash_table(size_t size);

#endif
