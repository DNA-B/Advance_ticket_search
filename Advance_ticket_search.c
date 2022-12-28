#define _CRT_SECURE_NO_WARNING

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 1000

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}



// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}



// 삽입 함수
void insert_max_heap(HeapType* h, int item)
{
	int i = h->heap_size;

	if (h->heap_size == 0)
	{
		h->heap[i] = item;
		h->heap_size += 1;
		return;
	}

	if (h->heap[i] < 0 || h->heap[i] > 999)
	{
		h->heap[i] = item;
		h->heap_size += 1;
		return;
	}

	if (h->heap[i + 1] >= 0 && h->heap[i + 1] <= 999)
	{
		// size가 0부터 시작 >> 왼쪽이 홀수, 오른쪽이 짝수
		if (item <= h->heap[i])
		{
			i = (i * 2) + 1;
		}
		else if (item > h->heap[i])
		{
			i = i * 2;
		}
	}
	else if(h->heap[i + 1] < 0 || h->heap[i + 1] > 999)
	{
		h->heap[i + 1] = item;
		h->heap_size += 1;
		return;
	}

	h->heap[i] = item;
	h->heap_size += 1;
}

// 삭제 함수
int delete_max_heap(HeapType* h)
{
	int item;
	int min = 1001;
	int index = 0;

	for (int i = h->heap_size - 1; i >= 0; i--)
	{
		if (h->heap[i] >= 0 && h->heap[i] <= 999)
		{
			if (h->heap[i] <= min)
			{
				min = h->heap[i];
				index = i;
			}
		}
	}
	
	item = min;
	h->heap[index] = 10000;
	h->heap_size -= 1;

	return item;
}


// 힙 정렬
void heap_sort(int a[], int n)
{
	HeapType* h;

	h = create();
	init(h);

	for (int i = 0; i < n; i++)
	{
		insert_max_heap(h, a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = delete_max_heap(h);
	}

	free(h);
}


int main(void)
{
	int number;
	int i;

	// 랜덤 수 생성
	srand(time(NULL));
	number = rand() % 100;
	printf("The number of nodes %d\n", number);


	// 리스트 초기화
	int list[MAX_ELEMENT];

	for (i = 0; i < number; i++)
	{
		list[i] = rand() % 999;
	}

	// 정렬
	heap_sort(list, number);
	printf("Sorting result\n");


	// 출력
	for (int i = 0; i < number; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}
