#include <stdio.h>

/*
	퀵 정렬(Quick Sort)
	하나의 리스트를 피벗을 기준으로 두 개의 비 균등한 크기로 분할하고
	분할된 부분 리스트를 정렬한 다음, 두 개의 정렬된 부분 리스트를 합하여
	전체가 정렬된 리스트가 되게하는 방법입니다.
*/
void quickSort(int *data, int start, int end) {
	//원소가 1개인 경우
	if (start >= end) { 
		return ;
	}
	// 키는 첫번째 원소
	int key = start;
	// 시작지점에서부터 증가하는 인덱스
	int i = start + 1; 
	// 마지막 지점에서 부터 감소하는 인덱스
	int j = end;
	// 값을 스왑할때 사용할 임시저장 변수
	int tmp;

	// 시작 인덱스와 끝 인덱스가 엇갈릴 때까지 반복
	while (i <= j) {
		// 키값보다 큰 값을 만날때까지 오른쪽으로 이동
		while (data[i] <= data[key])
			i++;
		// 키값보다 작은 값을 만날때 까지 왼쪽으로 이동
		while (data[j] >= data[key] && j > start)
			j--;
		// 두 인덱스가 엇갈린 상태라면 키 값과 교체
		if (i > j) {
			tmp = data[j];
			data[j] = data[key];
			data[key] = tmp;
		} else {
			tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main(void) {
	int n = 10;
	int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	quickSort(data, 0, n - 1);
	for (int i = 0; i < 10; i++)
		printf("%d ", data[i]);
}