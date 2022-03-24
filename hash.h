typedef int data_t;
#define N 15
typedef struct node_t {
    data_t value, key;
    struct node_t *next;
}linknode_t, *linklist_t;
typedef struct {
    linknode_t data[15];
}hash_t;
hash_t *hash_creat();
int hash_insert(hash_t *hs, data_t key);
linklist_t hash_search(hash_t *hs, data_t key);