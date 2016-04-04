/*
用c写的单链表
04121510 班    李乐新
*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//定义链表节点
typedef struct Node
{
	int data;//数据域
	struct Node * pNext;//指针域
}NODE, *PNODE;
//函数声明
PNODE createLinkList(void);//创建链表的函数
void traverseLinkList(PNODE pHead);//遍历链表的函数
bool isEmpty(PNODE pHead);//判断链表是否为空的函数
int getLength(PNODE pHead);//获取链表长度的函数
bool insertElement(PNODE pHead, int pos, int val);//向链表中插入元素的函数，三个参数依次为链表头结点、要插入元素的位置和要插入元素的值
bool deleteElement(PNODE pHead, int pos, int * pVal);//从链表中删除元素的函数，三个参数依次为链表头结点、要删除的元素的位置和删除的元素的值
void sort(PNODE pHead);//对链表中的元素进行排序的函数
int main()
{
	int val;//用于保存删除的元素
	PNODE pHead = NULL;				
	pHead = createLinkList();//创建一个非循环单链表，并将该链表的头结点地址赋给pHead
	traverseLinkList(pHead);//调用遍历链表的函数
	if (isEmpty(pHead))
		printf("链表为空！\n");
	else
		printf("链表不为空！\n");
	printf("链表的长度为：%d\n", getLength(pHead));
//调用冒泡排序函数
	sort(pHead);
//重新遍历
	traverseLinkList(pHead);
//向链表中指定位置处插入一个元素
	if (insertElement(pHead, 4, 30))
		printf("插入成功!插入的元素为：%d\n", 30);
	else
		printf("插入失败!\n");
//重新遍历链表
	traverseLinkList(pHead);
//删除元素测试
	if (deleteElement(pHead, 3, &val))
		printf("元素删除成功!删除的元素是：%d\n", val);
	else
		printf("元素删除失败!\n");
	traverseLinkList(pHead);
	system("pause");
	return 0;
}
PNODE createLinkList()
{
	int length;//有效结点的长度
	int i;
	int value;//用来存放用户输入的结点的值
//创建了一个不存放有效数据的头结点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("内存分配失败，程序退出！\n");
		exit(-1);
	}
	PNODE pTail = pHead;//pTail始终指向尾结点
	pTail->pNext = NULL;//清空指针域
	printf("请输入您想要创建链表结点的个数：len = ");
	scanf_s("%d", &length);
	for (i = 0; i<length; i++)
	{
		printf("请输入第%d个结点的值：", i + 1);
		scanf_s("%d", &value);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pHead)
		{
			printf("内存分配失败，程序退出！\n");
			exit(-1);
		}
		pNew->data = value;//向新结点中放入值
		pTail->pNext = pNew;//将尾结点指向新结点
		pNew->pNext = NULL;//将新结点的指针域清空
		pTail = pNew;//将新结点赋给pTail,使pTail始终指向为尾结点
	}
	return pHead;
}
void traverseLinkList(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}
bool isEmpty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}
int getLength(PNODE pHead)
{
	PNODE p = pHead->pNext;//指向首节点
	int len = 0;//记录链表长度的变量
	while (NULL != p)
	{
		len++;
		p = p->pNext;//p指向下一结点
	}
	return len;
}
void sort(PNODE pHead)
{
	int len = getLength(pHead);//获取链表长度
	int i, j, t;//用于交换元素值的中间变量
	PNODE p, q;//用于比较的两个中间指针变量
	for (i = 0, p = pHead->pNext; i<len - 1; i++, p = p->pNext)
	{
		for (j = i + 1, q = p->pNext; j<len; j++, q = q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
}
bool insertElement(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
//判断p是否为空并且使p最终指向pos位置的结点
	while (NULL != p && i<pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (NULL == p || i>pos - 1)
		return false;
//创建一个新结点
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("内存分配失败，程序退出!\n");
		exit(-1);
	}
	pNew->data = val;
//定义一个临时结点，指向当前p的下一结点
	PNODE q = p->pNext;
//将p指向新结点
	p->pNext = pNew;
//将q指向之前p指向的结点
	pNew->pNext = q;
	return true;
}
bool deleteElement(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;
//判断p是否为空并且使p最终指向pos结点
	while (NULL != p->pNext && i<pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (NULL == p->pNext || i>pos - 1)
		return false;
//保存要删除的结点
	*pVal = p->pNext->data;
//删除p后面的结点
	PNODE q = p->pNext;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}