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
* 说    明: 删除链表指定位置的元素
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
        return -1;
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