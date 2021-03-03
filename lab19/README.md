# Загальне завдання
1. Реалізувати програму відповідно до індивідуального завдання.

#Індивідуальне завдання
1. Перетворити число в рядок.

**ВИКОНАННЯ РОБОТИ**
2.1 Функціональне призначення
	Програма призначена для перетворення числа в рядок.
2.2 Створення репозиторію
	Створивши репозиторій на github, клоную його та створюю всі файли за вимогами структури проекту. 
2.3 Написання коду програми
int task(int ch){
	int temp = 0;
	int temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;
	char res[100] = {0};
	const char mas1[10][10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	const char mas2[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 	  "nineteen"};
	const char mas3[10][15] = {"", "", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
 	const char mas4[10][15] = {"", "one hundred ", "two hundred ", "three hundred ", "four hundred ", "five hundred ", "six hundred 		", "seven hundred ", "eight hundred ", "nine hundred "};
	const char mas5[10][15] = {"", "one thousand ", "two thousand ", "three thousand ", "four thousand ", "five thousand ", "six 	  thousand ", "seven thousand ", "eight thousand ", "nine thousand "};
	if(ch>9999){
		return 0;
		//Число слишком большое
	}
	for (int i = 0; i <= ch / 1000; i++){
		temp = 0;
        	for (int j = 0; j < 15; j++){
       		 res[temp++] = mas5[i][j];
        		temp1 = temp;
        	}
        }
	for (int i = 0; i <= ch / 100 % 10; i++){
    		temp = temp1;
    		for (int j = 0; j < 15; j++){
      			res[temp++] = mas4[i][j];
     	 		temp2 = temp;
    		}
  	}
  	if (ch % 100 >= 10 && ch % 100 < 20){
    		for (int i = 0; i <= ch % 10; i++){
      			temp = temp2;
      			for (int j = 0; j < 10; j++){
        			res[temp++] = mas2[i][j];
      			}
    		}
  	} else if (ch % 100 >= 20){
    		for (int i = 0; i <= ch / 10 % 10; i++){
      			temp = temp2;
      			for (int j = 0; j < 10; j++){
        			res[temp++] = mas3[i][j];
       			temp3 = temp;
      			}
    		for (int i = 0; i <= ch % 10; i++){
      			temp = temp3;
      				for (int j = 0; j < 10; j++){
        				res[temp++] = mas1[i][j];
      				}
    		}
  	} else {
    		for (int i = 0; i <= ch % 10; i++){
      			temp = temp2;
      			for (int j = 0; j < 10; j++){
        			res[temp++] = mas1[i][j];
      			}
    		}
  	}
  	if (ch == 0){
    		res[0] = 'z';
    		res[1] = 'e';
    		res[2] = 'r';
    		res[3] = 'o';
  	}
  	for (int i = 0; i < 100; i++){
    		printf("%c", res[i]);
  	}
![/home/danil/lab07/2(6)/doc](lab07(3(6)).png)

2.5 Компіляція проекту, та перевірка правильності роботи програми за допомогою Nemiver

![/home/danil/lab07/2(6)/doc](nemiver07(3(6)).png)

Висновки:
Я створив програму, яка перетворює число в рядок за допомогою двомірних масивів та операторів циклу.
