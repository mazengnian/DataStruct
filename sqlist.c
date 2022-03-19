#include "sqlist.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
sqlink list_creat(){
    /* 创建线性表流程
     * 1.申请内存
     * 2.初始化
     * 3.返回
     * */
    sqlink L;
    L = (sqlink)malloc(sizeof (sqlist));
    if(L == NULL){
        printf("List Malloc Failed!\n");
        return L;  //如果内存没申请成功其实返回的就是NULL
    }
    memset(L, 0, sizeof (sqlist));//清空内存
    L->last = -1;
    return L;
}
int list_clear(sqlink L){
    if(L == NULL){
        printf("List Malloc Failed!\n");
        return L;  //如果内存没申请成功其实返回的就是NULL
    }
    memset(L, 0, sizeof (sqlist));//清空内存
    L->last = -1;
    return L;
}
/*
 * list_empty: Is list empty?
 * pare L:list
 * @ret 1--empty  0--not empty
 * */
int list_empty(sqlink L){
    if (L->last == -1)
        return 1;
    else
        return 0;
}
int list_length(sqlink L){
    if(L == NULL)
        return -1;
    return (L->last+1);
}
int list_locate(sqlink L, data_t value){
    int pos, i;
    for(i=0; i <= L->last; i++){
        if(L->data[i] == value){
            return i;
            break;
        }
        else
            return -1;
    }
}
int list_insert(sqlink L, data_t value, int pos){
    /*
     * 1.判断是否满
     * 2.检查区间是否符合
     * 3.移动(往后移)
     * */
    int i;
    if(L->last == N-1){
        printf("List is full\n");
        return -1;
    }
    if(pos < 0 || pos > L->last+1){
        printf("Pos is invalid\n");
        return -1;
    }
    for(i = L->last; i >= pos; i--){
        L->data[i+1] = L->data[i];
    }
    L->data[pos] = value;
    L->last++;

    return 0;
}
int list_show(sqlink L){
    int i;
    if(L == NULL){
        printf("List is empty\n");
        return -1;
    }
    for(i =0; i <= L->last; i++){
        printf("%d", L->data[i]);
    }
}
int list_delete(sqlink L){
    if(L == NULL){
        return -1;
    }
    free(L);
    L = NULL;
    return 0;
}
int list_merge(sqlink L1, sqlink L2){
    int i = 0;
    int ret;
    while(i <= L2->last){
        ret = list_locate(L1, L2->data[i]);
        if(ret == -1){
            if(list_insert(L1, L2->data[i], L1->last+1) == -1)
                return -1;
        }
        i++;
    }
    return 0;
}
int list_delete_pos(sqlink L, int pos){
    /*
     * 1.判断是否空
     * 2.检查区间是否符合
     * 3.移动(往前移)
     * 4.更新链表
     * */
    int i;
    if(L->last == -1){
        printf("List is empty\n");
        return -1;
    }
    if(pos < 0 || pos > L->last){
        printf("Pos is invalid\n");
        return -1;
    }
    for(i = pos+1; i >= L->last; i++){
        L->data[i-1] = L->data[i];
    }
    L->last--;
    return 0;
}
int list_purge(sqlink L){
    int i,j;
    if(L->last == 0){
        return 0;
    }
    i = 1;
    while(i <= L->last){
        j = i-1;
        while (j >= 0){
            if(L->data[i] == L->data[j]){
                list_delete_pos(L, i);
            }
            else{
                j--;
            }
        }
        if(j < 0){
            i++;
        }
    }
    return 0;
}