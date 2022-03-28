#include<iostream>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int ucbasamak(int k[5], int toplam, int b, int o);
int ikibasamak(int k[5], int toplam, int b, int o, int ikibsmk);
int main()
{
	int k[5], o, b, toplam = 0;
	for (int i = 0; i < 5; i++) {
		k[i] = 1 + rand() % 9;
		cout << "otomatik olusturulan " <<i+1<<".sayi :" << k[i] << "\n";
	}
	o = (1 + (rand() % 9)) * 10;
	b = rand() % (898) + 100;
	cout << "otomatik olusturulan ondalikli sayi: " << o << "\n" << "otomatik olusturulan Tahmin edilecek sayi: " << b << "\n";
	int tmp, ucbsmk, ikibsmk;
	for (int j = 0; j < 4; j++) { //Diziyi kucukten buyuge siraladik
		for (int i = 0; i < 4; i++) {
			if (k[i] > k[i + 1]) {
				tmp = k[i];
				k[i] = k[i + 1];
				k[i + 1] = tmp;
			}
		}
	}
	ucbsmk = ucbasamak(k, toplam, b, o);
	ikibsmk = b - ucbsmk;
	toplam = ucbsmk + ikibasamak(k, toplam, b, o, ikibsmk);
	cout <<"Bulunan sayi : " << toplam << "\n";
	return 1;
}
int ucbasamak(int k[5], int toplam, int b, int o) {
	int i = 4;
	while (toplam < b) {
		for (int j = 0; j <= 4; j++) {
			if (toplam + (k[i] * o) > b)
				i--;
		}
		if (i == -1)
			break;
		toplam += k[i] * o;

	}
	return toplam;
}
int ikibasamak(int k[5], int toplam, int b, int o, int ikibsmk) {
	int i = 4;
	while (toplam < b) {
		for (int j = 0; j <= 4; j++) {
			if (toplam + (k[i] + 0) > ikibsmk)
				i--;
		}
		if (i == -1)
			break;
		toplam += k[i];

	}
	return toplam;
}