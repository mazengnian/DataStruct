#include "tree.h"
typedef bitree * datatype;
typedef struct node{
    datatype data;
    struct node *next;
}linknode_t, *linklist_t;
typedef struct {
    linklist_t front;
    linklist_t rear;

}linkqueue_t;
linkqueue_t *linkqueue_creat();
int linkqueue_en(linkqueue_t *lq, datatype value);
datatype linkqueue_out(linkqueue_t *lq);
int linkqueue_empty(linkqueue_t *lq);
int linkqueue_full(linkqueue_t *lq);
int linkqueue_clear(linkqueue_t *lq);
linkqueue_t *linkqueue_free(linkqueue_t *lq);
