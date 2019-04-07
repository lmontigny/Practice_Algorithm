#include <stdio.h>

#define HASH_SIZE 10

struct hashTable
{
    int key;
    double value;
};

struct hashTable ht[HASH_SIZE];

void initHashTable(struct hashTable ht[], int ht_size)
{
    int i;
    for(i=0; i<ht_size; i++){
        ht[i].key = -1;
        ht[i].value = 0.;
    }
}

void printHashTable(struct hashTable ht[], int ht_size)
{
    int i;
    for(i=0; i<ht_size; i++){
        if(ht[i].value)
            printf("Htable key %d, value %f, index %d \n", ht[i].key, ht[i].value, i);
    }
}

void insert(struct hashTable ht[], int ht_size, int key)
{
    int index = key % ht_size;
    int i = index;
    while(i<ht_size)
    {
        /* Key not present */
        if(!ht[i].value) {
            ht[i].key = key;
            ht[i].value = 1;
            return;
        }
        /* Key already present */
        else if(ht[i].key = key){
            ht[i].value++;
            return;
        }
        /* Linear probing */
        i = (i+1) % ht_size;
    }
    printf("Htable full");
    return;
}

// Search position without ht_size limit
void insertSimplified(struct hashTable ht[], int ht_size, int key)
{
    int index = key % ht_size;
    while(ht[index].value != 0 && ht[index].key != -1)
    {
        index = (index+1) % ht_size;
    }
    ht[index].key = key;
    ht[index].value = 1;
    return;
}

int hashIndex(int index, int hash_table_size)
{
    return index%hash_table_size;
}

int main()
{
    int ht_size = HASH_SIZE;

    initHashTable(ht, ht_size);

    int key = 99;
    insert(ht, ht_size, key);
    insert(ht, ht_size, key);

    printHashTable(ht, ht_size);

    return 0;
}
