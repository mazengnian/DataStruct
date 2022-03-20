#include "sqlist.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/***************************************************************
* 函数名称: list_creat
* 说    明: 创建一个顺序表
* 参    数: 无
* 返 回 值: 无
***************************************************************/
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
/***************************************************************
* 函数名称: list_clear
* 说    明: 清空顺序表
* 参    数: L：顺序表名
* 返 回 值: 无
***************************************************************/
int list_clear(sqlink L){
    if(L == NULL){
        printf("List Malloc Failed!\n");
        return L;  //如果内存没申请成功其实返回的就是NULL
    }
    memset(L, 0, sizeof (sqlist));//清空内存
    L->last = -1;
    return L;
}
/***************************************************************
* 函数名称: list_empty
* 说    明: 检测顺序表是否为空
* 参    数: L：顺序表名
* 返 回 值: 1：空
            0：非空
***************************************************************/
int list_empty(sqlink L){
    if (L->last == -1)
        return 1;
    else
        return 0;
}
/***************************************************************
* 函数名称: list_length
* 说    明: 测量顺序表长度
* 参    数: L：顺序表名
* 返 回 值: 顺序表的长度
***************************************************************/
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
/***************************************************************
* 函数名称: list_insert
* 说    明: 在顺序表的指定位置插入元素
* 参    数: L：顺序表名
            value：元素
            pos：位置
* 返 回 值: 无
***************************************************************/
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
/***************************************************************
* 函数名称: list_show
* 说    明: 打印顺序表
* 参    数: L：顺序表名
* 返 回 值: 无
***************************************************************/
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
/***************************************************************
* 函数名称: list_delete
* 说    明: 删除顺序表
* 参    数: L：顺序表名
* 返 回 值: 无
***************************************************************/
int list_delete(sqlink L){
    if(L == NULL){
        return -1;
    }
    free(L);
    L = NULL;
    return 0;
}
/***************************************************************
* 函数名称: list_merge
* 说    明: 将两个顺序表进行取并集，相同元素
* 参    数: L1：顺序表1名
            L2：顺序表2名
* 返 回 值: 无
***************************************************************/
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
/***************************************************************
* 函数名称: list_delete_pos 
* 说    明: 删除指定位置的元素顺序表
* 参    数: L：顺序表名
            pos：位置
* 返 回 值: 无
***************************************************************/
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
/***************************************************************
* 函数名称: list_purge
* 说    明: 删除顺序表中相同的元素
* 参    数: L：顺序表名
* 返 回 值: 无
***************************************************************/
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
