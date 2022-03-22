/*
 * 队列是限制在两端进行插入和删除操作的线性表
 * 允许进行存入操作的一端称为“队尾”
 * 允许进行删除操作的一端称为“队头”
 * 当线性表中没有元素时称为“空队”
 * 特点：先进先出 FIFO
 * */
#include "stdio.h"
#include "stdlib.h"
#include "sequeue.h"
#include "string.h"
sequeue *sequeue_creat(){
    sequeue *sq;
    sq = (sequeue *)malloc(sizeof (sequeue));
    if(sq == NULL){
        return NULL;
    }
    memset((sq->data), 0, sizeof (sq->data));
    sq->front = sq->rear = 0;
    return sq;
}
int sequeue_en(sequeue *sq, int value){
    if((sq->rear + 1)%N == sq->front){
        printf("sequeue is full\n");
        return -1;
    }
    sq->data[sq->rear] = value;
    sq->rear= (sq->rear + 1) % N;
    return 0;
}
int sequeue_out(sequeue *sq){
    int t;
    t = sq->data[sq->front];
    sq->front = (sq->front + 1) % N;
    return t;
}
int sequeue_full(sequeue *sq){
    if((sq->rear + 1) % N == sq->front){
        return 1;
    } else{
        return 0;
    }
}
int sequeue_empty(sequeue *sq){
    return (sq->front == sq->rear ? 1 : 0);
}
int sequeue_clear(sequeue *sq){
    sq->front = sq->rear = 0;
}
sequeue *sequeue_free(sequeue *sq){
    free(sq);
    sq = NULL;
    return sq;
}