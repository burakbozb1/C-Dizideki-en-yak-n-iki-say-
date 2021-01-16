/*
06.11.2020
Burak Boz

Brute Force yaklaþýmý ile dizideki en yakýn iki elemaný tespit etme
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void main()
{
	srand(time(NULL));//Random methodu kullanýldýðýnda farklý sayýlar üretmek için kullanýlýr
	
	printf("*** Dizideki en yakin iki elemani brute force ile tespit eden program | Soru 1 - Part 1 ***\n\n");
	
	int elemanSayisi;//Dizinin kaç elemanlý olacaðý kullanýcý tarafýndan girilecektir
	int indexler [2];//Bulunan en yakýn iki elemanýn index numaralarýný tutacak olan dizi
	int enKucukFark=100;//Bulunan en küçük farký tutmak için kullanýlacak deðiþken
	int geciciFark=0;//Sayýlar arasýndaki farklarý geçici olarak saklamak için kullanýlacak deðiþken
	
	printf("Lutfen dizinin eleman sayisini girin:");
	scanf("%d",&elemanSayisi);
	
	int dizi[elemanSayisi];//Elemanlarýn tutulduðu dizi, Elemanlar 1 ile 100 arasý olacaktýr
	
	int i =0;//Döngülerde kullanýlacak olan deðiþken
	int j =0;//Döngülerde kullanýlacak olan deðiþken
	
	for(i = 0;i<elemanSayisi;i++)//Diziyi rastgele sayýlarla doldurduk
	{
		dizi[i]=rand()%100;
	}
	for(i = 0;i<elemanSayisi;i++)//Diziyi yazdirma
	{
		printf("%d. sayi : %d\n",i+1,dizi[i]);
	}
	printf("\n\n");
	
	
	
	for(i=0;i<elemanSayisi;i++)
	{
		for(j=0;j<elemanSayisi;j++)
		{
			if(i!=j)
			{
				geciciFark=abs(dizi[i]-dizi[j]);
				if(geciciFark<enKucukFark)
				{
					enKucukFark=geciciFark;
					indexler[0]=dizi[i];
					indexler[1]=dizi[j];
				}
			}
			
		}
	}
	
	printf("Bulunan en kucuk fark:%d\n",enKucukFark);
	printf("Sayilar: %d - %d",indexler[0],indexler[1]);
	
}
