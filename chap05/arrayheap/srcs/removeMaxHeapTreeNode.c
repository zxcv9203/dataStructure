/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeMaxHeapTreeNode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:03:51 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 11:49:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayHeap.h"

int		removeMaxHeapTreeNode(HeapTree *pTree) //int position
{
	int parent;
	int child;
	HeapTreeNode temp;
	
	if (!pTree)
		return FALSE;
	//if (position <= 0 || position > pTree->maxElementCount)
	//{	
	//	error(INDEX_ERROR);
	//	return FALSE;
	//}
	if (isHeapTreeEmpty(pTree))
	{
		error(TREE_UNDERFLOW);
		return FALSE;
	}
	// root노드의 키값 0으로 초기화
	pTree->pElement[1].key = 0;
	//마지막 인덱스의 노드를 temp에 할당한 후 currcnt--
	temp = pTree->pElement[pTree->currentElementCount--];
	//처음 부모와 자식의 인덱스
	parent = 1;
	child = 2;
	//자식노드를 계속 말단 노드로 내리면서 반복문 실행
	while (child <= pTree->currentElementCount)
	{
		// 인덱스 오버플로우 방지 && 자식 두개를 비교해서 키값이 더 큰 자식을 선택
		if (child < pTree->currentElementCount &&
			pTree->pElement[child].key < pTree->pElement[child+1].key)
			child++;
		// 마지막 노드의 키값이 현재 자식의 키값보다 크거나 같을 경우 반복문 빠져나옴
		if (temp.key >= pTree->pElement[child].key)
			break ;
		// 키값이 큰 자식 노드 올리기
		pTree->pElement[parent] = pTree->pElement[child];
		// 그 다음 레벨로 넘어간다
		parent = child;
		child = child * 2;
	}
	//마지막 노드를 남는 공간에 할당해줌
	pTree->pElement[parent] = temp;
	return (TRUE);
}