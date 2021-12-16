/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBinSearchTree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:27:48 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 12:35:27 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "binsearchtree.h"

BinSearchTree* createBinSearchTree()
{
	BinSearchTree *bst;

	bst = (BinSearchTree *)calloc(1, sizeof(BinSearchTree));
	if (!bst)
		return NULL;
	return (bst);
}
