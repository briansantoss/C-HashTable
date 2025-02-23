#include "hash_table.h"
#include <ctype.h>
#include <stdio.h>

#define TAM 8

int main() {
  HashTable *hash_table = create_hash_table(TAM);

  if (hash_table == NULL) {
    fprintf(stderr, "Cannot create hash table");
    return 1;
  }

  printf("Hash table created successfully!\n");

  if (add_key_value(hash_table, "City", "Curitiba") == 0) {
    char *value = get_value(hash_table, "City");
    if (value != NULL) {
      printf("%s\n", value);
    }
  }

  // Trying to access a key that is not in the hash table
  if (get_value(hash_table, "nonexistent") == NULL) {
    printf("\nKey not present in the hash_table");
  }

  char input_key[50], input_value[50];
  printf("\n\nLet's create a new entry! Provide the key: ");
  scanf("%49s", input_key);

  printf("Now a value: ");
  scanf("%49s", input_value);

  if (add_key_value(hash_table, input_key, input_value) == 0) {
    char *value = get_value(hash_table, input_key);
    if (value != NULL) {
      printf("\nKey: %s\nValue: %s\n", input_key, value);
    }
  }

  return 0;
}
