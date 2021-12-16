/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayHeapTree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:51 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 12:18:46 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayHeap.h"

void DisplayHeapTree(HeapTree *pTree) {
	for (int i = 1; i <= pTree->currentElementCount; i++) {
		printf("index : %d, key: %d\n", i,  pTree->pElement[i].key);
	}
}