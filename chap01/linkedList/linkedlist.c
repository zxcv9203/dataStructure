#include "linkedlist.h"


LinkedList* createLinkedList()
{
    LinkedList *lst;

    lst = (LinkedList *)malloc(sizeof(LinkedList));
	if (lst == NULL)
		return (NULL);
	lst->currentElementCount = 0;
	lst->headerNode.pLink = NULL;
	return lst;
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode    *prev;
    ListNode    *node;
    int         i;

    i = 0;
    if (pList == NULL)
        return (FALSE);
    if (pList->currentElementCount + 1 < position || position < 0)
        return (FALSE);
    node = (ListNode *)malloc(sizeof(ListNode));
    if (node == NULL)
        return (FALSE);
    node->data = element.data;
    prev = &pList->headerNode;
    while(i < position && prev->pLink)
    {
        prev = prev->pLink;
        i++;
    }
    node->pLink = prev->pLink;
    prev->pLink = node;
    pList->currentElementCount++;
    return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
   ListNode    *node; // 삭제할 노드
   ListNode    *prev; // 이전 노드
   int          i;

   if (position >= pList->currentElementCount || position < 0)
       return (FALSE);
   if (pList == NULL)
       return (FALSE);
   prev = &pList->headerNode;
   i = 0;
   while (i++ < position && prev->pLink)  
		prev = prev->pLink;
   node = prev->pLink;
   prev->pLink = node->pLink;
   free(node);
   node = 0;
   pList->currentElementCount--;
   return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
   ListNode    *node;

   if (pList == NULL)
       return (FALSE);
   if (position >= pList->currentElementCount || position < 0)
       return (FALSE);
   node = pList->headerNode.pLink;
   while (position--)
       node = node->pLink;
   return (node);
}

void clearLinkedList(LinkedList* pList)
{
    ListNode    *node;
	int			i;

    if (pList == NULL)
        return ;
    i = pList->currentElementCount;
    node = pList->headerNode.pLink;
    while (i--)
    {
        node->data = 0;
        node = node->pLink;
    }
}

int getLinkedListLength(LinkedList* pList)
{
    if (pList == NULL)
        return (FALSE);
    return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	ListNode  *node;
	ListNode  *prev;

	if (pList == NULL)
		return ;
	node = pList->headerNode.pLink;
	while (node) 
	{
		prev = node;
		node = node->pLink;
		free(prev);
		prev = 0;
	}
	free(pList);
	pList = 0;
}
