/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getRootNodeBT.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:19:15 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 14:16:52 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return NULL;
	return (pBinTree->pRootNode);
}