/* Визначити найбільший спільний дільник для двох заданих чисел*/
int main() {
	int  ch1=14, ch2=35;
	while (ch1!=0&&ch2!=0){
		if (ch1>ch2){
			ch1=ch1%ch2;
		} else {
			ch2=ch2%ch1;
		}
	}
	int nod = ch1+ch2;
	/*int j = 1;
	for (int i=ch1; i!=0 && j!=0;i=ch1){
		if (ch1>ch2){
			ch1=ch1%ch2;
		} else {
			ch2=ch2%ch1;
		}
		j = ch2;
	}int nod = ch1+ch2;*/
	/*
	do{if (ch1>ch2){
			ch1=ch1%ch2;
		} else {
			ch2=ch2%ch1;
		}
	}while (ch1!=0&&ch2!=0);
	int nod = ch1+ch2;
	*/
	return 0;
}
