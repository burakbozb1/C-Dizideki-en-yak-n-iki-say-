/*
06.11.2020
Burak Boz

Brute Force yakla��m� ile dizideki en yak�n iki eleman� tespit etme
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void main()
{
	srand(time(NULL));//Random methodu kullan�ld���nda farkl� say�lar �retmek i�in kullan�l�r
	
	printf("*** Dizideki en yakin iki elemani brute force ile tespit eden program | Soru 1 - Part 1 ***\n\n");
	
	int elemanSayisi;//Dizinin ka� elemanl� olaca�� kullan�c� taraf�ndan girilecektir
	int indexler [2];//Bulunan en yak�n iki eleman�n index numaralar�n� tutacak olan dizi
	int enKucukFark=100;//Bulunan en k���k fark� tutmak i�in kullan�lacak de�i�ken
	int geciciFark=0;//Say�lar aras�ndaki farklar� ge�ici olarak saklamak i�in kullan�lacak de�i�ken
	
	printf("Lutfen dizinin eleman sayisini girin:");
	scanf("%d",&elemanSayisi);
	
	int dizi[elemanSayisi];//Elemanlar�n tutuldu�u dizi, Elemanlar 1 ile 100 aras� olacakt�r
	
	int i =0;//D�ng�lerde kullan�lacak olan de�i�ken
	int j =0;//D�ng�lerde kullan�lacak olan de�i�ken
	
	for(i = 0;i<elemanSayisi;i++)//Diziyi rastgele say�larla doldurduk
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
