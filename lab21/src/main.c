#include "lib.h"

int main()
{
	printf("\n");
	char input_name[]="input.txt";
	char *filename = input_name;

	int n = count_lines(filename);
	struct bird types[n];

	read_file(types, n, filename);

	char output_name[]="output.txt";
	filename = output_name;
	write_file(types, n,filename);

	write_out(types, n);

	percent_male_to_female(types, n);
	
	return 0;
}
