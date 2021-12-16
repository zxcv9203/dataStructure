/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteElementBST.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:53:25 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 17:49:56 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "binsearchtree.h"

static BinSearchTreeNode *dfs(BinSearchTreeNode *node, int key)
{
	if (!node)
		return (node);
	else if (key < node->key)
		node->pLeftChild = dfs(node->pLeftChild, key);
	else if (key > node->key)
		node->pRightChild = dfs(node->pRightChild, key);
	else
	{
		BinSearchTreeNode *tmp;
		if (!node->pLeftChild) {
			tmp = node->pRightChild;
			node->key = 0;
			node->value = 0;
			node->pRightChild = 0;
			free(node);
			return tmp;
		}
		else if (!node->pRightChild) {
			tmp = node->pLeftChild;
			node->key = 0;
			node->value = 0;
			node->pLeftChild = 0;
			free(node);
			return tmp;
		}
		else {
			tmp = searchLeftMaxNode(node);
			//printf("%d %d\n", tmp->key, tmp->value);
			node->key = tmp->key;
			node->value = tmp->value;
			//node->pLeftChild = 0;
			//node->pRightChild = 0;
			//ºó °ø°£À» ¿ÞÂÊ¿¡¼­ Å½»öÇØ ÇÏ³ª¾¿ À§·Î ¿Ã·Á ¸Þ²Û´Ù
			node->pLeftChild = dfs(node->pLeftChild, tmp->key);
		}
	}
	return (node);
}
int deleteElementBST(BinSearchTree* pBinSearchTree, int key)
{
	if (!pBinSearchTree)
		return FALSE;
	if (!searchBST(pBinSearchTree, key))
		return FALSE;
	dfs(pBinSearchTree->pRootNode, key);
	return TRUE;
}