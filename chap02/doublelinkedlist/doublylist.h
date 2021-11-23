#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

#include <stdlib.h>
#include <stdio.h>

typedef struct DoublyListNodeType
{
	int data;							// 값
	struct DoublyListNodeType* pLLink;	// prev list
	struct DoublyListNodeType* pRLink; // next list
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;		// 현재 리스트의 개수
	DoublyListNode	headerNode;		// 시작점(Header Node)
} DoublyList;

/*
*** Double Linked 리스트를 생성하는 함수
*/
DoublyList* createDoublyList();

/*
*** Double Linked list의 리스트를 삭제하는 함수(메모리 할당 해제)
*/
void deleteDoublyList(DoublyList* pList);

/*
*** Double Linked list를 position 위치에 elment의 내용으로 추가합니다.
*/
int addDLElement(DoublyList* pList, int position, DoublyListNode element);

/*
*** Double Linked list의 포지션 위치의 값을 삭제합니다.
*/
int removeDLElement(DoublyList* pList, int position);

/*
*** Double linked list의 data를 초기화합니다.
*/
void clearDoublyList(DoublyList* pList);

/*
*** Double Linked list의 현재 길이를 가져옵니다.
*/
int getDoublyListLength(DoublyList* pList);

/*
*** Double Linked List의 position 위치의 노드를 반환합니다.
*/
DoublyListNode* getDLElement(DoublyList* pList, int position);

/*
*** Display Double List의 값들을 출력해줍니다.
*/
void displayDoublyList(DoublyList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
