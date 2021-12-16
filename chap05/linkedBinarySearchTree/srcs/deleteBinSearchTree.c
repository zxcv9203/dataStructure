/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteBinSearchTree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:39:35 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 16:45:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"

static void dfs(BinSearchTreeNode *node)
{
	if (!node)
		return ;
	if (node->pLeftChild)
		dfs(node->pLeftChild);
	if (node->pRightChild)
		dfs(node->pRightChild);
	node->key = 0;
	node->value = 0;
	node->pRightChild = 0;
	node->pLeftChild = 0;
	free(node);
}
void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{
	if (!pBinSearchTree || !pBinSearchTree->pRootNode)
		return ;
	dfs(pBinSearchTree->pRootNode);
	pBinSearchTree->pRootNode = 0;
	free(pBinSearchTree);
	return ;
}