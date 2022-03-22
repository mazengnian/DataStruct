
//#include "sqlist.h"
#include "stdio.h"
#include "sequeue.h"

int main(int argc, const char *argv[]){
    sequeue *sq;
    sq = sequeue_creat();
    sequeue_en(sq, 5);
    sequeue_en(sq, 7);
    sequeue_en(sq, 6);
    while(!sequeue_empty(sq)){
        printf("Out：%d", sequeue_out(sq));
    }
    return 0;
}
