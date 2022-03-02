//Recuperado de https://www.geeksforgeeks.org/bubble-sort/

// C++ program for implementation of Bubble sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)	
	
	// Last i elements are already in place
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int * generateRandom(int *numbers,int size){
	srand(time(0));
	int n = size;
    for(int i = 0; i<n; i++){
		//cout<<i<<endl;
		numbers[i]=1+rand();
	}

	return numbers;
}

// Driver code
int main()
{
	const int size = 100000;
	int numebers[size];
	int *arr = generateRandom(numebers,size);

	bubbleSort(arr, size);
	//printArray(arr, size);

    //One way​ to find the length of an array is to divide the size of the array by the size of each element (in bytes).
    //cout<<sizeof(arr)<<sizeof(arr[0])<<endl;

	return 0;
}

// This code is contributed by rathbhupendra
