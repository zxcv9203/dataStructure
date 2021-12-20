#include "arraygraph.h"


// �׷��� ����
ArrayGraph *createArrayGraph(int maxVertexCount)
{
    ArrayGraph *pGraph;

    if (maxVertexCount <= 0)
        return (NULL);
    if (!(pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph))))
        return (NULL);
    if (!(pGraph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount)))
    {
        free(pGraph);
        return (NULL);
    }
    if (!(pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount)))
    {
        free(pGraph);
        free(pGraph->pVertex);
        return (NULL);
    }
    for (int i = 0; i < maxVertexCount; i++)
    {
        if (!(pGraph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount)))
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
	pGraph->currentVertexCount = 0;
    memset(pGraph->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    for (int i = 0; i < maxVertexCount; i++)
        memset(pGraph->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
    return (pGraph);
}
ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph *pGraph;

    if (maxVertexCount <= 0)
        return (NULL);
    if (!(pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph))))
        return (NULL);
    if (!(pGraph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount)))
    {
        free(pGraph);
        return (NULL);
    }
    if (!(pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount)))
    {
        free(pGraph);
        free(pGraph->pVertex);
        return (NULL);
    }
    for (int i = 0; i < maxVertexCount; i++)
    {
        if (!(pGraph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount)))
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
	pGraph->currentVertexCount = 0;

    memset(pGraph->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    for (int i = 0; i < maxVertexCount; i++)
        memset(pGraph->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
    return (pGraph);
}
// �׷��� ����
void deleteArrayGraph(ArrayGraph *pGraph)
{
    if (!pGraph)
        return;
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        free(pGraph->ppAdjEdge[i]);
    }
    free(pGraph->ppAdjEdge);
    free(pGraph->pVertex);
    free(pGraph);
}

// ���� �׷��� ���� �Ǵ�
int isEmptyAG(ArrayGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    if (pGraph->currentVertexCount == 0)
        return (TRUE);
    return (FALSE);
}

// ��� �߰�
int addVertexAG(ArrayGraph *pGraph, int vertexID)
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
int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    return (addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED));
}
int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (FAIL);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    return (SUCCESS);
}

// ����� ��ȿ�� ����.
int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
    if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED)
        return (FALSE);
    return (TRUE);
}

// ��� ����
int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, vertexID))
        return (FAIL);
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        removeEdgeAG(pGraph, vertexID, i);
        removeEdgeAG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
    return (SUCCESS);
}

// ���� ����
int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (FAIL);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
    return (SUCCESS);
}

// �׷��� ���� ���
void displayArrayGraph(ArrayGraph *pGraph)
{
    if (!pGraph)
        return;
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
		if (pGraph->pVertex[i] == NOT_USED)
			continue;
		printf("%d : ", i);
        for (int j = 0; j < pGraph->maxVertexCount; j++) {
			if (j == i || pGraph->pVertex[j] == NOT_USED) {
				printf("X ");
				continue;
			}
            printf("%d ", pGraph->ppAdjEdge[i][j]);
		}
        printf("\n");
    }
}