/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:39:28 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 12:02:330 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayHeap.h"

int		main(void)
{
	HeapTree *myTree;
	int stat;
	HeapTreeNode childNode;
	
	int number = 0;
	myTree = makeMaxHeapTree(10);
	while (1)
	{
		printf("1 : Insert\n2 : Remove\n3 : Empty\n4 : Full\n5 : Delete\n6 : Display\n> ");
		scanf(" %d", &number);
		switch (number)
		{
			case 1:
				printf("insert Heap Tree Node : ");
				scanf(" %d", &(childNode.key));
				stat = insertMaxHeapTreeNode(myTree, childNode);
				break;
			case 2:
				stat = removeMaxHeapTreeNode(myTree);
				break;
			case 3:
				printf("%s\n" , isHeapTreeEmpty(myTree) ? "is Empty" : "not empty");
				break;
			case 4:
				printf("%s\n" , isHeapTreeFull(myTree) ? "is Full" : "not full");
				break;
			case 5:
				printf("Delete Heap Tree : ");
				deleteHeapTree(myTree);
				break;
			case 6:
				DisplayHeapTree(myTree);
				break;
			default:
				break;
		}
		if (number == 5)
			break;
	}
	
	return (0);
}