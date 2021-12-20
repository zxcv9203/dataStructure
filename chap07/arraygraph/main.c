#include "arraygraph.h"

void dfs(ArrayGraph *ag, int vertex) {
	bool *visit;
	LinkedStack *s;
	StackNode ele;

	if (ag->maxVertexCount <= vertex)
		return ;
	ele.data = vertex;
	if (!(visit = (bool *)calloc(ag->maxVertexCount, sizeof(bool))))
		return ;
	s = createLinkedStack();
	pushLS(s, ele);
	visit[vertex] = true;
	while (!isLinkedStackEmpty(s)) {
		StackNode *tmp = popLS(s);
		printf("%d\n", tmp->data);
		for (int i = 0; i < ag->maxVertexCount; i++) {
			if (i == tmp->data)
				continue ;
			if (ag->ppAdjEdge[tmp->data][i] && !visit[i]) {
				ele.data = i;
				visit[i] = true;
				pushLS(s, ele);
			}
		}
	}
}

void bfs(ArrayGraph *ag, int vertex) {
	bool *visit;
	LinkedDeque *q;
	DequeNode ele;

	if (ag->maxVertexCount <= vertex)
		return ;
	ele.data = vertex;
	if (!(visit = (bool *)calloc(ag->maxVertexCount, sizeof(bool))))
		return ;
	q = createLinkedDeque();
	insertRearLD(q, ele);
	visit[vertex] = true;
	while (!isLinkedDequeEmpty(q)) {
		DequeNode *tmp = deleteFrontLD(q);
		printf("%d\n", tmp->data);
		for (int i = 0; i < ag->maxVertexCount; i++) {
			if (i == tmp->data)
				continue ;
			if (ag->ppAdjEdge[tmp->data][i] && !visit[i]) {
				ele.data = i;
				visit[i] = true;
				insertRearLD(q, ele);
			}
		}
	}
}

void undir_ag_test() {
	ArrayGraph *ag;
	int max_count;

	printf("graph의 크기 : ");
	scanf("%d", &max_count);
	ag = createArrayGraph(max_count);

	while (1) {
		int n;
		int to;
		int from;


		printf("1.vertex insert\n2.edge insert(no weight)\n3.edge insert(weight)\n4.remove vertex\n5.remove edge\n6.empty\n7.display\n8.delete\n9.dfs\n10.bfs\n");
		printf("작업할 내용을 선택해주세요 : ");
		scanf(" %d", &n);
		switch(n) {
			case 1:
				printf("추가할 Vertex : ");
				scanf(" %d", &n);
				addVertexAG(ag, n);
				break;
			case 2:
				printf("연결할 Vertex를 입력해주세요(from, to) : ");
				scanf("%d %d", &from, &to);
				if (addEdgeAG(ag, from, to) == FAIL)
					fprintf(stderr, "연결에 실패했습니다.\n");
				break;
			case 3:
				printf("연결할 Vertex를 입력해주세요(from, to) : ");
				scanf(" %d %d", &from, &to);
				printf("가중치를 입력해주세요 : ");
				scanf(" %d", &n);
				if (addEdgewithWeightAG(ag, from, to, n))
					fprintf(stderr, "연결에 실패했습니다.\n");
				break;
			case 4:
				printf("삭제할 Vertex를 입력해주세요 : ");
				scanf(" %d", &n);
				if (removeVertexAG(ag, n) == FAIL)
					fprintf(stderr, "vertex 삭제에 실패했습니다.\n");
				break;
			case 5:
				printf("삭제할 edge를 입력해주세요(from, to) : ");
				scanf(" %d %d", &from, &to);
				if(removeEdgeAG(ag, from, to) == FAIL)
					fprintf(stderr, "edge 삭제에 실패했습니다.\n");
				break;
			case 6:
				printf("%s\n", isEmptyAG(ag) ? "TRUE" : "FALSE");
				break;
			case 7:
				displayArrayGraph(ag);
				break;
			case 8:
				deleteArrayGraph(ag);
				break;
			case 9:
				printf("탐색 시작점을 입력해주세요 : ");
				scanf(" %d", &n);
				dfs(ag, n);
				break;
			case 10:
				printf("탐색 시작점을 입력해주세요 : ");
				scanf(" %d", &n);
				bfs(ag, n);
				break;
			default:
				break;
		}
		if (n == 8)
			break ;
	}

}

void dir_ag_test() {
	ArrayGraph *ag;
	int max_count;
	
	printf("graph의 크기 : ");
	scanf("%d", &max_count);
	ag = createArrayDirectedGraph(max_count);
	while (1) {
		int n;
		int to;
		int from;

		printf("1.vertex insert\n2.edge insert(no weight)\n3.edge insert(weight)\n4.remove vertex\n5.remove edge\n6.empty\n7.display\n8.delete\n9.dfs\n10.bfs\n");
		printf("작업할 내용을 선택해주세요 : ");
		scanf(" %d", &n);
		switch(n) {
			case 1:
				printf("추가할 Vertex : ");
				scanf(" %d", &n);
				addVertexAG(ag, n);
				break;
			case 2:
				printf("연결할 Vertex를 입력해주세요(from, to) : ");
				scanf(" %d %d", &from, &to);
				if (addEdgeAG(ag, from, to) == FAIL)
					fprintf(stderr, "연결에 실패했습니다.\n");
				break;
			case 3:
				printf("연결할 Vertex를 입력해주세요(from, to) : ");
				scanf(" %d %d", &from, &to);
				printf("가중치를 입력해주세요 : ");
				scanf(" %d", &n);
				if (addEdgewithWeightAG(ag, from, to, n))
					fprintf(stderr, "연결에 실패했습니다.\n");
				break;
			case 4:
				printf("삭제할 Vertex를 입력해주세요 : ");
				scanf(" %d", &n);
				if (removeVertexAG(ag, n) == FAIL)
					fprintf(stderr, "vertex 삭제에 실패했습니다.\n");
				break;
			case 5:
				printf("삭제할 edge를 입력해주세요(from, to) : ");
				scanf(" %d %d", &from, &to);
				if(removeEdgeAG(ag, from, to) == FAIL)
					fprintf(stderr, "edge 삭제에 실패했습니다.\n");
				break;
			case 6:
				printf("%s\n", isEmptyAG(ag) ? "TRUE" : "FALSE");
				break;
			case 7:
				displayArrayGraph(ag);
				break;
			case 8:
				deleteArrayGraph(ag);
				break;
			case 9:
				printf("탐색 시작점을 입력해주세요 : ");
				scanf(" %d", &n);
				dfs(ag, n);
				break;
			case 10:
				printf("탐색 시작점을 입력해주세요 : ");
				scanf(" %d", &n);
				bfs(ag, n);
				break;
			default:
				break;
		}
		if (n == 8)
			break ;
	}
}

int main() {
	int n;

	printf("1. undirected graph\n2. directed graph\n");
	scanf(" %d", &n);
	switch(n) {
		case 1:
			undir_ag_test();
			break;
		case 2:
			dir_ag_test();
			break;
		default:
			break;
	}
}