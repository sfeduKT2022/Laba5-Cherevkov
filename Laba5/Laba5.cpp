#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#define N 20

struct Stadion {
	char title[30];
	char sporttype[30];
	int yearcreation;
	char addres[40];
	int vmestimost;
	int countarea;
	int tablo;
};

typedef Stadion* Sstadion;
Stadion stad[N];
Sstadion st[N];

void addingdata(int k)
{
	for (int i = 0; i < k; i++) {
		printf("Введите название стадиона: ");
		scanf("%s", &stad[i].title);
		printf("Введите название спорта: ");
		scanf("%s", &stad[i].sporttype);
		printf("Введите год постройки стадиона: ");
		scanf("%d", &stad[i].yearcreation);
		while (stad[i].yearcreation < 1800 || stad[i].yearcreation > 2022) {
			printf("Введите корректные данные: ");
			scanf("%d", &stad[i].yearcreation);
		}
		printf("Введите адрес стадиона: ");
		scanf("%s", &stad[i].addres);
		printf("Введите вместимость стадиона: ");
		scanf("%d", &stad[i].vmestimost);
		while (stad[i].vmestimost < 0 || stad[i].vmestimost > 200000) {
			printf("Введите корректные данные: ");
			scanf("%d", &stad[i].vmestimost);
		}
		printf("Введите количество площадок: ");
		scanf("%d", &stad[i].countarea);
		while (stad[i].countarea < 0 || stad[i].countarea > 10000) {
			printf("Введите корректные данные: ");
			scanf("%d", &stad[i].countarea);
		}
		printf("Введите счет: ");
		scanf("%d", &stad[i].tablo);
		while (stad[i].tablo < 0 || stad[i].tablo > 10000) {
			printf("Введите корректные данные: ");
			scanf("%d", &stad[i].tablo);
		}
	}
}

void Recordd(FILE* f, int i)
{
	fprintf(f, "%s\t", stad[i].title);
	fprintf(f, "%s\t", stad[i].sporttype);
	fprintf(f, "%d\t", stad[i].yearcreation);
	fprintf(f, "%s\t", stad[i].addres);
	fprintf(f, "%d\t", stad[i].vmestimost);
	fprintf(f, "%d\t", stad[i].countarea);
	fprintf(f, "%d\t\n", stad[i].tablo);
}


void Record(FILE* f, int i)
{
	fprintf(f, "%s\t", st[i]->title);
	fprintf(f, "%s\t", st[i]->sporttype);
	fprintf(f, "%d\t", st[i]->yearcreation);
	fprintf(f, "%s\t", st[i]->addres);
	fprintf(f, "%d\t", st[i]->vmestimost);
	fprintf(f, "%d\t", st[i]->countarea);
	fprintf(f, "%d\t\n", st[i]->tablo);
}



void SortTitle(Sstadion st[], int p)
{
	Sstadion per;
	int i, j;
	for (i = 0; i < p - 1; i++) {
		for (j = p - 2; j >= i; j--) {
			if (strcmp(st[j]->title, st[j + 1]->title) > 0) {
				per = st[j];
				st[j] = st[j + 1];
				st[j + 1] = per;
			}
		}
	}
}

void SortSporttype(Sstadion st[], int p)
{
	Sstadion per;
	int i, j;
	for (i = 0; i < p - 1; i++) {
		for (j = p - 2; j >= i; j--) {
			if (strcmp(st[j]->sporttype, st[j + 1]->sporttype) > 0) {
				per = st[j];
				st[j] = st[j + 1];
				st[j + 1] = per;
			}
		}
	}
}


void SortYearcreation(Sstadion st[], int p)
{
	Sstadion per;
	int i, j;
	for (i = 0; i < p - 1; i++) {
		for (j = p - 2; j >= i; j--) {
			if (st[j]->yearcreation > st[j + 1]->yearcreation) {
				per = st[j];
				st[j] = st[j + 1];
				st[j + 1] = per;
			}
		}
	}
}

void SortAddres(Sstadion st[], int p)
{
	Sstadion per;
	int i, j;
	for (i = 0; i < p - 1; i++) {
		for (j = p - 2; j >= i; j--) {
			if (strcmp(st[j]->addres, st[j + 1]->addres) > 0) {
				per = st[j];
				st[j] = st[j + 1];
				st[j + 1] = per;
			}
		}
	}
}

void SortVmestimost(Sstadion st[], int p)
{
	Sstadion per;
	int i, j;
	for (i = 0; i < p - 1; i++) {
		for (j = p - 2; j >= i; j--) {
			if (st[j]->vmestimost > st[j + 1]->vmestimost) {
				per = st[j];
				st[j] = st[j + 1];
				st[j + 1] = per;
			}
		}
	}
}

