/*
06.11.2020
Burak Boz

Dizideki en yakýn iki elemaný tespit etme

Bu programda dizi önce merge sort ile sýralanacak ve sýralý ikili elemanlar kontrol edilerek en küçük fark bulunacak
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* Kullanýlacak geçici deðiþkenler */
    int L[n1], R[n2]; 
  
    /* Sol ve sað deðerler geçici deðiþkenlere kopyalanýyor */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Geçici deðiþkenler dizi ile birleþtiriliyor*/
    i = 0; // altdizinin ilk deðerinin ayarlanmasý için 
    j = 0; // altdizinin ikinci deðerinin ayarlanmasý için
    k = l; // Birleþtirilecek dizi için
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    //Sol dizide eleman kaldýysa diziye kopyalanmasý
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }
    /* Sað dizide eleman kaldýysa diziye kopyalanmasý*/
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) //Dizinin sýralanmasý için kullanýlan fonksiyon
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r); 
    } 
} 

void main()
{
	srand(time(NULL));//Random methodu kullanýldýðýnda farklý sayýlar üretmek için kullanýlýr
	
	printf("*** Dizideki en yakin iki elemani tespit eden program | Soru 1 - Part 2 ***\n\n");
	
	int elemanSayisi;//Dizinin kaç elemanlý olacaðý kullanýcý tarafýndan girilecektir
	int indexler [2];//Bulunan en yakýn iki elemanýn index numaralarýný tutacak olan dizi
	int enKucukFark=100;//Bulunan en küçük farký tutmak için kullanýlacak deðiþken
	int geciciFark=0;//Sayýlar arasýndaki farklarý geçici olarak saklamak için kullanýlacak deðiþken
	
	printf("Lutfen dizinin eleman sayisini girin. Elemanlar 1 ile 100 arasinda rastgele sayilardan olusturulacaktir:");
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
	
	
	mergeSort(dizi, 0, elemanSayisi - 1); //Dizi sýralanýyor
	
	for(i=0;i<elemanSayisi-1;i++)
	{
		geciciFark=abs(dizi[i]-dizi[i+1]);
		if(geciciFark<enKucukFark)
		{
			enKucukFark=geciciFark;
			indexler[0]=dizi[i];
			indexler[1]=dizi[i+1];
		}
	}
	
	printf("En Kucuk fark:%d\n",enKucukFark);
	printf("Sayilar: %d - %d",indexler[0],indexler[1]);
	
	
}
