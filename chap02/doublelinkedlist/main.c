#include "doublylist.h"

void createDoublyList_test() {
	DoublyList *dl;

	dl = createDoublyList();
	printf("%d %d %p %p\n", dl->currentElementCount, dl->headerNode.data, dl->headerNode.pLLink, dl->headerNode.pRLink);
}

void addDLElement_test() {
	DoublyList *dl;
	DoublyListNode element;
	DoublyListNode *node;

	dl = createDoublyList();
	for (int i = 0; i < 2; i++) {
		element.data = (i+1) * 3;
		addDLElement(dl, i, element);
	}
	node = dl->headerNode.pRLink;
	for (int i = 0; i < 10; i++) {
		printf("prev : %p node : %p %d next : %p\n", node->pLLink, node, node->data, node->pRLink);
		node = node->pRLink;
	}
}

void removeDLElement_test() {

}

int main() {
	//createDoublyList_test();
	addDLElement_test();
	//removeDLElement_test();
}
