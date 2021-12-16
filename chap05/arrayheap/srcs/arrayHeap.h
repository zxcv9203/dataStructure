#ifndef _ARR_HEAP_TREE_
#define _ARR_HEAP_TREE_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
	ERROR define 
*/

/*
	heap tree struct
*/
typedef struct HeapTreeNodeType
{
	int key;
} HeapTreeNode;

typedef struct HeapTreeType
{
	int	maxElementCount;		//�ִ� ��� ����
	int	currentElementCount;	//���� ��� ����
	HeapTreeNode *pElement;		//������ �����ϰ� �ִ� 1���� �迭
} HeapTree;

HeapTree* makeMaxHeapTree(int maxElementCount);
// HeapTree* makeMinHeapTree();
int		removeMaxHeapTreeNode(HeapTree *pTree);
int		insertMaxHeapTreeNode(HeapTree *pTree, HeapTreeNode Element);
int		isHeapTreeFull(HeapTree *pTree);
int		isHeapTreeEmpty(HeapTree *pTree);
// void	removeMinHeapTreeNode();
// void	insertMinHeapTreeNode();
void	deleteHeapTree(HeapTree *pHeap);
void 	DisplayHeapTree(HeapTree *pTree);
void	error(const char *msg);


#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0


#endif

#ifndef __ERROR__
# define __ERROR__
	extern const char *MALLOC_ERROR;
	extern const char *TREE_OVERFLOW;
	extern const char *TREE_UNDERFLOW;
	extern const char *INDEX_ERROR;
#endif