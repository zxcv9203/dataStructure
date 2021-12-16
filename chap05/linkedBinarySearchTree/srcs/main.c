/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:47:40 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 20:38:32 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"

int		main(void)
{
	BinSearchTree *myTree;
	int stat;
	BinSearchTreeNode childNode;
	BinSearchTreeNode *node;
	
	int number = 0;
	myTree = createBinSearchTree();
	while (1)
	{
		printf("1 : Insert\n2 : Remove\n3 : Search\n4 : Search(Recursive)\n5 : Search(Internal Recursive)\n6 : Display\n7: Delete\n8: Delete(Internal)\n$ ");
		scanf(" %d", &number);
		switch (number)
		{
			case 1:
				printf("insert node in BST : ");
				scanf(" %d", &(childNode.key));
				stat = insertElementBST(myTree, childNode);
				break;
			case 2:
				printf("delete Key : ");
				scanf(" %d", &(childNode.key));
				stat = deleteElementBST(myTree, childNode.key);
				break;
			case 3:
				printf("Search Key : ");
				scanf(" %d", &(childNode.key));
				node = searchBST(myTree, childNode.key);
				printf("%p\n", node);
				if (node)
					printf("key : %d, value : %d\n", node->key, node->value);
				break;
			case 4:
				printf("Search Key : ");
				scanf(" %d", &(childNode.key));
				printf("result key : %d\n", searchRecursiveBST(myTree, childNode.key)->key);
				break;
			case 5:
				printf("Search Key : ");
				scanf(" %d", &(childNode.key));
				node = searchBST(myTree, childNode.key);
				printf("Interal Search Key : ");
				scanf(" %d", &(childNode.key));
				node = searchInternalRecursiveBST(node, childNode.key);
				if (node)
					printf("key : %d value : %d\n", node->key, node->value);
				break;
			case 6:
				displayBST(myTree->pRootNode, 0);
				break;
			case 7:
				deleteBinSearchTree(myTree);
				break;
			case 8:
				printf("Search Key : ");
				scanf(" %d", &(childNode.key));
				node = searchBST(myTree, childNode.key);
				deleteBinSearchTreeInternal(myTree, node);
				break;
			default:
				break;
		}
		if (number == 7)
			break;
	}
	
	return (0);
}