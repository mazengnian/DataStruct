typedef char data_t;
typedef struct node_t{
    data_t data;
    struct node_t *left;
    struct node_t *right;
}bitree;
bitree *bitree_creat();
void preorder(bitree *t);
void inorder(bitree *t);
void postorder(bitree *t);
void layerorder(bitree *t);