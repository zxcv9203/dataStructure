#include "arrayheap.h"

ArrayHeap *createArrayHeap(int maxElementCount)
{
	ArrayHeap *myHeap;

	myHeap = (ArrayHeap *)calloc(1, sizeof(ArrayHeap));
	if (!myHeap)
		return FALSE;
		
	myHeap->pElement = (HeapNode *)calloc(maxElementCount, sizeof(HeapNode));
	if (!myHeap->pElement) {
		free(myHeap);
		return FALSE;
	}
	myHeap->maxElementCount = maxElementCount;
	myHeap->currentElementCount = 0;
	return myHeap;
}


void insertHeapNode(ArrayHeap *pArrayHeap, HeapNode element)
{
    int nextpos;
    if (isFullArrayHeap(pArrayHeap))
    {
        printf("This heap is full");
        return;
    }
    nextpos = ++(pArrayHeap->currentElementCount); // 癲ル슢�뵯占쎌맆占쎈쐻占쎈짗占쎌굲癲ル슢�뿪占쎌굲 占쎈쐻占쎈윥椰꾩�λ쐻占쎈윥�뤃占� 占쎈쐻占쎈윥�젆袁��쐻占쎈윪甕곤옙 占쎈쐻占쎈윪占쎄껑�뜝�럥�렓�뜝�럥遊억옙諭� 占쎈쐻占쎈윞占쎈룼占쎌뒙占쎈뙔占쎌굲 占쎈쐻占쎈윞占쎈쭨占쎈쐻占쎈윪獄�占� element 占쎈쐻占쎈윪筌띻쑈�뇲占쎄땔占쎌굲 占쎈쐻占쎈윪�굢�깷�쐻占쎈윥筌묕옙 占쎈쐻占쎈짗占쎌굲占쎈쐻占쎈짗占쎌굲�뜝�럩沅�
    while (nextpos != 1 && element.key > pArrayHeap->pElement[nextpos / 2].key)
    {
        pArrayHeap->pElement[nextpos] = pArrayHeap->pElement[nextpos / 2];
        nextpos /= 2;
    }
    pArrayHeap->pElement[nextpos] = element;
}
void deleteArrayHeap(ArrayHeap *pArrayHeap)
{
    if (!pArrayHeap)
        return;
    if (pArrayHeap->pElement)
        free(pArrayHeap->pElement);
    free(pArrayHeap);
}

int isFullArrayHeap(ArrayHeap *pArrayHeap)
{
    if (!pArrayHeap)
        return (FALSE);
    if (pArrayHeap->currentElementCount == pArrayHeap->maxElementCount)
        return (TRUE);
    return (FALSE);
}
int isEmptyArrayHeap(ArrayHeap *pArrayHeap)
{
    if (!pArrayHeap)
        return (FALSE);
    if (pArrayHeap->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}
HeapNode *deleteHeapNode(ArrayHeap *pArrayHeap)
{
    if (!pArrayHeap)
        return (NULL);
    if (isEmptyArrayHeap(pArrayHeap))
        return (NULL);
    int temp;
    int parent = 1;
    int child = 2;
    HeapNode *delNode;
    HeapNode *tempNode;

    if (!(delNode = (HeapNode *)malloc(sizeof(HeapNode))))
        return (NULL);
    *delNode = pArrayHeap->pElement[1];

    temp = pArrayHeap->currentElementCount--;
    tempNode = &(pArrayHeap->pElement[temp]);

    while (child <= pArrayHeap->currentElementCount)
    {
        if (child < pArrayHeap->currentElementCount && pArrayHeap->pElement[child].key > pArrayHeap->pElement[child + 1].key)
            child++;
        if (tempNode->key <= pArrayHeap->pElement[child].key)
            break;
        pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
        parent = child;
        child *= 2;
    }
    pArrayHeap->pElement[parent] = *tempNode;
    return (delNode);
}