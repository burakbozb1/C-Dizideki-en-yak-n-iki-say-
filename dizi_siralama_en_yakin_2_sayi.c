/*
06.11.2020
Burak Boz

Dizideki en yak�n iki eleman� tespit etme

Bu programda dizi �nce merge sort ile s�ralanacak ve s�ral� ikili elemanlar kontrol edilerek en k���k fark bulunacak
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* Kullan�lacak ge�ici de�i�kenler */
    int L[n1], R[n2]; 
  
    /* Sol ve sa� de�erler ge�ici de�i�kenlere kopyalan�yor */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Ge�ici de�i�kenler dizi ile birle�tiriliyor*/
    i = 0; // altdizinin ilk de�erinin ayarlanmas� i�in 
    j = 0; // altdizinin ikinci de�erinin ayarlanmas� i�in
    k = l; // Birle�tirilecek dizi i�in
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
    //Sol dizide eleman kald�ysa diziye kopyalanmas�
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }
    /* Sa� dizide eleman kald�ysa diziye kopyalanmas�*/
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) //Dizinin s�ralanmas� i�in kullan�lan fonksiyon
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
	srand(time(NULL));//Random methodu kullan�ld���nda farkl� say�lar �retmek i�in kullan�l�r
	
	printf("*** Dizideki en yakin iki elemani tespit eden program | Soru 1 - Part 2 ***\n\n");
	
	int elemanSayisi;//Dizinin ka� elemanl� olaca�� kullan�c� taraf�ndan girilecektir
	int indexler [2];//Bulunan en yak�n iki eleman�n index numaralar�n� tutacak olan dizi
	int enKucukFark=100;//Bulunan en k���k fark� tutmak i�in kullan�lacak de�i�ken
	int geciciFark=0;//Say�lar aras�ndaki farklar� ge�ici olarak saklamak i�in kullan�lacak de�i�ken
	
	printf("Lutfen dizinin eleman sayisini girin. Elemanlar 1 ile 100 arasinda rastgele sayilardan olusturulacaktir:");
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
	
	
	mergeSort(dizi, 0, elemanSayisi - 1); //Dizi s�ralan�yor
	
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
