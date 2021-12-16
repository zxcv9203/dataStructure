/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteBinSearchTreeInternal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:39:56 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 20:43:42 by sujilee          ###   ########.fr       */
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
 	if (!node)
 		free(node);
 }

static BinSearchTreeNode *search_prev(BinSearchTreeNode *node, BinSearchTreeNode *prev, int key)
 {
	if (!node || node->key == key)
		return (prev);
	else if (node->key > key)
		return search_prev(node->pLeftChild, node, key);
	else
		return search_prev(node->pRightChild, node, key);
 }
 
 void deleteBinSearchTreeInternal(BinSearchTree *pTree, BinSearchTreeNode* pTreeNode)
 {
	BinSearchTreeNode *prev;
	
 	if (!pTree || !pTreeNode)
 		return ;
	if (pTreeNode == pTree->pRootNode)
		pTree->pRootNode = 0;
	else
	{
		prev = search_prev(pTree->pRootNode, NULL, pTreeNode->key);
		if (!prev)
			return ;
		if (prev->pLeftChild == pTreeNode)
			prev->pLeftChild = 0;
		else
			prev->pRightChild = 0;
	}
 	dfs(pTreeNode);
 }
