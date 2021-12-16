/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertElementBST.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:36:28 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 17:09:22 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"

static BinSearchTreeNode* DFS(BinSearchTreeNode* new_node, BinSearchTreeNode* curr_node, int* stat)
{
	if (curr_node == 0)
	{
		curr_node = new_node;
		return curr_node;
	}	
	if (new_node->key < curr_node->key)
	{
		curr_node->pLeftChild = DFS(new_node, curr_node->pLeftChild, stat);	
	}	
	else if (new_node->key > curr_node->key)
		curr_node->pRightChild = DFS(new_node, curr_node->pRightChild, stat);
	else
	{
		printf("insert fail! node with same key already exist");
		stat = FALSE;
	}	
	return curr_node;
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{
	BinSearchTreeNode* new_node;
	int stat;
	
	stat = TRUE;
	if (!pBinSearchTree)
		return FALSE;
	new_node = (BinSearchTreeNode *)calloc(1, sizeof(BinSearchTreeNode));
	if (!new_node)
		return (FALSE);
	*(new_node) = element;
	
	pBinSearchTree->pRootNode = DFS(new_node, pBinSearchTree->pRootNode, &stat);
	return stat;
}
