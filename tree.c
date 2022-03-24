#include "stdio.h"
#include "stdlib.h"
#include "linkqueue.h"
bitree *bitree_creat(){
    data_t ch;
    bitree *t;
    scanf("%c", &ch);
    if(ch == '#')
        return NULL;
    t = (bitree *)malloc(sizeof(bitree));
    if(t == NULL){
        printf("malloc is failed\n");
        return NULL;
    }
    t->data = ch;
    t->left = bitree_creat();
    t->right = bitree_creat();
    return t;
}
void preorder(bitree *t){
    if(t == NULL)
        return;
    printf("%c", t->data);
    preorder(t->left);
    preorder(t->right);
}
void inorder(bitree *t){
    if(t == NULL)
        return;
    inorder(t->left);
    printf("%c", t->data);
    inorder(t->right);
}
void postorder(bitree *t){
    if(t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    printf("%c", t->data);
}
void layerorder(bitree *t){
    linkqueue_t *lq;
    lq = linkqueue_creat();
    if(lq == NULL)
        return;
    if(t == NULL)
        return;
    printf("%c", t->data);
    linkqueue_en(lq, t);
    while(!linkqueue_empty(lq)){
        t = linkqueue_out(lq);
        if(t->left){
            printf("%c", t->left->data);
            linkqueue_en(lq, t->left);
        }
        if(t->right){
            printf("%c", t->right->data);
            linkqueue_en(lq, t->right);
        }
    }
    puts("");
}