/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeMaxHeapTree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:13:06 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 12:07:02 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayHeap.h"

HeapTree* makeMaxHeapTree(int maxElementCount)
{
	HeapTree *myHeap;

	myHeap = (HeapTree *)calloc(1, sizeof(HeapTree));
	if (!myHeap)
	{
		error(MALLOC_ERROR);
		return FALSE;
	}
		
	myHeap->pElement = (HeapTreeNode *)calloc(maxElementCount, sizeof(HeapTreeNode));
	if (!myHeap->pElement)
	{
		//해당 분기에서 false로 프로그램이 종료되면 위에서 동적할당된 myHeap은 아직 남아있음
		error(MALLOC_ERROR);
		free(myHeap);
		return FALSE;
	}
	myHeap->maxElementCount = maxElementCount;
	myHeap->currentElementCount = 0;
	return myHeap;
}