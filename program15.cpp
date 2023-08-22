#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct HashEntry {
    int key;
    int value;
};
struct HashTable {
    struct HashEntry table[TABLE_SIZE];
};
void initializeHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i].key = -1;
    }
}
int hashFunction(int key) {
    return key % TABLE_SIZE;
}
void insert(struct HashTable* ht, int key, int value) {
    int index = hashFunction(key);
    while (ht->table[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    ht->table[index].key = key;
    ht->table[index].value = value;
}
int search(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    while (ht->table[index].key != -1) {
        if (ht->table[index].key == key) {
            return ht->table[index].value; // Return value if key is found
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }
    return -1; // Return -1 if key is not found
}
int main() {
    struct HashTable ht;
    initializeHashTable(&ht);
    insert(&ht, 5, 50);
    insert(&ht, 15, 150);
    insert(&ht, 25, 250);
    insert(&ht, 35, 350);
    int searchKey = 25;
    int result = search(&ht, searchKey);
    if (result != -1) {
        printf("Value for key %d: %d\n", searchKey, result);
    } else {
        printf("Key %d not found.\n", searchKey);
    }
    return 0;
}