void SortCountarea(Sstadion st[], int p)
{
	Sstadion per;
	int i, j;
	for (i = 0; i < p - 1; i++) {
		for (j = p - 2; j >= i; j--) {
			if (st[j]->countarea > st[j + 1]->countarea) {
				per = st[j];
				st[j] = st[j + 1];
				st[j + 1] = per;
			}
		}
	}
}

void SortTablo(Sstadion st[], int p)
{
	Sstadion per;
	int i, j;
	for (i = 0; i < p - 1; i++) {
		for (j = p - 2; j >= i; j--) {
			if (st[j]->tablo > st[j + 1]->tablo) {
				per = st[j];
				st[j] = st[j + 1];
				st[j + 1] = per;
			}
		}
	}
}

void Func(FILE* f, int n, int k)
{
	for (int i = 0; i < k; i++) {
		st[i] = &stad[i];
	}
	switch (n) {
	case 1:
		SortTitle(st, k);
		for (int i = 0; i < k; i++) {
			Record(f, i);
		}
		break;

	case 2:
		SortSporttype(st, k);
		for (int i = 0; i < k; i++) {
			Record(f, i);
		}
		break;
	case 3:
		SortYearcreation(st, k);
		for (int i = 0; i < k; i++) {
			Record(f, i);
		}
		break;
	case 4:
		SortAddres(st, k);
		for (int i = 0; i < k; i++) {
			Record(f, i);
		}
		break;
	case 5:
		SortVmestimost(st, k);
		for (int i = 0; i < k; i++) {
			Record(f, i);
		}
		break;
	case 6:
		SortCountarea(st, k);
		for (int i = 0; i < k; i++) {
			Record(f, i);
		}
		break;
	case 7:
		SortTablo(st, k);
		for (int i = 0; i < k; i++) {
			Record(f, i);
		}
		break;
	}
	fprintf(f, "%s\n", "STOP");
}

void SearchTitle(FILE* f)
{
	char massiv[30];
	printf("Введите название стадиона: ");
	scanf("%s", &massiv);
	for (int i = 0; i < N; i++) {
		if (strcmp(massiv, stad[i].title) == 0) {
			Recordd(f, i);
		}
	}

}

void SearchSporttype(FILE* f)
{
	char massiv[30];
	printf("Введите название спорта: ");
	scanf("%s", &massiv);
	for (int i = 0; i < N; i++) {
		if (strcmp(massiv, stad[i].sporttype) == 0) {
			Recordd(f, i);
		}
	}

}

void SearchYearcreation(FILE* f)
{
	int per;
	printf("Введите год постройки: ");
	scanf("%d", &per);
	for (int i = 0; i < N; i++) {
		if (per == stad[i].yearcreation) {
			Recordd(f, i);
		}
	}

}

void SearchAddres(FILE* f)
{
	char massiv[30];
	printf("Введите адрес: ");
	scanf("%s", &massiv);
	for (int i = 0; i < N; i++) {
		if (strcmp(massiv, stad[i].addres) == 0) {
			Recordd(f, i);
		}
	}

}

void SearchVmestimost(FILE* f)
{
	int per;
	printf("Введите вместимость стадиона: ");
	scanf("%d", &per);
	for (int i = 0; i < N; i++) {
		if (per == stad[i].vmestimost) {
			Recordd(f, i);
		}
	}

}

void SearchCountarea(FILE* f)
{
	int per;
	printf("Введите количество площадок: ");
	scanf("%d", &per);
	for (int i = 0; i < N; i++) {
		if (per == stad[i].countarea) {
			Recordd(f, i);
		}
	}

}

void SearchTablo(FILE* f)
{
	int per;
	printf("Введите счет: ");
	scanf("%d", &per);
	for (int i = 0; i < N; i++) {
		if (per == stad[i].tablo) {
			Recordd(f, i);
		}
	}

}


