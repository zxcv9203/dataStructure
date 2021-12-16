/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:57:08 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 16:46:05 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key)
{
	BinSearchTreeNode* temp;
	
	if (!pBinSearchTree)
		return NULL;
	temp = pBinSearchTree->pRootNode;
	while (temp)
	{
		if (key == temp->key)
			break;
		else if (key < temp->key)
			temp = temp->pLeftChild;
		else
			temp = temp->pRightChild;
	}
	return (temp);
}