#include "arrayHeap.h"

void	deleteHeapTree(HeapTree *pHeap)
{
	if (!pHeap || !pHeap->pElement)
		return ;
	for (int i = 0; i < pHeap->currentElementCount; i++)
		pHeap->pElement[i].key = 0;
	free(pHeap->pElement);
	pHeap->currentElementCount = 0;
	pHeap->maxElementCount = 0;
	free(pHeap);
}