void Func2(FILE* f, int n)
{
	printf("Выберите опцию, по которой будет происходить поиск: \n");
	printf("1 - Название стадиона\n");
	printf("2 - Название спорта\n");
	printf("3 - Год постройки\n");
	printf("4 - Адрес\n");
	printf("5 - Вместимость\n");
	printf("6 - Количество площадок\n");
	printf("7 - Счет\n");
	printf("0 - Завершение поиска\n");
	scanf("%d", &n);
	while ((n < 0) || (n > 7)) {
		printf("Введите число от 0 до 7!!!");
		scanf("%d", &n);
	}
	switch (n) {
	case 1:
		SearchTitle(f);
		break;
	case 2:
		SearchSporttype(f);
		break;
	case 3:
		SearchYearcreation(f);
		break;
	case 4:
		SearchAddres(f);
		break;
	case 5:
		SearchVmestimost(f);
		break;
	case 6:
		SearchCountarea(f);
		break;
	case 7:
		SearchTablo(f);
		break;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	FILE* f;
	int k, poz, j, n = 1;
	f = fopen("file.txt", "w");
	if (f == NULL)
	{
		puts("Error the open file!");
		return 0;
	}
	printf("Введите количество стадионов от 1 до 20: ");
	scanf("%d", &k);
	while ((k < 1) || (k > 20)) {
		printf("Введите корректные данные: ");
		scanf("%d", &k);
	}
	addingdata(k);
	printf("Выберите позицию:\n");
	printf("1 - добавление стадиона в базу данных;\n");
	printf("2 - поиск стадиона с заданным значением выбранного элемента;\n");
	printf("3 - вывод на экран содержимого базы данных;\n");
	printf("4 - упорядочение данных в базе по заданным элементам.\n");
	printf("Выбранная опция: ");
	scanf("%d", &poz);
	printf("\n");
	while ((poz < 1) || (poz > 4))
	{
		printf("Введите корректные данные: ");
		scanf("%d", &poz);
	}
	switch (poz)
	{
	case 1:
		printf("Введите количество стадионов, которые будут добавлены от 1 до %d: ", N - k);
		scanf("%d", &n);
		while ((n < 0) || (n > N - k)) {
			printf("Введите корректные данные: ");
			scanf("%d", &n);
		}
		for (j = 0; j < n; j++) {
			printf("Введите название стадиона: ");
			scanf("%s", &stad[k].title);
			printf("Введите название спорта: ");
			scanf("%s", &stad[k].sporttype);
			printf("Введите год постройки стадиона: ");
			scanf("%d", &stad[k].yearcreation);
			while (stad[k].yearcreation < 1800 || stad[k].yearcreation > 2022) {
				printf("Введите корректные данные: ");
				scanf("%d", &stad[k].yearcreation);
			}
			printf("Введите адрес стадиона: ");
			scanf("%s", &stad[k].addres);
			printf("Введите вместимость стадиона: ");
			scanf("%d", &stad[k].vmestimost);
			while (stad[k].vmestimost < 0 || stad[k].vmestimost > 200000) {
				printf("Введите корректные данные: ");
				scanf("%d", &stad[k].vmestimost);
			}
			printf("Введите количество площадок: ");
			scanf("%d", &stad[k].countarea);
			while (stad[k].countarea < 0 || stad[k].countarea > 10000) {
				printf("Введите корректные данные: ");
				scanf("%d", &stad[k].countarea);
			}
			printf("Введите счет: ");
			scanf("%d", &stad[k].tablo);
			while (stad[k].tablo < 0 || stad[k].tablo > 10000) {
				printf("Введите корректные данные: ");
				scanf("%d", &stad[k].tablo);
			}
			k++;
		}
		for (j = 0; j < k; j++) {
			fprintf(f, "%s\t%s\t%d\t%s\t%d\t%d\t%d\t\n", stad[j].title, stad[j].sporttype, stad[j].yearcreation, stad[j].addres, stad[j].vmestimost, stad[j].countarea, stad[j].tablo);
		}
		break;
	case 2:
		Func2(f, n);
		break;
	case 3:
		for (j = 0; j < k; j++) {
			printf("%s\t%s\t%d\t%s\t%d\t%d\t%d\t\n", stad[j].title, stad[j].sporttype, stad[j].yearcreation, stad[j].addres, stad[j].vmestimost, stad[j].countarea, stad[j].tablo);
			fprintf(f, "%s\t%s\t%d\t%s\t%d\t%d\t%d\t\n", stad[j].title, stad[j].sporttype, stad[j].yearcreation, stad[j].addres, stad[j].vmestimost, stad[j].countarea, stad[j].tablo);
		}
		while (n) {
			printf("1 - вывод содержимого\n");
			printf("0 - завершение вывода\n");
			scanf("%d", &n);
			while ((n < 0) || (n > 1)) {
				printf("Введите число от 0 до 1");
				scanf("%d", &n);
			}

		}
		for (j = 0; j < k; j++) {
			printf("%s\t%s\t%d\t%s\t%d\t%d\t%d\t\n", stad[j].title, stad[j].sporttype, stad[j].yearcreation, stad[j].addres, stad[j].vmestimost, stad[j].countarea, stad[j].tablo);
			fprintf(f, "%s\t%s\t%d\t%s\t%d\t%d\t%d\t\n", stad[j].title, stad[j].sporttype, stad[j].yearcreation, stad[j].addres, stad[j].vmestimost, stad[j].countarea, stad[j].tablo);
		}

		break;
	case 4:
		while (n)
		{
			printf("Выберите элемент, по которому будет происходить сортировка: \n");
			printf("1 - Название стадиона\n");
			printf("2 - Название спорта\n");
			printf("3 - Год постройки\n");
			printf("4 - Адрес\n");
			printf("5 - Вместимость\n");
			printf("6 - Количество площадок\n");
			printf("7 - Счет\n");
			printf("0 - Завершение сортировки\n");
			scanf("%d", &n);
			while ((n < 0) || (n > 7)) {
				printf("Введите число от 0 до 7!!!");
				scanf("%d", &n);
			}
			Func(f, n, k);
		}
	}
}
