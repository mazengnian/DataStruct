#include "stdio.h"

#include "linkqueue.h"
/*int main(int argc, const char *argv[]){
    bitree *t;
    t = bitree_creat();
    preorder(t);
    puts("");
    inorder(t);
    puts("");
    postorder(t);
    puts("");
    return 0;
}*/
int main(int argc, const char *argv[]){
    bitree *t;
    t = bitree_creat();
    preorder(t);
    puts("");
    inorder(t);
    puts("");
    postorder(t);
    puts("");
    layerorder(t);
    return 0;
}