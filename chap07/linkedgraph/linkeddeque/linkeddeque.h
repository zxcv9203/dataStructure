#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct DequeNodeType
{
	int data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
	int currentElementCount;	// ���� ������ ����
	DequeNode* pFrontNode;		// Front ����� ������
	DequeNode* pRearNode;		// Rear ����� ������
} LinkedDeque;

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeSize(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);
void displayLinkedDeque(LinkedDeque *pDeque);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif