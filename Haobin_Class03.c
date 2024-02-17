#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node* pNext;
}Node, * pNode;//Node == struct Node, * pNode == struct Node *

pNode create_list(void);
void traverse_list(pNode pHead);
bool is_empty(pNode pHead);
int	 length_list(pNode pHead);
bool insert_list(pNode pHead, int pos, int val);
bool delete_list(pNode pHead, int pos, int* val);
void sort_list(pNode pHead);

int main(void) {
	pNode pHead = NULL;

	pHead = create_list();
	traverse_list(pHead);

	insert_list(pHead, 4, 33);
	traverse_list(pHead);

	/*if (is_empty(pHead))
		printf("链表为空！\n");
	else
		printf("链表非空！\n");

	printf("链表长度为：%d\n", length_list(pHead));
	sort_list(pHead);
	printf("从小到大的排序为：");
	traverse_list(pHead);*/

	return 0;
}

pNode create_list(void) {
	int len;
	int i;
	int temp = 0;

	pNode pHead = (pNode)malloc(sizeof(Node));
	if (pHead == NULL) {
		printf("分配失败，程序终止！\n");
		exit(-1);
	}

	pNode pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入您需要生成的链表节点的个数：len = ");
	scanf_s("%d", &len);

	for (i = 0; i < len; i++) {
		printf("请输入第%d个节点的值：", i + 1);
		scanf_s("%d", &temp);

		pNode pNew = (pNode)malloc(sizeof(Node));
		if (pNew == NULL) {
			printf("分配第%d个节点失败，程序终止！\n", i + 1);
			exit(-1);
		}
		pNew->data = temp;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}

	return pHead;
}

void traverse_list(pNode pHead) {
	while (pHead->pNext != NULL) {
		pHead = pHead->pNext;
		printf("%d  ", pHead->data);
	}
	printf("\n");
}

bool is_empty(pNode pHead) {
	if (pHead->pNext != NULL)
		return false;
	return true;
}

int	 length_list(pNode pHead) {
	int len = 0;

	while (pHead->pNext != NULL) {
		len++;
		pHead = pHead->pNext;
	}
	
	return len;
}

bool insert_list(pNode pHead, int pos, int val) {
	if (pos > length_list(pHead) + 1 || pos < 1)
		return false;

	int count = 1;

	while (count < pos) {
		pHead = pHead->pNext;
		count++;
	}
	pNode pNew = (pNode)malloc(sizeof(Node));
	if (pNew == NULL) {
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = pHead->pNext;
	pHead->pNext = pNew;

	return true;
}

void sort_list(pNode pHead) {
	pNode one = pHead->pNext;

	while (one != NULL) {
		pNode two = one->pNext;
		while (two != NULL) {
			if (one->data > two->data) {
				int temp = one->data;
				one->data = two->data;
				two->data = temp;
			}
			two = two->pNext;
		}
		one = one->pNext;
	}
}

bool delete_list(pNode pHead, int pos, int* val) {

}
