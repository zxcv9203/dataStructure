/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isHeapTreeEmpty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:36:07 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 10:37:48 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayHeap.h"

int		isHeapTreeEmpty(HeapTree *pTree)
{
	if (!pTree)
		return FALSE;
	return (pTree->currentElementCount == 0);
}
