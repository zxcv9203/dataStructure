#include "doublylist.h"

DoublyList* createDoublyList()
{
	DoublyList *dl;

	dl = (DoublyList *)malloc(sizeof(DoublyList));
	if (dl == NULL)
		return (NULL);
	dl->currentElementCount = 0;
	dl->headerNode.data = 0;
	dl->headerNode.pLLink = NULL;
	dl->headerNode.pRLink = NULL;
	return (dl);
}

void deleteDoublyList(DoublyList* pList)
{
	DoublyListNode *node;
	DoublyListNode *release;

	if (pList == NULL)
		return ;
	node = pList->headerNode.pRLink;
	while (node && node != &pList->headerNode) {
		release = node;
		node = node->pRLink;
		release->pLLink = 0;
		release->pRLink = 0;
		release->data = 0;
		free(release);

	}
	pList->currentElementCount = 0;
	pList->headerNode.pLLink = 0;
	pList->headerNode.pRLink = 0;
	free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *node;
	DoublyListNode *prev;
	int				i;

	i = 0;
	if (pList == NULL)
		return (FALSE);
	if (position < 0 || pList->currentElementCount < position)
		return (FALSE);
	node = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (node == NULL)
		return (FALSE);
	node->data = element.data;
	prev = &pList->headerNode;
	while (i++ < position && prev->pRLink)
		prev = prev->pRLink;
	node->pRLink = prev->pRLink;
	node->pLLink = prev;
	prev->pRLink = node;
	if (node->pRLink == NULL || node->pRLink == &pList->headerNode)
	{
		node->pRLink = &pList->headerNode;
		pList->headerNode.pLLink = node;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *node;
	DoublyListNode *prev;
	DoublyListNode *next;
	int				i;

	i = 0;
	if (pList == NULL)
		return (FALSE);
	if (position >= pList->currentElementCount || position < 0)
		return (FALSE);
	prev = &pList->headerNode;
	while (i++ < position && prev->pRLink)
		prev = prev->pRLink;
	node = prev->pRLink;
	next = node->pRLink;
	next->pLLink = prev;
	prev->pRLink = next;
	node->pLLink = NULL;
	node->pRLink = NULL;
	node->data = 0;
	free(node);
	pList->currentElementCount--;
	return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
	DoublyListNode *node;
	DoublyListNode *prev;
	int				i;

	if (pList == NULL)
		return ;
	i = pList->currentElementCount;
	node = pList->headerNode.pRLink;
	while (i--)
	{
		prev = node;
		node = node->pRLink;
		prev->pLLink = NULL;
		prev->pRLink = NULL;
		prev->data = 0;
		pList->currentElementCount--;
		free(prev);
	}
}

int getDoublyListLength(DoublyList* pList)
{
	if (pList == NULL)
		return (FALSE);
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *node;
	
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

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode *node;

	if (pList == NULL)
		return ;
	node = pList->headerNode.pRLink;
	while (node && node != &pList->headerNode)
	{
		printf("prev : %p, node : %p, node->data : %d, next : %p\n", 
				node->pLLink, node, node->data, node->pRLink);
		node = node->pRLink;
	}
}

void reverseDoublyLinkedList(DoublyList *pList) {

	DoublyListNode *node;
	DoublyListNode *prev;
	DoublyListNode *tmp;

	if (pList == NULL)
		return ;
	prev = &pList->headerNode;
	node = pList->headerNode.pRLink;
	while (node != &pList->headerNode)
	{
		tmp = prev->pRLink;
		prev->pRLink = prev->pLLink;
		prev->pLLink = tmp;
		prev = node;
		node = node->pRLink;
	}
	tmp = prev->pRLink;
	prev->pRLink = prev->pLLink;
	prev->pLLink = tmp;
}