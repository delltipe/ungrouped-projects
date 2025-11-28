#include <stdio.h>
int main() {
	//boolean = true/false
	
	//format if
	//if (condition) {}
	//if else (condition) {}
	//else {}
	
	//true = 1
	//false = 0
//	if (false) {
//		printf ("Benar\n");
//	}
	
	//logical operators < > == !=
//	int number;
//	scanf ("%d", &number);
//	if (number > 0) {
//		printf ("lebih besar dari 0\n");
//	}
//	else if (number<0) {
//		printf ("lebih kecil dari 0\n");
//	}
//	else {
//		printf ("sama dengan 0\n");
//	}

	//switch case deafult, mirip if
//	switch(yg mau dibandingkan) {}
//	case <sama apa>:{
//		break;
//	}
//	default:{
//		break;
//	}

//	int number;
//	scanf ("%d", &number);
//	switch (number) {
//		case 1: {
//			//apa yang di-run kalau kondisi sama
//			printf ("satu\n");
//			break; //menghentikan switch
//		}
//		case 2: {
//			printf ("dua\n");
//			break;
//		}
//		case 3: {
//			printf ("tiga\n");
//			break;
//		}
//		default: { //mirip else
//			printf("gak nemu");
//			break;
//		}
//	}

//	//logical operators < > == !=
//	// if else lite version [cuma bisa if else]
//	int number1;
//	int number2;
//	scanf("%d %d", &number1, &number2);
//	//true atau false
//	//<kondisi> ? <benar> : <salah>
//	printf("kondisi: number1 > number2\n");
//	printf("%s", number1 > number2 ? "true" : "false");
	
//	//boolean stuff
//	bool condition = true;
//	printf("%s", condition ? "true" : "false");

//	int number1, number2, number3;
//	scanf("%d %d %d", number1, number2, number3);
//	//cari angka terbesar
//	//cek apakah number1 > number2
//	//               true1 or false1?  true1: true2 or false2? true2       false2    false1:true2 or false2? true2       false2
//	printf("%s\n", number1 > number2 ? (number1 > number3 ? "number1" : "number3") : (number2 > number3 ? "number2" : "number3"));

//	//scopes
//	int money=500
//	int age;
//	scanf("%d", &age);
//	if(age>17){
//		int money=1000
//		money-=200;
//		//money=money-200
//		printf("%d\n", money); //mengikuti int di dalam scope if
//	}
//	printf("%d\n", money); // mengikuti int di luar scope if
	
//	int money=2000;
//	if(true){
//		int debt=1000;
//		printf("%d\n", debt);
//		printf("%d\n", money); //koding masih bisa karna int di luar scope if dapat di akses
//	}
//	printf("%d\n", debt); //tidak akan bisa karna scope di luar if tidak bisa mengakses yg di dalam scope if
//	printf("%d\n", money);

//	//nested if
//	int height=170;
//	int age=17;
//	char gender='M';
//	if(height>=170){
//		if(age>=17){
//			if(gender=='M'){
//				printf("dapet hadiahh\n");
//			}
//		}
//	}
//	//bentuk rapihh
//	if(height>=170 && age>=17 && gender=='M'){
//		printf("dapet hadiahh\n");
//	}
	
//	//ASCII
//	printf("%d\n", '1');
//	//perbedaan angka huruf ascii besar dengan kecil = 32
//	printf("%c\n", 'B'+32);
//	//ngecek huruf kecil atau besar
//	char karakter='a';
//	if(karakter>='a' && karakter<='z'){
//		printf("huruf kecil");
//	}
//	else if(karakter>='A' && karakter<='Z'){
//		printf("huruf besar");
//	}
//	else{
//		printf("bukan huruf");
//	}

	//cara kerja if
	//gak dikasih operator,
	//if apakah valuenya NULL = salah
	//if else apakah valuenya 0 = salah
	//if else apakah valuenya 1 = benar
	//else = benar
	//NULL = ga ada isi
	
	//konvensi penamaan variabel:
	//- HARUS JELAS
	//- C, C++, DAN JAVASCRIPT=camelCase
	//  namaSayaSen=nama saya sen
	//- PYTHON=snake_case
	//- JAVA=camelCase, PascalCase
	//- untuk variabel biasakan sediakan valuenya!
	//  int namaSaya; value=NULL, SEBAIKNYA
	//  int namaSaya=0;

	return 0;
}
