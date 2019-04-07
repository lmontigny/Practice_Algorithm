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
    while(ht[index].value != 0 && ht[index].key != -1)
    {
        /* Key not present */
        /* if(!ht[index].value) { */
        /*     ht[index].key = key; */
        /*     ht[index].value = 1; */
        /*     return; */
        /* } */
        /* /1* Key already present *1/ */
        /* else if(ht[index].key = key){ */
        /*     ht[index].value++; */
        /*     return */
        /* } */
        index = (index+1) % ht_size;
    }
    ht[index].key = key;
    ht[index].value = 1;
    /* printf("Htable full"); */
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
