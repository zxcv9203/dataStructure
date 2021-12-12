/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:39:28 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/12 18:00:56 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

int		main(void)
{
	BinTree *myTree;
	
	BinTreeNode *temp;
	BinTreeNode rootNode = {'A', 0, 0, 0};
	BinTreeNode childNode = {'B', 0, 0, 0};
	
	int number = 0;
	myTree = makeBinTree(rootNode);
	temp = myTree->pRootNode;
	while (1)
	{
		printf("1 : Insert Left\n2 : Insert Right\n3 : Get Left\n4 : Get Right\n5 : Get Root\n6 : Delete TreeNode\n7 : Delete Tree\n8 : print Preorder\n9 : print Inorder\n10 : print Postorder\n");
		scanf(" %d", &number);
		switch (number)
		{
			case 1:
				printf("insert Left Tree data : ");
				scanf(" %c", &(childNode.data));
				temp = insertLeftChildNodeBT(temp, childNode);
				break;
			case 2:
				printf("insert Right data : ");
				scanf(" %c", &(childNode.data));
				temp = insertRightChildNodeBT(temp, childNode);
				break;
			case 3:
				temp = getLeftChildNodeBT(temp);
				printf("get left child data %c\n", temp->data);
				break;
			case 4:
				temp = getRightChildNodeBT(temp);
				printf("get right child data %c\n", temp->data);
				break;
			case 5:
				temp = getRootNodeBT(myTree);
				printf("get root node data %c\n", temp->data);
				break;
			case 6:
				deleteBinTree(myTree);
				printf("BinTree deleted\n");
				break;
			case 7:
				deleteBinTreeNode(&rootNode);
				printf("BinTreeNode deleted\n");
				break;
			case 8:
				printf("8th case in\n");
				printPreorder(myTree->pRootNode);
				printf("\n");
				break;
			case 9:
				printf("9th case in\n");
				printInorder(myTree->pRootNode);
				printf("\n");
				break;
			case 10:
				printf("10th case in\n");
				printPostorder(myTree->pRootNode);
				printf("\n");
				break;
			default:
				break;
		}
		if (number == 6)
			break;
	}
	
	return (0);
}