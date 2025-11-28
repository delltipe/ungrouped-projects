#include <stdio.h>
//#include <windows.h>

int main()
{
//	looping!!!
//	uncounted loop: jumlah perulangannya
//					tidak tentu

//	WHILE
//	char decision='y';
//	while(decision=='y')
//	{
//		printf("ingin mengulang? (y/t): ");
//		scanf("%c", &decision);
//		getchar();
//	}

//	PERBEDAAN WHILE DENGAN DO-WHILE
//	WHILE: baca syarat lalu lakukan
//	int a=0;
//	while(a<5)
//	{
//		printf("%d. While\n",a);
//		a++;
//	}
//	DO-WHILE: lakukan lalu baca syarat
//	do
//	{
//		printf("%d. DO-WHILE\n",a);
//		a++;
//	}
//	while(a<5);

//	counted loop

//	WHILE BISA BERUBAH COUNTABLE LOOP				
//	int n=0;
//	while(n<10)
//	{
//		printf("Hello World!\n");
//		n++;//n+1
//	}

//	FOR
//	for(value awal;syarat looping;action value)
//	{
//		action statement
//	}
//	int i;
//	for(i=0;i<5;i++)
//	{
//		printf("%d. FOR increment\n",i);
//	}
//	printf("\n\n");
//	for(i=5;i>0;i--)
//	{
//		printf("%d. FOR decrement\n",i);
//	}

//	NESTED LOOPING
//	int i;
//	for(i=0;i<5;i++)
//	{
//		int j;
//		for(j=0;j<5;j++)
//		{
////			Sleep(1000); //penundaan 1000 milisecond=1 detik
//			printf("%d,%d ",i,j);
//		}
//		puts("");//printf("\n")
//	}
//	int baris;
//	scanf("%d",&baris);
//	getchar();
//	int i;
//	for(i=0;i<baris;i++)
//	{
//		int j;
//		for(j=0;j<=i;j++)
//		{
//			printf("*");
//		}
//		puts("");
//	}
	
//		system("cls")
		int choice;
		printf("Silahkan dipilih!\n");
		printf("=================\n");
		printf("1. Segitiga siku-siku terbalik\n");
		printf("2. Trapesium\n");
		printf("3. Segitiga siku-siku bolong\n");
		printf("4. Exit\n");
		printf("Masukkan pilihan (1-4): ");
		scanf("%d", &choice);
		if(choice==1)
		{
			int baris;
			int decision;
			printf("Masukkan banyak baris: ");
			scanf("%d", &baris);getchar();
			int i;
			for(i=0;i<baris;i++)
			{
				int j;
				for(j=baris-i;j>0;j--)
				{
					printf("*");
				}
				puts("");
			}
			puts("");
			printf("Ingin mengulang? (y/t): ");
			scanf("%c",&decision);getchar();
		}
	
//	printf("Perulangan Selesai.\n");
	return 0;
}
