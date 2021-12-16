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
	// root����� Ű�� 0���� �ʱ�ȭ
	pTree->pElement[1].key = 0;
	//������ �ε����� ��带 temp�� �Ҵ��� �� currcnt--
	temp = pTree->pElement[pTree->currentElementCount--];
	//ó�� �θ�� �ڽ��� �ε���
	parent = 1;
	child = 2;
	//�ڽĳ�带 ��� ���� ���� �����鼭 �ݺ��� ����
	while (child <= pTree->currentElementCount)
	{
		// �ε��� �����÷ο� ���� && �ڽ� �ΰ��� ���ؼ� Ű���� �� ū �ڽ��� ����
		if (child < pTree->currentElementCount &&
			pTree->pElement[child].key < pTree->pElement[child+1].key)
			child++;
		// ������ ����� Ű���� ���� �ڽ��� Ű������ ũ�ų� ���� ��� �ݺ��� ��������
		if (temp.key >= pTree->pElement[child].key)
			break ;
		// Ű���� ū �ڽ� ��� �ø���
		pTree->pElement[parent] = pTree->pElement[child];
		// �� ���� ������ �Ѿ��
		parent = child;
		child = child * 2;
	}
	//������ ��带 ���� ������ �Ҵ�����
	pTree->pElement[parent] = temp;
	return (TRUE);
}