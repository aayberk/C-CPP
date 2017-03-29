#include <stdio.h>
#include <stdlib.h>
//int xx=0;		xx deðiþkeni kaçýncý adýmda olduguna bakýyor
void kontrol(int * gelenDizi, int satir, int sutun)
{
	int c, d;
	int dizi[20][20];
	//0 toplama    1 carpma
	int sonrakiIslem = 0;
	int r = 0;
	int i = satir;
	int j = sutun;
	for (c = 0; c<i; c++){
		for (d = 0; d<j; d++){
			dizi[c][d] = gelenDizi[r]; r++;
		}
	}
	//olumlu olumsuz cevabi alamasi için bool olusturulur
	bool bo = true;
	//tum islemler0
	for (c = 0; c < i; c++)
	{
		if(c%2==0){
			sonrakiIslem=0;
		}else{
			sonrakiIslem=1;
		}
		for (d = 0; d < j; d++)
		{
			if (c == 0 && d == j - 1)
			{
				if ((c % 2 == 0 && d % 2 == 1) || (c % 2 == 1 && d % 2 == 0)){
					if (sonrakiIslem == 1){
						sonrakiIslem = 0;
						if (dizi[c][d] != dizi[c + 1][d] * dizi[c][d - 1]){ bo = false; return;}
					}
					else if (sonrakiIslem == 0){
						sonrakiIslem = 1;
						if (dizi[c][d] != dizi[c + 1][d] + dizi[c][d - 1]){ bo = false; return;}
					}
				}
			}
			else if (c == i - 1 && d == 0)
			{
				if ((c % 2 == 0 && d % 2 == 1) || (c % 2 == 1 && d % 2 == 0)){
					if (sonrakiIslem == 1){
						sonrakiIslem = 0;
						if (dizi[c][d] != dizi[c - 1][d] * dizi[c][d + 1]){ bo = false; return;}
					}
					else if (sonrakiIslem == 0){
						sonrakiIslem = 1;
						if (dizi[c][d] != dizi[c - 1][d] + dizi[c][d + 1]){ bo = false; return;}
					}
				}
			}
			else if (c == i - 1 || d == j - 1)
			{
				if (c == i - 1 && d == j - 1){
					if ((c % 2 == 0 && d % 2 == 1) || (c % 2 == 1 && d % 2 == 0)){
						if (sonrakiIslem == 1){
							sonrakiIslem = 0;
							if (dizi[c][d] != dizi[c - 1][d] * dizi[c][d - 1]){ bo = false; return;}
						}
						else if (sonrakiIslem == 0){
							sonrakiIslem = 1;
							if (dizi[c][d] != dizi[c - 1][d] + dizi[c][d - 1]){ bo = false; return;}
						}
					}
				}
				else if (c == i - 1){
					if ((c % 2 == 0 && d % 2 == 1) || (c % 2 == 1 && d % 2 == 0)){
						if (sonrakiIslem == 1){
							sonrakiIslem = 0;
							if (dizi[c][d] != dizi[c - 1][d] * dizi[c][d - 1] * dizi[c][d + 1]){ bo = false; return;}
						}
						else if (sonrakiIslem == 0){
							sonrakiIslem = 1;
							if (dizi[c][d] != dizi[c - 1][d] + dizi[c][d - 1] + dizi[c][d + 1]){ bo = false; return;}
						}
					}
				}
				else if (d == j - 1){
					if ((c % 2 == 0 && d % 2 == 1) || (c % 2 == 1 && d % 2 == 0)){
						if (sonrakiIslem == 1){
							sonrakiIslem = 0;
							if (dizi[c][d] != dizi[c - 1][d] * dizi[c + 1][d] * dizi[c][d - 1]){ bo = false; return;}
						}
						else if (sonrakiIslem == 0){
							sonrakiIslem = 1;
							if (dizi[c][d] != dizi[c - 1][d] + dizi[c + 1][d] + dizi[c][d - 1]){ bo = false; return;}
						}
					}
				}
			}
			else if (c == 0 || d == 0)
			{
				if (c == 0 && d == 0){
					if ((c % 2 == 0 && d % 2 == 1) || (c % 2 == 1 && d % 2 == 0)){
						if (sonrakiIslem == 1){
							sonrakiIslem = 0;
							if (dizi[c][d] != dizi[c + 1][d] * dizi[c][d + 1]){ bo = false; return;}
						}
						else if (sonrakiIslem == 0){
							sonrakiIslem = 1;
							if (dizi[c][d] != dizi[c + 1][d] + dizi[c][d + 1]){ bo = false; return;}
						}
					}
				}
				else if (c == 0){
					if ((c % 2 == 0 && d % 2 == 1) || (c % 2 == 1 && d % 2 == 0)){
						if (sonrakiIslem == 1){
							sonrakiIslem = 0;
							if (dizi[c][d] != dizi[c + 1][d] * dizi[c][d - 1] * dizi[c][d + 1]){ bo = false; return;}
						}
						else if (sonrakiIslem == 0){
							sonrakiIslem = 1;
							if (dizi[c][d] != dizi[c + 1][d] + dizi[c][d - 1] + dizi[c][d + 1]){ bo = false; return;}
						}
					}
				}
				else if (d == 0){
					if ((c % 2 == 0 && d % 2 == 1) || (c % 2 == 1 && d % 2 == 0)){
						if (sonrakiIslem == 1){
							sonrakiIslem = 0;
							if (dizi[c][d] != dizi[c - 1][d] * dizi[c + 1][d] * dizi[c][d + 1]){ bo = false; return;}
						}
						else if (sonrakiIslem == 0){
							sonrakiIslem = 1;
							if (dizi[c][d] != dizi[c - 1][d] + dizi[c + 1][d] + dizi[c][d + 1]){ bo = false; return;}
						}
					}
				}
			}
			else if (c>0 && d > 0)
			{
				if ((c % 2 == 0 && d % 2 == 1) || (c % 2 == 1 && d % 2 == 0)){
					if (sonrakiIslem == 1){
						sonrakiIslem = 0;
						if (dizi[c][d] != dizi[c - 1][d] * dizi[c + 1][d] * dizi[c][d - 1] * dizi[c][d + 1]){ bo = false; return;}
					}
					else if (sonrakiIslem == 0){
						sonrakiIslem = 1;
						if (dizi[c][d] != dizi[c - 1][d] + dizi[c + 1][d] + dizi[c][d - 1] + dizi[c][d + 1]){ bo = false; return;}
					}
				}
			}
		}
	}
	//sonucun ekrana yazilmasi
		if (bo == true)
		{	printf("\nACCEPTABLE\n");
		for (c = 0; c<i; c++){
			for (d = 0; d<j; d++){
				printf("%d	", dizi[c][d]);
			}
			printf("\n");
		}printf("\n");}
	//	else
	//	printf("\n NOT MATCH");
}
int x = 0;int sayac=0;
int yeniDizi[400];
void siraDegistir(int satir, int sutun, int *gelenDizi,int basla)
{
	int a;
	int eskiDizi[400];
	for (a = 0; a < satir*sutun; a++)
	{
		int c;
		
		for (c = 0; c < satir*sutun; c++)
		{
			eskiDizi[c] = gelenDizi[c];
		}
		if (eskiDizi[a] != -1){
			yeniDizi[basla] = eskiDizi[a];
			eskiDizi[a] = -1;
			if (basla<satir*sutun){
				siraDegistir(satir, sutun, eskiDizi,basla+1);
			}
		}
		if (basla== satir*sutun){
		//	xx++;
			kontrol(yeniDizi, satir, sutun);basla++;
		//	printf("%d\n",xx);
		}
	}
}
int main(int argc, char * argv[])
{
	int satir, sutun;
	int tablo[400];
	int c, basla = 0;
	satir = atoi(argv[1]);
	sutun = atoi(argv[2]);
	int r = 3;
	for (c = 0; c < satir*sutun; c++)
	{
		tablo[c] = atoi(argv[r]);
		r++;
	}
	//	iþlemleri yapan fonksiyonun cagrilmasi
	siraDegistir(satir, sutun, tablo,basla);
//	system("PAUSE");
	return 0;
}
