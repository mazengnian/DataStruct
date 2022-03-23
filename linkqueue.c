#include "stdlib.h"
#include "stdio.h"
#include "linkqueue.h"
linkqueue_t *linkqueue_creat(){
    linkqueue_t *lq;
    if((lq = (linknode_t *) malloc(sizeof (linkqueue_t))) == NULL){
        printf("malloc is null\n");
        return NULL;
    }
    lq->front = lq->rear = (linklist_t) malloc(sizeof (linknode_t));
    if(lq->rear == NULL){
        printf("malloc is null\n");
        return NULL;
    }
    lq->front->data = 0;
    lq->front->next = NULL;
    return lq;

}
int linkqueue_en(linkqueue_t *lq, data_t value){
    linklist_t p;
    if((p = (linklist_t) malloc(sizeof (linknode_t))) == NULL){
        printf("malloc is failed\n");
        return -1;
    }
    p->data = value;
    p->next = NULL;
    lq->rear->next = p;
    lq->rear = p;
    return 0;
}
data_t linkqueue_out(linkqueue_t *lq){
    linklist_t p;
    if((p = (linklist_t) malloc(sizeof (linknode_t))) == NULL){
        printf("malloc is failed\n");
        return -1;
    }
    p = lq->front;
    lq->front = p->next;
    free(p);
    return (lq->front->data);
}
int linkqueue_empty(linkqueue_t *lq){
    if(lq == NULL){
        printf("malloc is null\n");
        return -1;
    }
    return (lq->front == lq->rear ? 1:0);
}
int linkqueue_full(linkqueue_t *lq){

}
int linkqueue_clear(linkqueue_t *lq){
    linklist_t p;
    while(lq->front->next != NULL){
        p = lq->front->next;
        lq->front = p->next;
        free(p);
    }
    return 0;
}
linkqueue_t *linkqueue_free(linkqueue_t *lq){
    linklist_t p;
    if(lq == NULL){
        printf("malloc is null\n");
        return NULL;
    }
    while(lq->front != NULL){
        p = lq->front;
        lq->front = p->next;
        free(p);
    }
    return NULL;
}