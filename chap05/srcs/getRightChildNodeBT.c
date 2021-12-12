/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getRightChildNodeBT.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:20:48 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 14:27:15 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pRightChild);
}