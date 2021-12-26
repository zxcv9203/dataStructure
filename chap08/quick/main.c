#include <stdio.h>

/*
	퀵 정렬(Quick Sort)
	하나의 리스트를 피벗을 기준으로 두 개의 비 균등한 크기로 분할하고
	분할된 부분 리스트를 정렬한 다음, 두 개의 정렬된 부분 리스트를 합하여
	전체가 정렬된 리스트가 되게하는 방법입니다.

	퀵 정렬은 다음과 같은 단계로 이루어집니다.
	1. 입력 배열을 피벗을 기준으로 비균등하게 2개의
	부분배열(피벗을 중심으로 왼쪽은 작은 요소, 오른쪽은 큰 요소)로
	분할합니다.
	2. 부분 배열을 정렬합니다. 부분 배열의 크기가 충분히 작지 않으면
	재귀를 이용하여 다시 분할 정복 방법을 적용합니다.
	3. 정렬될 부분 배열들을 하나의 배열에 합병합니다.

	재귀가 한번 진행될 때마다 최소한 하나의 원소(피벗)는 최종적으로
	위치가 정해지므로, 이 알고리즘은 반드시 끝난다는 것을 보장할 수 있습니다.
	
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