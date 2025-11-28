//	DATA STRUCTURES SESI 1

//	POINTER REVIEW

#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 10;
	printf("x = %d, Address: %d\n", x, &x); // & menandakan alamat x
	
	int *px = &x;
	// nilai variabel *px menunjuk nilai pada alamat x yang bernilai 10
	
	int **ppx = &px;
	// ** harus menunjuk ke pointer lain, jika bukan ke pointer, tidak akan bisa
	
	printf("*px = %d, px = %d, &px = %d\n", *px, px, &px);
	// maka px berisi alamatnya x saja
	// dan &px berisi alamat variabel px
	
	printf("**ppx = %d, ppx = %d, &ppx = %d\n", **ppx, ppx, &ppx);
	// **ppx menunjuk *px yang menunjuk alamat x bernilai 10
	// ppx brisi alamat px
	// &ppx berisi alamatnya tersendiri
	
	// review pass by reference/address
	int a = 10, b = 20;
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	
	int arr[10] = {1, 2, 3};
	int arr2[] = {1,1};
	// size array mengikuti isinya = 2
	
	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int arr[10][10];
	// sistem array 2 dimensi [kolom][baris]
	
	return 0;
}
