#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "hash.h"
hash_t *hash_creat(){
    hash_t *hs;
    hs = (hash_t *) malloc(sizeof(hash_t));
    if(hs == NULL){
        printf("malloc is failed\n");
        return NULL;
    }
    memset(hs, 0, sizeof(hash_t));
    return hs;
}
int hash_insert(hash_t *hs, data_t key){
    linklist_t p, q;

    if (hs == NULL) {
        printf("HT is NULL\n");
        return -1;
    }

    if ((p = (linklist_t)malloc(sizeof(linknode_t))) == NULL) {
        printf("malloc failed\n");
        return -1;
    }
    p->key = key;
    p->value = key % N;
    p->next = NULL;

    q = &(hs->data[key % N]);

    while (q->next && q->next->key < p->key ) {
        q = q->next;
    }

    p->next = q->next;
    q->next = p;

    return 0;
}
linklist_t hash_search(hash_t *hs, data_t key){
    linklist_t p;

    if (hs == NULL) {
        printf("HT is NULL\n");
        return NULL;
    }

    p = &(hs->data[key % N]);

    while (p->next && p->next->key != key) {
        p = p->next;
    }

    if (p->next == NULL) {
        return NULL;
    } else {
        printf("found\n");
        return p->next;
    }
}