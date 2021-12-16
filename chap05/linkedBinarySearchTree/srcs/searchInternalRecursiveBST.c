/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchInternalRecursiveBST.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:54:53 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 19:40:03 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"


BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{
	if (!pTreeNode || pTreeNode->key == key)
		return (pTreeNode);
	else if (pTreeNode->key > key)
		return searchInternalRecursiveBST(pTreeNode->pLeftChild, key);
	else
		return searchInternalRecursiveBST(pTreeNode->pRightChild, key);
}
