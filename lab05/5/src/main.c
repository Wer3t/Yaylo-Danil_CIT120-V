// Без допомоги зовнішніх бібліотек отримати корень числа
int main() {
	int ch = 100, kor;
	for (int i=0; i<=ch; i++){
		if (ch == i*i){
			kor = i;
			//корень числа найден
			break;
		}
	}
	/*
	int i=0;
	while(i<=ch){
		if (ch == i*i){
			kor = i;
			//корень числа найден
			break;
		}
		i++;
	}*/
	/*
	int i=0;
	do{
	if (ch == i*i){
			kor = i;
			//корень числа найден
			break;
		}
		i++;
		}
		while(i<=ch);*/
	return 0;
}
