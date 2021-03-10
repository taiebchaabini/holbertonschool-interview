#include "sort.h"
/**
 * find_largest - Finds the longest number in array
 * @array: Array where to find the number
 * @size: Size of the array
 * Return: returns number of digit of the longest number
 **/
int find_largest(int *array, size_t size)
{
	unsigned int i = 0, b = 0, number = 0, l = 0;

	for (i = 0; i < size; i++)
	{
		number = array[i];
		for (b = 0; number; b++)
			number = number / 10;
		if (b > l)
			l = b;
	}
	return (l);
}
/**
 * free_buckets - Cleaning up memory used for buckets
 * @b: Buckets used for sorting
 **/
void free_buckets(int *b[9])
{
	int i = 0;

	for (i = 0; i <= 9; i++)
		free(b[i]);
}
/**
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: Array to sort
 * @size: size of the array
 **/
void radix_sort(int *array, size_t size)
{
	int *buckets[9], bSize[9], largest = 0, tmp = 0,
	    step = 0, b = 0, digit = 0, count = 0;
	unsigned int i = 0;

	if (size < 2)
		return;
	largest = find_largest(array, size);

	for (step = 0; step < largest; step++)
	{

		for (i = 0; i <= 9; i++)
		{
			bSize[i] = 0;
			buckets[i] = (int *)malloc(sizeof(int) * 1024);
			buckets[i][0] = -1;
		}

		for (i = 0; i != size; i++)
		{
			tmp = array[i];
			for (b = 0; b < step; b++)
				tmp = tmp / 10;
			digit = tmp % 10;
			buckets[digit][bSize[digit]] = array[i], bSize[digit] += 1;
		}

		for (i = 0, count = 0; i <= 9; i++)
		{
			for (b = 0; b < bSize[i] && buckets[i][0] != -1; b++, count++)
				array[count] = buckets[i][b];
		}

		free_buckets(buckets);
		print_array(array, size);
	}
}
