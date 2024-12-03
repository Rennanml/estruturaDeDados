#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int is_occupied;
} HashItem;

HashItem hashTable[TABLE_SIZE];

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].is_occupied = 0;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash(key);
    int originalIndex = index;
    
    while (hashTable[index].is_occupied == 1) {
        if (hashTable[index].key == key) {
            printf("Chave %d ja esta na tabela.\n", key);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Tabela cheia! Nao e possivel inserir a chave %d.\n", key);
            return;
        }
    }
    
    hashTable[index].key = key;
    hashTable[index].is_occupied = 1;
    printf("Chave %d inserida na tabela na posicao %d.\n", key, index);
}

void removeItem(int key) {
    int index = hash(key);
    int originalIndex = index;
    
    while (hashTable[index].is_occupied == 1) {
        if (hashTable[index].key == key) {
            hashTable[index].is_occupied = 0;
            printf("Chave %d removida da tabela.\n", key);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            break;
        }
    }
    
    printf("Chave %d nao encontrada na tabela.\n", key);
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].is_occupied) {
            printf("Posicao %d: Chave %d\n", i, hashTable[i].key);
        } else {
            printf("Posicao %d: Vazio\n", i);
        }
    }
}

int main() {
    initializeHashTable();

    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);
    
    displayHashTable();

    removeItem(20);
    displayHashTable();

    insert(20);
    displayHashTable();

    return 0;
}
