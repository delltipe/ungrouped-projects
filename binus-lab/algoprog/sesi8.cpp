//	sesi 8 lab
/*
BASIC SORTING:
- BUBBLE SORT
- SELECTION SORT
- INSERTION SORT
*/

#include <stdio.h>

void printAll (int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf ("%d - ", arr[i]);
	}
	puts ("");
}

//	BUBBLE SORT
//	PERBANDINGAN TIAP 2 ANGKA DI SETIAP ARRAY, TUKAR SESUAI SIZE
void bubbleSort (int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//	SELECTION SORT
//	SUATU INDEX MENCARI INDEX LAIN YANG PALING MINIMUM UNTUK DITUKAR
void selectionSort (int arr[], int size)
{
	int minIdx = 0;
	for (int i = 0; i < size - 1; i++)
	{
		minIdx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}

//	INSERTION SORT
//	MENGURUT MULAI DARI 2 INDEX LALU SATU PER SATU MEMASUKKAN ANGKA LALU DIURUT ULANG
void insertionSort (int arr[], int size)
{
	int key = 0, j = 0;
	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

//	TIME COMPLEXITY
//	PERHITUNGAN WAKTU DALAM MENJALANKAN SELURUH PROGRAM:
//	1. BIG-O = WORST CASE
//	2. THETA = AVERAGE CASE
//	3. OMEGA = BEST CASE

//	CARA HITUNG BIG-O
//	MISAL
//	printf ("Hello World");
//	O(1) = KONSTAN KARENA HANYA MENJALANKAN 1 STATEMENT
//	O(n) = WORST CASE NYA PRINT SEMUA DATA SEBANYAK N
//	MAKIN BANYAK LOOP O(n PANGKAT LOOP)

//	TIME COMPLEXITY KETIGA-TIGA SORTING MEMILIKI NESTED LOOP
//	DAN TIME COMPLEXITY NYA O(n^2)

int main ()
{
	int arr[] = {9, 1, 11, 7, 5};
	int size = sizeof (arr) / sizeof (arr[0]);
	
	puts ("Before sort: ");
	printAll (arr, size);
	
	insertionSort (arr, size);
	
	puts ("After sort: ");
	printAll (arr, size);
	
	return 0;
}
