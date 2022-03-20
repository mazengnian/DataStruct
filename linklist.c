#include "linklist.h"
#include "stdio.h"
#include "stdlib.h"
/***************************************************************
* 函数名称: linklist_creat
* 说    明: 创建一个链表
* 参    数: 无
* 返 回 值: 无
***************************************************************/
linklist linklist_creat(){
    linklist H;
    H = (linklist)malloc(sizeof (listnode));
    if(H == NULL){
        printf("Linklist is NULL\n");
        return 0;
    }
    H->data = 0;
    H->next = NULL;
    return H;
}
/***************************************************************
* 函数名称: linklist_tail_insert
* 说    明: 在链表尾部插入元素
* 参    数: H：链表名
           value：元素
* 返 回 值: 无
***************************************************************/
int linklist_tail_insert(linklist H, data_t value){
    /*
     * 1.生成新节点
     * 2.寻找尾结点
     * 3.插入
     * */
    linklist p;
    linklist q;
    if(H == NULL){
        printf("H is empty\n");
        return -1;
    }
    if((p = (linklist) malloc(sizeof (listnode))) == NULL){
        printf("Malloc is failed\n");
        return -1;
    }
    p->data = value;
    p->next = NULL;

    q = H;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = p;
    return 0;
}
/***************************************************************
* 函数名称: linklist_show
* 说    明: 打印链表
* 参    数: H：链表名
* 返 回 值: 无
***************************************************************/
int linklist_show(linklist H){
    linklist p;
    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    p = H;
    while(p->next != NULL){
        printf("%d", p->next->data);
        p = p->next;
    }
    puts("");
    return 0;
}
/***************************************************************
* 函数名称: linklist_get
* 说    明: 获取链表指定位置的元素
* 参    数: H：链表名
           pos：位置
* 返 回 值: 无
***************************************************************/
linklist linklist_get(linklist H, int pos){
    linklist p;
    int i;
    if(H == NULL){
        printf("H is empty\n");
        return NULL;
    }
    if(pos == -1){
        return H;
    }
    if(pos < -1){
        printf("Pos is invalid\n");
        return NULL;
    }
    p = H;
    i = -1;
    while(i < pos){
        p = p->next;
        if(p == NULL){
            printf("Pos is invalid\n");
            return NULL;
        }
        i++;
    }

    return p;
}
/***************************************************************
* 函数名称: linklist_free_insert
* 说    明: 在链表的指定位置插入元素
* 参    数: H：链表名
           value：元素
           pos：位置
* 返 回 值: 无
***************************************************************/
int linklist_free_insert(linklist H, data_t value, int pos){
    linklist p;
    linklist q;
    if(H == NULL){
        printf("H is empty\n");
        return -1;
    }
    p = linklist_get(H, pos - 1);
    if(p == NULL){
        return -1;
    }
    if((q = (linklist) malloc(sizeof (listnode))) == NULL){
        printf("Malloc is failed\n");
        return -1;
    }
    q->data = value;
    q->next = NULL;
    q->next = p->next;
    p->next = q;
    return 0;
}
/***************************************************************
* 函数名称: linklist_delete_pos
* 说    明: 删除链表指定位置后的元素
* 参    数: H：链表名
           pos：位置
* 返 回 值: 0：成功
           -1：失败
***************************************************************/
int linklist_delete_pos(linklist H, int pos){
    linklist p;
    linklist q;
    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    p = linklist_get(H, pos - 1);
    if(p == NULL){
        return -1;
    }
    if(p->next == NULL){
        printf("Delete pos is invalid\n");
        return -1;
    }
    q = p->next;
    q->next = p->next;
    free(q);
    q = NULL;
    return 0;
}
/***************************************************************
* 函数名称: linklist_free
* 说    明: 释放链表
* 参    数: H：链表名
* 返 回 值: 无
***************************************************************/
linklist linklist_free(linklist H){
    linklist p;
    if(H == NULL){
        printf("H is invalid\n");
        return NULL;
    }
    p = H;
    printf("free\n");
    while(H != NULL){
        p = H;
        printf("%d ", p->data);
        H = H->next;
        free(p);
    }
    puts("");
    return NULL;
}
/***************************************************************
* 函数名称: linklist_reverse
* 说    明: 反转链表
* 参    数: H：链表名
* 返 回 值: 无
***************************************************************/
int linklist_reverse(linklist H){
    linklist p;
    linklist q;
    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    if(H->next == NULL || H->next->next == NULL){
        return 0;
    }
    p = H->next->next;
    H->next->next = NULL;
    while(p != NULL){
        q = p;
        p = p->next;
        q->next = H->next;
        H->next = q;
    }
    return 0;
}
/***************************************************************
* 函数名称: linklist_adjacent_max
* 说    明: 求链表中相邻两个节点的最大值
* 参    数: H：链表名
* 返 回 值: 第一个节点指针
***************************************************************/
linklist linklist_adjacent_max(linklist H, data_t *value){
    int sum = 0;
    int max = 0;
    linklist p, q, r;
    if(H == NULL ){
        return NULL;
    }
    if(H->next->next->next == NULL || H->next == NULL || H->next->next == NULL){
        return H;
    }
    p = H->next;
    q = H->next->next;
    r = p;
    max = p->data + q->data;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
        sum = p->data + q->data;
        if(sum > max){
            max = sum;
            r = p;
        }
    }
    *value = max;
    return r;
}
/***************************************************************
* 函数名称: linklist_merge
* 说    明: 将两个有序链表进行合并
* 参    数: H：链表名
* 返 回 值: 无
***************************************************************/
int linklist_merge(linklist H1, linklist H2){
    linklist p, q, r;
    if(H1 == NULL || H2 == NULL){
        printf("H1 or H2 is empty\n");
        return -1;
    }
    p = H1->next;
    q = H2->next;
    r = p;
    H1->next = NULL;
    H2->next = NULL;
    while(p && q){
        if(p->data <= q->data){
            r->next = p;
            p = p->next;
            r = r->next;
            r->next = NULL;
        }else{
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    if(p == NULL){
        r->next = q;
    }else{
        r->next = p;
    }
    return 0;
}
