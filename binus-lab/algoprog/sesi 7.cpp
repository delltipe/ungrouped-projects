// session 7 - FUNCTION AND RECURSION

#include <stdio.h>

//function main
//akan dipanggil saat kita menjalankan program

// <data type> <nama fungsi>(<parameter>){

// }

// data types = int, float, double, bool, void

// void = tidak mengembalikan apa apa
void printHelloWorld(){
	printf("Hello World\n");
}

// global variabel, tidak terikat function
//int x = 10;
//int y = 20;


// <tipe data return value> <nama function>(<parameter>)
//			  parameter
int multiply(int x, int y){
	int result = x * y;
	return result;
}

int divide(int x, int y){
	int result = x / y;
	return result;
}

int multiplyAndDivide(int x, int y){
	int result = multiply(x, y) + divide(x, y);
	return result;
}

//void functionDua(){
//	printf("%d\n", x + y);
//}

// passing by reference
void swapPtr(int* x, int* y){
	int z = *y;
	*y = *x;
	*x = z;
}

// passing by value
void swap(int x, int y){
	int z = y;
	y = x;
	x = z;
}

int factorialLoop(int factorial){
	int x = 1;
	for(int i = 1; i <= factorial; i++){
		x*=i;
	}
	return x;
}

int factorialRecursive(int factorial){
	if(factorial == 1 || factorial == 1){
		return 1;
	}
	return factorial * factorialRecursive(factorial - 1);
}

char map [][200] = {"###############",
					"#             #",
					"#             #",
					"#             #",
					"#         #####",
					"#         #   #",
					"###############"};
					   
void printMap(){
	for(int i = 0; i < 15; i++){
		printf("%s\n", map[i]);
	}
}

int dirX[] = {0, 1, 0, -1};
int dirY[] = {1, 0, -1, 0};

void floodFill(int x, int y){
	if(map[x][y] == '#' || map[x][y] == '*'){
		return;
	}
	
	map[x][y] = '*';
	
	printMap();
	
	for(int i = 0; i < 4; i++){
		floodFill(x + dirX[i], y + dirY[i]);
	}
}
					   
// recursive = function yang memanggil dirinya sendiri
//void recursiveAdd(int initial){
//	
//	if (initial == 1001){
//		return;
//	}
//	// stopping point (yg memberhentika fungsi rekursi)
//	printf("%d\n", initial);
//	
//	recursiveAdd(initial + 1);
//}

int main(){
	
	printMap();
	
	floodFill(1, 1); // koordinat, jangan mulai paint di border
	// function
	// karena sudah tau void, biasanya main hanya digunakan
	// untuk memanggil fungsi-fungsi void
	
//	printHelloWorld(); // memanggil function printHelloWorld
//
//	int numberOne, numberTwo;
//	scanf("%d %d", &numberOne, &numberTwo);
//	printf("%d\n", multiplyAndDivide(numberOne, numberTwo));
//	
//	x = 30; // x akan berubah dimanapun
//	
//	functionDua();
	
//	int x = 20;
//	int y = 30;
	
	// kita mau swap variabel
	// x => y
	// y => x
	
//	printf("%d %d\n", x, y);
//	
//	swapPtr(&x, &y);
//	
//	printf("%d %d\n", x, y);
	
//	printf("%d\n", factorialLoop(5));
	
//	recursiveAdd(1);
	
//	printf("%d\n", factorialRecursive(5));
	
	return 0;
}
