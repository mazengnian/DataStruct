
//#include "sqlist.h"
#include "stdio.h"
#include "linkstack.h"

int main(int argc, const char *argv[]){
    linkstack s;
    s = link_stack_creat();
    if(s == NULL){
        return -1;
    }
    link_stack_push(s,10);
    link_stack_push(s,20);
    link_stack_push(s,30);
    printf("Stack Top is %d", link_stack_top(s));
    while(link_stack_empty(s) != 1){
        printf("POP:%d ", link_stack_pop(s));
    }
    s = link_stack_free(s);
    return 0;
}
