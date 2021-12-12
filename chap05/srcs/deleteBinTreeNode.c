/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteBinTreeNode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:29:05 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 16:05:54 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	if (pNode->pLeftChild || pNode->pLeftChild)
	{
		fprintf(stderr, "Cannot delete due to child node");
	}
	else
	{
		pNode->data = 0;
		pNode->visited = 0;
		free(pNode);
	}
}