#include "linkedgraph.h"

// �׷��� ����
LinkedGraph *createLinkedGraph(int maxVertexCount)
{
    LinkedGraph *pGraph;

    if (maxVertexCount <= 0)
        return (NULL);
    if (!(pGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph))))
        return (NULL);
    if (!(pGraph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount)))
    {
        free(pGraph);
        return (NULL);
    }
    if (!(pGraph->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount)))
    {
        free(pGraph);
        free(pGraph->pVertex);
        return (NULL);
    }
    for (int i = 0; i < maxVertexCount; i++)
    {
        if (!(pGraph->ppAdjEdge[i] = (LinkedList *)malloc(sizeof(LinkedList) * maxVertexCount)))
        {
            for (int j = 0; j < i - 1; j++)
            {
                free(pGraph->ppAdjEdge[j]);
            }
            free(pGraph->pVertex);
            free(pGraph);
            return (NULL);
        }
    }
    pGraph->graphType = GRAPH_UNDIRECTED;
    pGraph->maxVertexCount = maxVertexCount;
    pGraph->currentEdgeCount = 0;
    pGraph->currentVertexCount = 0;
    return (pGraph);
}

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount)
{
    LinkedGraph *pGraph;

    if (maxVertexCount <= 0)
        return (NULL);
    if (!(pGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph))))
        return (NULL);
    if (!(pGraph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount)))
    {
        free(pGraph);
        return (NULL);
    }
    if (!(pGraph->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount)))
    {
        free(pGraph);
        free(pGraph->pVertex);
        return (NULL);
    }
    for (int i = 0; i < maxVertexCount; i++)
    {
        if (!(pGraph->ppAdjEdge[i] = (LinkedList *)malloc(sizeof(LinkedList) * maxVertexCount)))
        {
            for (int j = 0; j < i - 1; j++)
            {
                free(pGraph->ppAdjEdge[j]);
            }
            free(pGraph->pVertex);
            free(pGraph);
            return (NULL);
        }
    }
    pGraph->graphType = GRAPH_DIRECTED;
    pGraph->maxVertexCount = maxVertexCount;
    pGraph->currentEdgeCount = 0;
    pGraph->currentVertexCount = 0;
    return (pGraph);
}
// �׷��� ����
void deleteLinkedGraph(LinkedGraph *pGraph)
{
    if (!pGraph)
        return;
    for (int i = 0; i < pGraph->maxVertexCount; i++)
        deleteLinkedList(pGraph->ppAdjEdge[i]);
    free(pGraph->ppAdjEdge);
    free(pGraph->pVertex);
    free(pGraph);
}

// ���� �׷��� ���� �Ǵ�
int isEmptyLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    if (pGraph->currentVertexCount == 0)
        return (TRUE);
    return (FALSE);
}

// ��� �߰�
int addVertexLG(LinkedGraph *pGraph, int vertexID)
{
    if (!pGraph)
        return (FAIL);
    if (vertexID >= pGraph->maxVertexCount)
        return (FAIL);
    if (pGraph->pVertex[vertexID] == USED)
        return (FAIL);
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return (SUCCESS);
}
// ���� �߰�
int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    return (addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, USED));
}


int addEdgewithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    ListNode addNode;
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (FAIL);
    addNode.vertexID = toVertexID;
    addNode.weight = weight;
    addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, addNode);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
    {
        addNode.vertexID = fromVertexID;
        addLLElement(pGraph->ppAdjEdge[toVertexID], 0, addNode);
    }
	pGraph->currentEdgeCount++;
	printf("func in Edge Count : %d\n", pGraph->currentEdgeCount);
    return (SUCCESS);
}
// ����� ��ȿ�� ����.
int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
    if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED)
        return (FALSE);
    return (TRUE);
}
// ��� ����
int removeVertexLG(LinkedGraph *pGraph, int vertexID)
{
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, vertexID))
        return (FAIL);
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        removeEdgeLG(pGraph, vertexID, i);
        removeEdgeLG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    return (SUCCESS);
}

// ���� ����
int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (FAIL);
    deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
    return (SUCCESS);
}
void deleteGraphNode(LinkedList *pList, int delVertexID)
{
    if (!pList)
        return;
    int position;

    position = findGraphNodePosition(pList, delVertexID);
    if (position >= 0)
        removeLLElement(pList, position);
}
int findGraphNodePosition(LinkedList *pList, int vertexID)
{
    if (!pList)
        return (-1);
    ListNode *temp;
    int position = 0;

    temp = pList->headerNode.pLink;
    while (temp)
    {
        if (temp->vertexID == vertexID)
            return (position);
        position++;
        temp = temp->pLink;
    }
    return (-1);
}
// ���� ���� ��ȯ
int getEdgeCountLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    return (pGraph->currentEdgeCount);
}
// ��� ���� ��ȯ
int getVertexCountLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    return (pGraph->currentVertexCount);
}

// �ִ� ��� ���� ��ȯ
int getMaxVertexCountLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    return (pGraph->maxVertexCount);
}

// �׷��� ���� ��ȯ.
int getGraphTypeLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    return (pGraph->graphType);
}

// �׷��� ���� ���
void displayLinkedGraph(LinkedGraph *pGraph)
{
    if (!pGraph)
        return;
    ListNode *temp;
    int position;

    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
		if (pGraph->pVertex[i] == NOT_USED)
			continue;
		printf("%d : ", i);
        for (int j = 0; j < pGraph->maxVertexCount; j++)
        {
			if (j == i) {
				printf("X ");
				continue;
			}
            position = findGraphNodePosition(pGraph->ppAdjEdge[i], j);
            if (position >= 0)
            {
                temp = getLLElement(pGraph->ppAdjEdge[i], position);
                printf("%d ", temp->weight);
            }
            else
            { 
				if(checkVertexValid(pGraph, j))
                	printf("0 ");
				else
					printf("X ");
            }
        }
        printf("\n");
    }
}