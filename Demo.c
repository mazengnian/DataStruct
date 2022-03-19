//#include "linklist.h"
#include "sqlist.h"
#include "stdio.h"
void test_insert();
void test_delete();
void test_merge();
void test_purge();
int main(int argc, const char *argv[]){
    //test_insert();
    //test_delete();
    //test_merge();
    test_purge();
    return 0;
}
void test_insert(){
    sqlink L;

    L = list_creat();
    if (L == NULL)
        return;
    list_insert(L, 10, 0);
    list_insert(L, 20, 0);
    list_insert(L, 30, 0);
    list_insert(L, 40, 0);
    list_insert(L, 50, 0);
    list_insert(L, 60, 0);

    list_show(L);
    list_insert(L, 100, -1000);
    list_show(L);
    list_delete(L);
}
void test_delete(){
    sqlink L;

    L = list_creat();
    if (L == NULL)
        return;
    list_insert(L, 10, 0);
    list_insert(L, 20, 0);
    list_insert(L, 30, 0);
    list_insert(L, 40, 0);
    list_insert(L, 50, 0);
    list_insert(L, 60, 0);
    list_show(L);
    list_delete_pos(L, 9);
    list_show(L);
    list_delete(L);
}
void test_merge(){
    sqlink L1, L2;

    L1 = list_creat();
    if (L1 == NULL)
        return;

    L2 = list_creat();
    if (L2 == NULL)
        return;

    list_insert(L1, 10, 0);
    list_insert(L1, 20, 0);
    list_insert(L1, 30, 0);
    list_insert(L1, 40, 0);

    list_insert(L2, 50, 0);
    list_insert(L2, 20, 0);
    list_insert(L2, 90, 0);
    list_insert(L2, 40, 0);

    list_show(L1);
    list_show(L2);
    printf("********************\n");
    list_merge(L1, L2);
    list_show(L1);
    list_show(L2);
}
void test_purge(){
    sqlink L;

    L = list_creat();
    if (L == NULL)
        return;

    list_insert(L, 10, 0);
    list_insert(L, 10, 0);
    list_insert(L, 10, 0);
    list_insert(L, 10, 0);
    list_insert(L, 10, 0);
    list_insert(L, 10, 0);

    list_show(L);
    list_purge(L);
    list_show(L);

    list_delete(L);
}