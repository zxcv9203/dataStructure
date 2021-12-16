/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isHeapTreeFull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:34:58 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 10:35:37 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayHeap.h"

int		isHeapTreeFull(HeapTree *pTree) 
{
	if (!pTree)
		return FALSE;
	return (pTree->currentElementCount == pTree->maxElementCount);
}
