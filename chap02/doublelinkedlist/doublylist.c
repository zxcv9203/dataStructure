#include "doublylist.h"

/*
*** Double Linked 리스트를 생성하는 함수
*/
DoublyList* createDoublyList() {
	DoublyList *doubleList;

	doubleList = (DoublyList *)malloc(sizeof(DoublyList));
	if (!doubleList)
		return (NULL);
	doubleList->currentElementCount = 0;
	doubleList->headerNode.pLLink = NULL;
	doubleList->headerNode.pRLink = NULL;
	return (doubleList);
}

/*
*** Double Linked list의 리스트를 삭제하는 함수(메모리 할당 해제)
*/
void deleteDoublyList(DoublyList* pList) {
	DoublyListNode *node;
	DoublyListNode *release;

	if (pList == NULL)
		return ;
	node = pList->headerNode.pRLink;
	while (node) {
		release = node;
		node = node->pRLink;
		free(release);
		release = 0;
	}
	free(pList);
	pList = 0;
}

/*
*** Double Linked list를 position 위치에 elment의 내용으로 추가합니다.
*/
int addDLElement(DoublyList* pList, int position, DoublyListNode element) {
	DoublyListNode *node;
	DoublyListNode *prev;
	int				i;

	i = 0;
	if (pList == NULL && (pList->currentElementCount < 0 || pList->currentElementCount < position))
		return (FALSE);
	node = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (node == NULL)
		return (FALSE);
	node->data = element.data;
	prev = &pList->headerNode;
	while (i < position && prev->pRLink)
	{
		prev = prev->pRLink;
		i++;
	}
	node->pRLink = prev->pRLink;
	node->pLLink = prev;
	prev->pRLink = node;
	if (node->pRLink == NULL)
	{
		node->pRLink = &pList->headerNode;
		pList->headerNode.pLLink = node;
	}
	pList->currentElementCount++;
	return (TRUE);	
}

/*
*** Double Linked list의 포지션 위치의 값을 삭제합니다.
*/
int removeDLElement(DoublyList* pList, int position) {
	DoublyListNode *node;
	DoublyListNode *prev;
	DoublyListNode *next;

	int i;
	
	i = 0;
	if (position >= pList->currentElementCount || position < 0)
		return (FALSE);
	if (pList == NULL)
		return (FALSE);
	prev = &pList->headerNode;
	while (i++ < position && prev->pRLink)
		prev = prev->pRLink;
	node = prev->pRLink;
	next = node->pRLink;
	next->pLLink = prev;
	prev = node->pRLink;
	free(node);
	node = 0;
	pList->currentElementCount--;
	return (TRUE);
}

/*
*** Double linked list의 data를 초기화합니다.
*/
void clearDoublyList(DoublyList* pList) {
    DoublyListNode    *node;
	int			i;

    if (pList == NULL)
        return ;
    i = pList->currentElementCount;
    node = pList->headerNode.pRLink;
    while (i--)
    {
        node->data = 0;
        node = node->pRLink;
    }
}

/*
*** Double Linked list의 현재 길이를 가져옵니다.
*/
int getDoublyListLength(DoublyList* pList) {
    if (pList == NULL)
        return (FALSE);
    return (pList->currentElementCount);
}

/*
*** Double Linked List의 position 위치의 노드를 반환합니다.
*/
DoublyListNode* getDLElement(DoublyList* pList, int position) {
   DoublyListNode    *node;

	if (pList == NULL)
       return (FALSE);
	if (position >= pList->currentElementCount || position < 0)
       return (FALSE);
	if (pList->currentElementCount / 2 <= position)
	{
		node = pList->headerNode.pLLink;
   		while (position--)
       		node = node->pLLink;
	}
	else
	{
		node = pList->headerNode.pRLink;
   		while (position--)
       		node = node->pRLink;
	}
   return (node);
}

/*
*** Display Double List의 값들을 출력해줍니다.
*/
void displayDoublyList(DoublyList* pList) {
    DoublyListNode    *node;

    node = pList->headerNode.pRLink;
    while (node)
    {
        printf("[%p]\t%d\n", node, node->data);
        node = node->pRLink;
    }
}
