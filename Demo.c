#include "linklist.h"
//#include "sqlist.h"
#include "stdio.h"


int main(int argc, const char *argv[]){
    linklist H;
    int value;
    H = linklist_creat();
    if(H == NULL){
        return -1;
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
    return 0;
}
