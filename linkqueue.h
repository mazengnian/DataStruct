typedef int data_t;
typedef struct node_t{
    data_t data;
    struct node_t *next;
}linknode_t, *linklist_t;
typedef struct {
    linklist_t front;
    linklist_t rear;

}linkqueue_t;
linkqueue_t *linkqueue_creat();
int linkqueue_en(linkqueue_t *lq, data_t value);
data_t linkqueue_out(linkqueue_t *lq);
int linkqueue_empty(linkqueue_t *lq);
int linkqueue_full(linkqueue_t *lq);
int linkqueue_clear(linkqueue_t *lq);
linkqueue_t *linkqueue_free(linkqueue_t *lq);
