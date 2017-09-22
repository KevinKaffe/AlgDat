// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace std;
void heapify(int numbers[], int amount, int index)
{
	int l = 2 * index + 1;
	int r = 2 * index + 2;
	int g = index;

	if (l < amount && numbers[l]>numbers[g])
	{
		g = l;
	}
	if (r<amount && numbers[r]>numbers[g])
	{
		g = r;
	}
	if (g != index)
	{
		swap(numbers[index], numbers[g]);

		heapify(numbers, amount, g);
	}
}
void sort(int numbers[], int amount)
{
	for (int i = amount / 2 - 1; i >= 0; i--)
	{
		heapify(numbers, amount, i);
	}
	for (int i = amount - 1; i >= 0; i--)
	{
		swap(numbers[0], numbers[i]);
		heapify(numbers, i, 0);
	}
}
int adjSearchMin(int numbers[], int minIndex, int maxIndex, int val, int size)
{
	while (minIndex <= maxIndex)
	{
		int m = minIndex + (maxIndex - minIndex) / 2;
		if (numbers[m] == val)
			return val;
		if (numbers[m] < val)
		{
			/*if (m != size - 1 && numbers[m + 1] > val)
			return numbers[m+1];*/
			minIndex = m + 1;
		}
		else
		{
			if (m != 0 && numbers[m - 1] < val)
				return numbers[m - 1];
			maxIndex = m - 1;
		}
	}
	return numbers[0];
}
int adjSearchMax(int numbers[], int minIndex, int maxIndex, int val, int size)
{
	while (minIndex <= maxIndex)
	{
		int m = minIndex + (maxIndex - minIndex) / 2;
		if (numbers[m] == val)
			return val;
		if (numbers[m] < val)
		{
			if (m != size - 1 && numbers[m + 1] > val)
				return numbers[m + 1];
			minIndex = m + 1;
		}
		else
		{
			maxIndex = m - 1;
		}
	}
	return numbers[size - 1];
}
int main()
{
	int numbers[3000];
	char line[300000], *val,*val1;
	int valsRead, value;
	char delims[] = " \t\r\n";
	fgets(line, 30000, stdin);
	val = strtok(line, delims);
	valsRead = sscanf(val, "%d", &value);
	int amount = 0;
	while (valsRead>0)
	{
		numbers[amount++] = value;
		val = strtok(NULL, delims);
		valsRead = (val == NULL) ? 0 : sscanf(val, "%d", &value);
	}

	int value2;
	sort(numbers, amount);
	while (fgets(line, 18, stdin) != NULL)
	{
		val = strtok(line, delims);
		sscanf(val, "%d", &value);
		val1 = strtok(NULL, delims);
		sscanf(val1, "%d", &value2);
		printf("%d %d\n", adjSearchMin(numbers, 0, amount, value, amount), adjSearchMax(numbers, 0, amount, value2, amount));
	}

	return 0;
}

