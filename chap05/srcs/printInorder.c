/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printInorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:05:35 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 17:56:08 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

// 중위 순회
void printInorder(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	printInorder(pNode->pLeftChild);
	printf("%c ", pNode->data);
	// write(1, &pNode->data, 1);
	printInorder(pNode->pRightChild);
	return ;
}