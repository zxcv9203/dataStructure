/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchRecursiveBST.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:54:14 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 19:52:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"

static BinSearchTreeNode *dfs(BinSearchTreeNode *node, int key)
{
	if (!node || node->key == key)
		return (node);
	else if (node->key > key)
		return dfs(node->pLeftChild, key);
	else
		return dfs(node->pRightChild, key);
}

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key)
{
	if (!pBinSearchTree)
		return (NULL);
	return (dfs(pBinSearchTree->pRootNode, key));
}