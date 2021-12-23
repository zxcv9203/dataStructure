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
    nextpos = ++(pArrayHeap->currentElementCount); // �뜝�럩�뀋�뜝�럡�땽�뜝�럥裕쏉옙�쐻占쎈윥占쎈윲�뜝�럥�맶�뜝�럥�쑋嶺뚮씭���占쎌맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅嶺뚯쉸占싸살맶�뜝�럥�쑋占쎈쨨饔낃퀣�뀋�뜝�럡�땽�뜝�럥裕쏉옙�쐻占쎈윥占쎈열�뜝�럥�맶�뜝�럥�쑋占쎈쨨�뜝占� �뜝�럥�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅�뜝�럩紐쀧솾袁㏉�쀯옙維믭옙�쐻占쎈뼢占쎄땀筌띾씛�삕占쎌맶�뜝�럥�쑅�뜝�럩紐쀯옙�쐻占쎈윥鸚룐뫅�삕占쎌맶占쎈쐻�뜝占� �뜝�럥�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅�뜝�럩紐쀯옙�쐻占쎈윪占쎌읆占쎈꽠��⑥궡�굲占쎈쐻占쎈윪筌띾씛�삕占쎌맶�뜝�럥�쑅�뜝�럩紐앭뜝�럥�꺐占쏙옙�벀�걠占쎄뎡 �뜝�럥�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅�뜝�럩紐앭뜝�럥�맶�뜝�럥�쐾占쎈쇊�눧類ㅼ굲�뜝�럩留띰옙�쐻占쎈윥占쎌몗占쎈쐻占쎈윥占쎌젢占쎈쐻占쎈윥占쎈㎍占쎈쐻占쎈윥占쎌몗�뜝�럡愿뚦뜝�럥�꽔�뜝�럩援뀐옙�쎗�뜝�뜴�쐻�뜝占� �뜝�럥�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅�뜝�럩留썲뜝�럥�맶�뜝�럥�쑅占쎈쇀占쎈눓占쎌맶�뜝�럥�쑋�뜝�럥痢먨뜝�럥�맶�뜝�럥�쑅�뜝�럩�꼨�뜝�럥�맶�뜝�럥�쑋占쎈쨨�뜝占� �뜝�럥�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅�뜝�럩留썲뜝�럥�맶�뜝�럥�쑅鶯ㅼ렮踰귨옙�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅�뜝�럩紐앭뜝�럥�럸占쎈쐻占쎈쑕占쎌맶占쎈쐻�뜝占� element �뜝�럥�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅�뜝�럩紐앯솾�꺂�뒧占쎈뎀�뜝�럥泥랃옙�쐻占쎈윥占쎈떀�뜝�럥�맶�뜝�럥�쐾�뜝�럥由듿뜝�럥�맶�뜝�럥�쑋占쎈쨨�뜝占� �뜝�럥�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅�뜝�럩紐앾옙�쐻占쎈윞占쎈쑆占쎈쐻占쎈윞�맱�씢�쐻占쎈윪筌띾씛�삕占쎌맶�뜝�럥�쑅�뜝�럩紐쀧솾�꺂�뒧筌ㅻ낑�삕占쎄뎡 �뜝�럥�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅嶺뚯쉸占싸살맶�뜝�럥�쑋占쎈쨨饔끸뫀�맶�뜝�럥�쑅�뜝�럥�럪�뜝�럥�맶�뜝�럥�쑅嶺뚯쉸占싸살맶�뜝�럥�쑋占쎈쨨占쏙옙癒��굲�뜝�럩留띰옙�쐻占쎈윥占쎌몝�썒占쏙옙援�占쎌굲
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
        if (child < pArrayHeap->currentElementCount && pArrayHeap->pElement[child].key < pArrayHeap->pElement[child + 1].key)
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