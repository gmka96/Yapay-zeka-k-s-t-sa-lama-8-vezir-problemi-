#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
struct eleme {
	int sayi;
	struct eleme *next;
};
typedef struct eleme eleme;
int sayi = 0, dizi[8] = { -1,-1,-1,-1,-1,-1,-1,-1 }, k, eklenecek[16];
eleme *head;
void *olustur()
{
	eleme *p = head, *g = head;
	for (int i = 0; i < 8; i++)
	{
		if (sayi == 0)
		{
			head = (eleme *)malloc(sizeof(eleme));
			p = head;
		}
		else
		{
			p->next = (eleme *)malloc(sizeof(eleme));
			p = p->next;
		}
		sayi++;
		p->sayi = i;
		p->next = NULL;
	}
	p = head;
	printf("\n\n");
	printf("\n(OLUSTURMA)Dizideki sayilar:");
	while (p != NULL)
	{
		printf("\t%d", p->sayi);
		p = p->next;
	}
	return NULL;
}
void *ekle(int deger)
{
	eleme *p, *g;
	p = head;
	g = head;
	if (head != NULL)
	{
		while (p != NULL)
		{
			g = p;
			p = p->next;
		}
		g->next = (eleme *)malloc(sizeof(eleme));
		g = g->next;
		g->sayi = deger;
		g->next = NULL;
		printf("\n\n");
		printf("\n(EKLEME)Dizideki sayilar:");
		p = head;
		while (p != NULL)
		{
			printf("\t%d", p->sayi);
			p = p->next;
		}
		sayi++;
		return NULL;
	}
	
}

void *sil(int deger)
{
	eleme *g, *p;
	p = head;
	g = head;
	if (head != NULL)
	{
		if (head->sayi == deger)
		{
			p = p->next;
			free(head);
			head = p;
		}
		else
		{
			p = head;
			g = head;
			while (p != NULL&&p->sayi != deger)
			{
				g = p;
				p = p->next;
			}
			g->next = p->next;
			free(p);
			p = g->next;
		}
		printf("\n(SIL)Dizideki sayilar:");
		p = head;
		while (p != NULL)
		{
			printf("\t%d", p->sayi);
			p = p->next;
		}
		sayi--;
		return NULL;
	}



}
int arama(int deger)
{
	eleme *p;
	p = head;
	while (p != NULL)
	{
		if (p->sayi == deger)
		{
			return 1;
			break;
		}
		else
		{
			p = p->next;
		}
	}
	return 0;

}
int arama2(int deger)
{
	for (int i = 0; i < 8; i++)
	{
		if (dizi[i] == deger)
			return 1;
	}
	return 0;
}
void silOnceki() {
	int t = k + 1;
	if (k >= 1)
	{
		for (int i = 0; i < k; i++)
		{
			if (dizi[i] - (t - i) >= 0 && arama(dizi[i] - (t - i)) == 1 && head != NULL)
			{
				sil(dizi[i] - (t - i));
				eklenecek[k - 1] = dizi[i] - (t - i);
			}

			if (dizi[i] + (t - i) <= 7 && arama(dizi[i] + (t - i)) == 1 && head != NULL)
			{
				sil(dizi[i] + (t - i));
				eklenecek[k] = dizi[i] + (t - i);
			}

		}

	}

}
void ekleOnceki() {
	if (k >= 1)
	{
		for (int i = 0; i < k * 2; i++)
		{
			if (eklenecek[i] >= 0 && eklenecek[i] <= 7 && arama(eklenecek[i]) == 0 && arama2(eklenecek[i]) == 0)
				ekle(eklenecek[i]);

		}

	}

}



int main()
{

	system("color 0b");
	int v, size = 8, a;
	char z = 178;


	while (1)
	{
		int tahta[8][8] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		olustur();
		srand(time(NULL));
		for (k = 0; k < 8; k++)





		{



			v = 0 + rand() % 7;
			while (1)
			{
				
				if (arama2(v) == 1 || arama(v) == 0)
					v = 0 + rand() % 8;
				else
					break;

			}
			a = v;
			dizi[k] = v;
			printf("\n");
			for (int t = 0; t<8; t++)
				printf("%d", dizi[t]);



			tahta[k][v] = z;
			printf("\tRASGELE:%d", v);
			for (int i = 0; i<8; i++)
			{
				printf("\n\n");
				for (int j = 0; j<8; j++)
				{
					if (tahta[i][j] != 0)
						printf("%c\t", tahta[i][j]);
					else
						printf("%d\t", tahta[i][j]);
				}

			}
			ekleOnceki();

			if (k >= 1)
			{

				if (dizi[k - 1] + 1 <= 7 && arama2(dizi[k - 1] + 1) != 1 && arama(dizi[k - 1] + 1) != 1)
					ekle(dizi[k - 1] + 1);
				if (dizi[k - 1] - 1 >= 0 && arama2(dizi[k - 1] - 1) != 1 && arama(dizi[k - 1] - 1) != 1)
					ekle(dizi[k - 1] - 1);



			}
			if (arama(v) == 1 && head != NULL)
				sil(v);
			if (arama(v + 1) == 1 && arama(v + 1) <= 7 && head != NULL)
				sil(v + 1);
			if (arama(v - 1) == 1 && arama(v - 1) >= 0 && head != NULL)
				sil(v - 1);
			silOnceki();
			/*	for(int t=0;t<8;t++)
			if(tahta[7][t]==178)
			break;
			*/
		}







	}








}