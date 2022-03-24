#顺序表
将线性表L=(a0,a1, ……,an-1)中的各元素依次存储于计算机一片连续的存储空间。
##特点
* 逻辑上相邻的元素存储位置也相邻
* 对数据元素的存取为随机存取或按地址存取
* 存储密度高  存储密度D = （数据结构中元素所占的存储空间）/（整     个数据结构所占的空间）
* 对表的插入和删除运算的时间复杂度较差
* 存在元素在存储器中成片移动的现象
* 要求系统提供一片较大的连续存储空间
##基本运算
###建立空表 sqlink list_creat(void)
将顺序表看作一个一维数组，last始终指向最后一个元素
###清空表 int list_clear(sqlink L)
将表内所有内容置0，last指向表头
###判断表是否为空 int list_empty(sqlink L)
判断last指向的位置，指向表头则为空
###计算表长度 int list_length(sqlink L)
last指向的位置+1即可
###确定元素在表中的位置 int list_locate(sqlink L, data_t value)
遍历
###插入元素 list_insert(sqlink L, data_t value, int pos)
将元素插入到表中元素Ai之前，并且表长+1，若表存在空闲空间，只需要将表L->data[i]到L->data[L->last]部分顺序下移一个单位即可,并将元素插入到L->data[i]处即可
###删除元素 int list_delete_pos(sqlink L, int pos)
将pos后的元素均向前移动
###删除顺序表 int list_delete(sqlink L)
直接free
###对两个表取并集 int list_merge(sqlink L1, sqlink L2)
* 遍历表L1,L2中元素是否相等
* 不相等则把L2中元素插入到L1表尾
###删除表中的相同元素 int list_purge(sqlink L)
遍历