/* За заданим радіусом r та командою ('l', 's' або 'v') користувача обчислити:
- довжину окружності, якщо команда - 'l'
- площу кола, якщо команда - 's'
- об'єм кулі, якщо команда - 'v'*/
int main() {
	int  r=10;
	char com = 's';
	#define pi 3.14
	//Задається значення радіуса r, та команда 
	if (com == 'l'){
	
		int rez = 2*pi*r;
	
	} else if (com == 's'){
		
		int rez = pi*r*r;
	
	} else if (com == 'v'){
		
		int rez = 4/3*pi*r*r*r;
	
	} else {
	//некорректна команда
	}
	return 0;
}
