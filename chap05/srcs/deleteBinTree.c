/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteBinTree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:28:27 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 16:06:22 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

static void postOrderDelete(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	postOrderDelete(pNode->pLeftChild);
	postOrderDelete(pNode->pRightChild);
	pNode->data = 0;
	pNode->visited = 0;
	free(pNode);
}

void deleteBinTree(BinTree* pBinTree)
{
	if(!pBinTree)
		return ;
	postOrderDelete(pBinTree->pRootNode);
	pBinTree->pRootNode = 0;
	free(pBinTree);
	return ;
}
