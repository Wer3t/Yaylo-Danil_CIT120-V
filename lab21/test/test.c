/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Yaylo D.
 * @date 15-feb-2021
 * @version 1.0
 */
 
#include "/home/danil/dev/Yaylo-Danil_CIT120-V/lab21/src/lib.h"

unsigned short test_percent_male_to_female(){
	int n = 3;
	struct bird test[n];
	test[0].sex = 1;
	test[1].sex = 0;
	test[2].sex = 1;
	double expected_male=2;
	double male=percent_male_to_female(test, n);
	if(expected_male!=male){
		printf("\nTest: percent_male_to_female failed");
	} else {
		printf("\nTest: percent_male_to_female successful");
	}
}

int main(){
	test_percent_male_to_female();
	return 0;
}


