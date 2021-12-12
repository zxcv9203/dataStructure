/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printPostorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:08:53 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 17:55:41 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

// 후위 순회
void printPostorder(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	printPostorder(pNode->pLeftChild);
	printPostorder(pNode->pRightChild);
	printf("%c ", pNode->data);

	// write(1, &pNode->data, 1);

	return ;
}