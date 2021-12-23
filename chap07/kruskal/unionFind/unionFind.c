#include "unionFind.h"
#include "linkedgraph/linkedgraph.h"
#include <stdbool.h>

// 부모노드를 찾는 함수
int getParent(int *parent, int child) {
	if (parent[child] == child)
		return child;
	return parent[child] = getParent(parent, parent[child]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int *parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}


// parent same is true, parent different is false
bool find(int *vertex, int to, int from) {
	to = getParent(vertex, to);
	from = getParent(vertex, from);
	if (to == from)
		return true;
	return false;
}

int *createUnionFind(int max) {
	int *vertex;

	vertex = (int *)calloc(max, sizeof(int));
	if (!vertex)
		return (NULL);
	for (int i = 0; i < max; i++) {
		vertex[i] = i;
	}
	return vertex;
}
