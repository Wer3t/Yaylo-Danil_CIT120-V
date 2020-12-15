#include "stdio.h"
//Центрувати заданий рядок на площині із заданим заповнювачем
int main() {
	const char zapovnuvach = '_';
	const int N = 16;
	char mas[16] = " Ivanov         ";
	int pusto = 0, s = 0, e = 0, j=0;
	for (int i =0; i<N; i++){
		if (mas[i] == ' '){
			pusto++;
		}
		if (mas[i]!=' '&&mas[i-1]==' '){
			s = i;
		}
		if (mas[i]!=' '&&mas[i+1]==' '){
			e = i;
		}
	}
	pusto/=2;
	int N2 = e-s+1;
	char mas2 [N2];
	for (int i = 0; i<N2; i++){
		mas2[i]=mas[s+i];
	}
	for (int i=0; i<pusto; i++){
		mas[i]=zapovnuvach;
	}
	N2+=pusto;
	for (int i = pusto; i<N2; i++){
		mas [i] = mas2[j];
		j++;
	}
	for (int i = N2; i<N; i++){
		mas[i] = zapovnuvach;
	}
	for (int i = 0; i<N; i++){
		printf("%c", mas[i]);
	}
	return 0;
}
