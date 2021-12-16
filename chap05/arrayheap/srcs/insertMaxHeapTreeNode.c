/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertMaxHeapTreeNode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:21:17 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 11:03:53 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayHeap.h"

int	insertMaxHeapTreeNode(HeapTree *pTree, HeapTreeNode Element)
{
	if (!pTree)
		return FALSE;
	if (isHeapTreeFull(pTree))
	{
		error(TREE_OVERFLOW);
		return FALSE;
	}
	//EX) index 6¿¡ insert
	pTree->pElement[++pTree->currentElementCount] = Element;
	
	for (int i = pTree->currentElementCount; 
			i != 1 && pTree->pElement[i].key > pTree->pElement[i/2].key;
				i /= 2)
	{
		pTree->pElement[i] = pTree->pElement[i/2];
		pTree->pElement[i/2] = Element;
	}
	return TRUE;
}