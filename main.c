
//#include "sqlist.h"
#include "stdio.h"
#include "linklist.h"
void test_list_adjacent_max();
void test_linklist_reverse();
void test_linklist_delete_pos();
void test_linklist_free_insert();
void test_linklist_get();
void test_linklist_free();
void test_linklist_merge();
int main(int argc, const char *argv[]){
    //test_list_adjacent_max();
    //test_linklist_reverse();
    //test_linklist_delete_pos();
    //test_linklist_free_insert();
    //test_linklist_get();
    //test_linklist_merge();
    test_linklist_free();
    return 0;
}
void test_list_adjacent_max(){
    linklist H, r;
    int value, sum;
    H = linklist_creat();
    if(H == NULL){
        return;
    }
    printf("input:");
    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        linklist_tail_insert(H, value);
        printf("input:");
    }
    linklist_show(H);
    r = linklist_adjacent_max(H, &sum);
    if(r != NULL && r != H){
        printf("%d, %d", r->data, sum);
    }
    linklist_show(H);
}
void test_linklist_reverse(){
    linklist H;
    int value;
    H = linklist_creat();
    if(H == NULL){
        return;
    }
    printf("input:");
    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        linklist_tail_insert(H, value);
        printf("input:");
    }
    linklist_show(H);
    linklist_reverse(H);
    linklist_show(H);
}
void test_linklist_delete_pos(){
    linklist H;
    int value;
    H = linklist_creat();
    if(H == NULL){
        return;
    }
    printf("input:");
    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        linklist_tail_insert(H, value);
        printf("input:");
    }
    linklist_show(H);
    linklist_delete_pos(H, 2);
    linklist_show(H);
}
void test_linklist_free_insert(){
    linklist H;
    int value;
    H = linklist_creat();
    if(H == NULL){
        return;
    }
    printf("input:");
    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        linklist_tail_insert(H, value);
        printf("input:");
    }
    linklist_show(H);
    linklist_free_insert(H, 5,3);
    linklist_show(H);
}
void test_linklist_get(){
    linklist H, r;
    int value;
    H = linklist_creat();
    if(H == NULL){
        return;
    }
    printf("input:");
    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        linklist_tail_insert(H, value);
        printf("input:");
    }
    linklist_show(H);
    r = linklist_get(H ,2);
    linklist_show(r);
}
void test_linklist_free(){
    linklist H, r;
    int value;
    H = linklist_creat();
    if(H == NULL){
        return;
    }
    printf("input:");
    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        linklist_tail_insert(H, value);
        printf("input:");
    }
    linklist_show(H);
    linklist_free(H);

}
void test_linklist_merge(){
    linklist H1, H2;
    int value;
    H1 = linklist_creat();
    H2 = linklist_creat();
    if(H1 == NULL){
        return;
    }
    printf("input:");
    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        linklist_tail_insert(H1, value);
        printf("input:");
    }
    printf("input:");
    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        linklist_tail_insert(H2, value);
        printf("input:");
    }
    linklist_show(H1);
    linklist_show(H2);

}
