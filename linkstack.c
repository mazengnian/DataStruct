#include "linkstack.h"
#include "stdlib.h"
#include "stdio.h"
linkstack link_stack_creat(){
    linkstack s;
    s = (linkstack) malloc(sizeof (linkstack));
    if(s == NULL){
        printf("Malloc is failed\n");
        return NULL;
    }
    s->data = 0;
    s->next = NULL;
    return s;
}
int link_stack_push(linkstack s, data_t value){
    linkstack p;
    if(s == NULL){
        printf("S is NULL\n");
        return -1;
    }
    p = (linkstack) malloc(sizeof (linkstack));
    if(p == NULL){
        printf("Malloc is failed\n");
        return -1;
    }
    p->data = value;
    p->next = s->next;
    s->next = p;
    return 0;

}
data_t link_stack_pop(linkstack s){
    linkstack p;
    data_t t;
    if(s == NULL){
        printf("S is NULL\n");
        return -1;
    }
    p = (linkstack) malloc(sizeof (linkstack));
    if(p == NULL){
        printf("Malloc is failed\n");
        return -1;
    }
    p = s->next;
    s->next = p->next;
    t = p->data;
    free(p);
    p = NULL;
    return t;
}
int link_stack_empty(linkstack s){
    return (s->next == NULL ? 1 : 0);
}
data_t link_stack_top(linkstack s){
    return (s->next->data);
}
linkstack link_stack_free(linkstack s){
    linkstack p;
    if(s == NULL){
        printf("s is null\n");
        return NULL;
    }
    while(s != NULL){
        p = s;
        s = s->next;
        printf("free:%d\n", p->data);
        free(p);
    }
    return NULL;
}