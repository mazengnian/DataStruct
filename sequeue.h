typedef int data_t;
#define N 100
typedef struct {
    data_t data[N];
    int front, rear;
}sequeue;
sequeue *sequeue_creat();
int sequeue_en(sequeue *sq, int value);
int sequeue_out(sequeue *sq);
int sequeue_full(sequeue *sq);
int sequeue_empty(sequeue *sq);
int sequeue_clear(sequeue *sq);
sequeue *sequeue_free(sequeue *sq);
