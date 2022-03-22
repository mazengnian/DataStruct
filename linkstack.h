typedef int data_t;
typedef struct node_t{
    data_t data;
    struct node_t *next;
}listnode,*linkstack;
linkstack link_stack_creat();
int link_stack_push(linkstack s, data_t value);
data_t link_stack_pop(linkstack s);
int link_stack_empty(linkstack s);
data_t link_stack_top(linkstack s);
linkstack link_stack_free(linkstack s);
