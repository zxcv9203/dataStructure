/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeBinTree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:18:31 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 16:04:23 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *bTree;
	BinTreeNode *myRootNode;
	
	bTree = (BinTree *)calloc(1, sizeof(BinTree));
	if (!bTree)
		return (NULL);
	myRootNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (!myRootNode) {
		free(bTree);
		return (NULL);
	}
	*myRootNode = rootNode;
	bTree->pRootNode = myRootNode;
	return (bTree);
}