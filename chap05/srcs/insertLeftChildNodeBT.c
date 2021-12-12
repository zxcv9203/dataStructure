/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertLeftChildNodeBT.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:19:43 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 16:19:58 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *childNode;
	
	childNode = NULL;
	if (!pParentNode)
		return (NULL);
	if (!pParentNode->pLeftChild)
	{
		childNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
		if (!childNode)
			return (NULL);
		childNode->data = element.data;
		pParentNode->pLeftChild = childNode;
	}
	else
		fprintf(stderr, "There is already a left child");
	return (childNode);
}