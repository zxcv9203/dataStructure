/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertRightChildNodeBT.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:20:12 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 16:20:16 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *childNode;
	
	childNode = NULL;
	if (!pParentNode)
		return (NULL);
	if (!pParentNode->pRightChild)
	{
		childNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
		if (!childNode)
			return (NULL);
		childNode->data = element.data;
		pParentNode->pRightChild = childNode;
	}
	else
		fprintf(stderr, "There is already a Right child");
	return (childNode);
}