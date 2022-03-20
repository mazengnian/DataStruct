typedef int data_t;
typedef struct node{
    data_t data;
    struct node *next;
}listnode, *linklist;
linklist linklist_creat();
int linklist_tail_insert(linklist H, data_t value);//尾部插入
linklist linklist_get(linklist H, int pos);
int linklist_free_insert(linklist H, data_t value, int pos);
int linklist_show(linklist H);
int linklist_delete_pos(linklist H, int pos);
linklist linklist_free(linklist H);

