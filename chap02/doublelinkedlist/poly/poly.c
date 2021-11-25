#include "poly.h"

static int	handle_remaining_term(LinkedList *poly, ListNode *node, int index)
{
	int		stat;

	while (node)
	{
		stat = addLLElement(poly, index, *node);
		if (stat == FALSE)
		{
			deleteLinkedList(poly);
			return (FALSE);
		}
		index++;
		node = node->pLink;
	}
	return (TRUE);
} 

LinkedList	*addPoly(LinkedList *lsA, LinkedList *lsB)
{
	LinkedList	*poly;
	ListNode	*IterA;
	ListNode	*IterB;
	ListNode	calc;
	int			stat;
	int			i;
	
	i = 0;
	if (lsA == NULL && lsB == NULL)
		return (NULL);
	else if (lsA == NULL)
		return (copyLinkedList(lsB));
	else if (lsB == NULL)
		return (copyLinkedList(lsA));
	poly = createLinkedList();
	if (poly == NULL)
		return (NULL);
	IterA = lsA->headerNode.pLink;
	IterB = lsB->headerNode.pLink;
	while(IterA && IterB)
	{
		if (IterA->degree > IterB->degree)
		{
			stat = addLLElement(poly, i, *IterA);
			if (stat == FALSE)
			{
				deleteLinkedList(poly);
				return (NULL);
			}
			IterA = IterA->pLink;
		}
		else if (IterA->degree < IterB->degree)
		{
			stat = addLLElement(poly, i, *IterB);
			if (stat == FALSE)
			{
				deleteLinkedList(poly);
				return (NULL);
			}
			IterB = IterB->pLink;
		}
		else // IterA->degree == IterB->degree 
		{
			// 다항식 차수가 같은 경우에만 같은 차수끼리 계산
			calc.coef = IterA->coef + IterB->coef;
			calc.degree = IterA->degree;
			stat = addLLElement(poly, i, calc);
			if (stat == FALSE)
			{
				deleteLinkedList(poly);
				return (NULL);
			}
			IterA = IterA->pLink;
			IterB = IterB->pLink;
		}
		i++;
	}
	stat = handle_remaining_term(poly, IterA, i);
	if (stat == FALSE)
		return (NULL);
	stat = handle_remaining_term(poly, IterB, i);
	if (stat == FALSE)
		return (NULL);
	return (poly);
}