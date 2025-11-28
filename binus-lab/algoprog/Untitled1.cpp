//% = modulo = hasil sisa bagi
//7 % 2 = 1, 7 / 2 = 3 sisa 1
#include <stdio.h>
int main(){
	int angka1 = 11;
	int angka2 = 4;
	printf("Penjumlahan : %d\n", angka1 + angka2);
	printf("Pengurangan : %d\n", angka1 - angka2);
	printf("Perkalian   : %d\n", angka1 * angka2);
	printf("Pembagian   : %d\n", angka1 / angka2);
	printf("Modulo      : %d\n", angka1 % angka2);
	
	//pre-increment
	printf("Angka1 : %d\n", angka1); //11
	printf("Pre-increment : %d\n", ++angka1); //12
	//post-increment
	printf("Post-increment : %d\n", angka1++); //12
	printf("Angka1 : %d\n", angka1); //13
	
	//relational operators
	//angka1 = 5 dan angka2 = 7
	//angka1 != angka2
	
	if(angka1 < angka2){
		printf("angka 1 lebih kecil dari angka 2\n");
	}
	else{
		printf("angka 1 lebih besar dari angka 2\n");
	}
	
	//logical operators
	//ex: bool1 = true, bool2 = true
	//bool1 && bool2 = true
	//&& = and
	//|| = or
	//! = negation
	bool a = false;
	bool b = false;
	if(!a == true){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
	
	//bitwise operators
	//cara merubah angka menjadi biner
	//ex: 43/2 = 21, sisa 1
	//    21/2 = 10, sisa 1
	//    10/2 = 5,  sisa 0
	//    5/2  = 2,  sisa 1
	//    2/2  = 1,  sisa 0
	//    1/2  = 0,  sisa 1
	// ambil dari bawah untuk angka biner
	//101011
	
	//ex:    11 & 4 
	//    01011   0100
	//    01011
	//     0100
	//    -----&
	//    00000
	
	int c;
	int d;
	printf("Masukkan c: ");
	scanf("%d", &c); getchar(); //tambahkan getchar setiap scanf binary?
	printf("Masukkan d: ");
	scanf("%d", &d); getchar();
	//printf("Hasil %d & %d: %d\n", c, d, c&d); //and
	//printf("Hasil %d | %d: %d\n", c, d, c|d); //or
	//printf("Hasil %d ^ %d: %d\n", c, d, c^d); //Xor
	//printf("Negasi dari c: %d\n", ~c); //negasi
	//printf("Negasi dari d: %d\n", ~d); //negasi
	//<< = shift left
	//>> = shift right
	//ex:         a << b
	//            2 << 2
	//    0010 + 00 << 10
	//       001000 =  8
	//ex:         c << d
	//            3 << 1
	//         0011 << 0
	//        00110 =  6
	//ex:              a >> b
	//                13 >> 2
	//             01101 >> 10
	//               011 >> 0110
	//tambahkan 0, 00011 =  3
	printf("Left shift: %d << %d = %d\n", c, d, c<<d);
	printf("Right shift: %d >> %d = %d\n", c, d, c>>d);
	
	int e = 5;
	//a = a + 5; //10
	//a += 5;
	
	while(e<10){
		e += 2;
		printf("%d\n", e);
	}
	return 0;
}
