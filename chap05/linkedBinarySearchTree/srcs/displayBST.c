/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayBST.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:50:00 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 17:17:10 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"

void displayBST(BinSearchTreeNode *node, int space) {
	if(!node)
		return ;
	space += 8;
	displayBST(node->pRightChild, space);
	printf("\n");
	for (int i = 8; i < space; i++)
		printf(" ");
	printf("%d(%d)\n", node->key, node->value);
	displayBST(node->pLeftChild, space); 
}