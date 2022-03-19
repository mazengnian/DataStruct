#define N 256
typedef int data_t;
/*typedef struct sqlist_t sqlist;
typedef struct sqlist_t *sqlink;*/
typedef struct{
    data_t data[N];
    int last;
}sqlist, *sqlink;

sqlink list_creat();
int list_clear(sqlink L);
int list_empty(sqlink L);
int list_length(sqlink L);
int list_locate(sqlink L, data_t value);
int list_insert(sqlink L, data_t value, int pos);
int list_show(sqlink L);
int list_delete(sqlink L);
int list_merge(sqlink L1, sqlink L2);
int list_delete_pos(sqlink L, int pos);
int list_purge(sqlink L);
