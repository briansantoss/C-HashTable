#include <stdio.h>
#include "hash_table.h"

#define TAM 8

int main() {
  HashTable* hash_table = create_hash_table(TAM);

  if (hash_table == NULL) {
    fprintf(stderr, "Cannot create hash table");
    return -1;
  }

  printf("Hash table created successfully!");

  return 0;
}
