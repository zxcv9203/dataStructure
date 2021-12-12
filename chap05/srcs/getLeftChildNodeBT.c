/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getLeftChildNodeBT.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:20:34 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 14:27:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pLeftChild);
}