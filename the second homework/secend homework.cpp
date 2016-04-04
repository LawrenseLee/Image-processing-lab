/*
��cд�ĵ�����
04121510 ��    ������
*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//��������ڵ�
typedef struct Node
{
	int data;//������
	struct Node * pNext;//ָ����
}NODE, *PNODE;
//��������
PNODE createLinkList(void);//��������ĺ���
void traverseLinkList(PNODE pHead);//��������ĺ���
bool isEmpty(PNODE pHead);//�ж������Ƿ�Ϊ�յĺ���
int getLength(PNODE pHead);//��ȡ�����ȵĺ���
bool insertElement(PNODE pHead, int pos, int val);//�������в���Ԫ�صĺ�����������������Ϊ����ͷ��㡢Ҫ����Ԫ�ص�λ�ú�Ҫ����Ԫ�ص�ֵ
bool deleteElement(PNODE pHead, int pos, int * pVal);//��������ɾ��Ԫ�صĺ�����������������Ϊ����ͷ��㡢Ҫɾ����Ԫ�ص�λ�ú�ɾ����Ԫ�ص�ֵ
void sort(PNODE pHead);//�������е�Ԫ�ؽ�������ĺ���
int main()
{
	int val;//���ڱ���ɾ����Ԫ��
	PNODE pHead = NULL;				
	pHead = createLinkList();//����һ����ѭ�������������������ͷ����ַ����pHead
	traverseLinkList(pHead);//���ñ�������ĺ���
	if (isEmpty(pHead))
		printf("����Ϊ�գ�\n");
	else
		printf("����Ϊ�գ�\n");
	printf("����ĳ���Ϊ��%d\n", getLength(pHead));
//����ð��������
	sort(pHead);
//���±���
	traverseLinkList(pHead);
//��������ָ��λ�ô�����һ��Ԫ��
	if (insertElement(pHead, 4, 30))
		printf("����ɹ�!�����Ԫ��Ϊ��%d\n", 30);
	else
		printf("����ʧ��!\n");
//���±�������
	traverseLinkList(pHead);
//ɾ��Ԫ�ز���
	if (deleteElement(pHead, 3, &val))
		printf("Ԫ��ɾ���ɹ�!ɾ����Ԫ���ǣ�%d\n", val);
	else
		printf("Ԫ��ɾ��ʧ��!\n");
	traverseLinkList(pHead);
	system("pause");
	return 0;
}
PNODE createLinkList()
{
	int length;//��Ч���ĳ���
	int i;
	int value;//��������û�����Ľ���ֵ
//������һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("�ڴ����ʧ�ܣ������˳���\n");
		exit(-1);
	}
	PNODE pTail = pHead;//pTailʼ��ָ��β���
	pTail->pNext = NULL;//���ָ����
	printf("����������Ҫ����������ĸ�����len = ");
	scanf_s("%d", &length);
	for (i = 0; i<length; i++)
	{
		printf("�������%d������ֵ��", i + 1);
		scanf_s("%d", &value);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pHead)
		{
			printf("�ڴ����ʧ�ܣ������˳���\n");
			exit(-1);
		}
		pNew->data = value;//���½���з���ֵ
		pTail->pNext = pNew;//��β���ָ���½��
		pNew->pNext = NULL;//���½���ָ�������
		pTail = pNew;//���½�㸳��pTail,ʹpTailʼ��ָ��Ϊβ���
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
	PNODE p = pHead->pNext;//ָ���׽ڵ�
	int len = 0;//��¼�����ȵı���
	while (NULL != p)
	{
		len++;
		p = p->pNext;//pָ����һ���
	}
	return len;
}
void sort(PNODE pHead)
{
	int len = getLength(pHead);//��ȡ������
	int i, j, t;//���ڽ���Ԫ��ֵ���м����
	PNODE p, q;//���ڱȽϵ������м�ָ�����
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
//�ж�p�Ƿ�Ϊ�ղ���ʹp����ָ��posλ�õĽ��
	while (NULL != p && i<pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (NULL == p || i>pos - 1)
		return false;
//����һ���½��
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("�ڴ����ʧ�ܣ������˳�!\n");
		exit(-1);
	}
	pNew->data = val;
//����һ����ʱ��㣬ָ��ǰp����һ���
	PNODE q = p->pNext;
//��pָ���½��
	p->pNext = pNew;
//��qָ��֮ǰpָ��Ľ��
	pNew->pNext = q;
	return true;
}
bool deleteElement(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;
//�ж�p�Ƿ�Ϊ�ղ���ʹp����ָ��pos���
	while (NULL != p->pNext && i<pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (NULL == p->pNext || i>pos - 1)
		return false;
//����Ҫɾ���Ľ��
	*pVal = p->pNext->data;
//ɾ��p����Ľ��
	PNODE q = p->pNext;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}