// Підрахувати добуток чисел у заданому діапазоні. Наприклад, при вхідних даних 50 та 52 повинно бути 50*51*52 = 132600.
/*Використовуючи формулу Стірлінга для приблизного визначення факторіалу чисел
int main() {
	int  ch1=50, ch2= 52;
	const double e = 2.71828182846;
	const double pi = 3.14;
	int rez = (sqrt(2*pi*ch2)*pow(ch2, ch2)*pow(e, 1/ch2))-(sqrt(2*pi*ch1)*pow(ch1, ch1)*pow(e, 1/ch1));
	prinf ("rez : %.20f\n");
	return 0;
}*/
int main() {
	int ch1=50, ch2=52;
	int rez = ((ch1+ch2)/2)*(ch2-ch1+1);
	return 0;
}
