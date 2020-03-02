#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void quicksort(int* array, int first, int last)
{
	if (first >= last) return;
	int begin = first;
	int end = last;

	while (1)
	{
		while (array[first] > array[++begin] && begin < end);
		while (array[first] < array[--end]);
		if (begin >= end) break;
		swap(array + begin, array + end);
	}

	swap(array + first, array + end);
	quicksort(array, first, end);
	quicksort(array, end + 1, last);
}

int main()
{
	int array[] = { 3, 7, 8, 5, 2, 1, 9, 5, 4 };
	int count = sizeof(array) / sizeof * array;

	quicksort(array, 0, count);

	for (int i = 0; i < count; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
