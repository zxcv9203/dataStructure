/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchLeftMaxNode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:13:41 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 17:14:37 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"

BinSearchTreeNode* searchLeftMaxNode(BinSearchTreeNode *node)
{
	BinSearchTreeNode *curr;

	if (!node)
		return (node);
	curr = node->pLeftChild;
	while (curr->pRightChild)
	{
		curr = curr->pRightChild;
	}
	return (curr);
}
