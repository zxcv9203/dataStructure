/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printPreorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:10:41 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 17:56:11 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

// 전위 순회
void printPreorder(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	printf("%c ", pNode->data);
	printPreorder(pNode->pLeftChild);
	printPreorder(pNode->pRightChild);
	return ;
}