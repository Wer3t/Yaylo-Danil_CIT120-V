/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Yaylo D.
 * @date 15-feb-2021
 * @version 1.0
 */

#include "list.h"
#include "data.h"

void read_list(D_LinkedList *list, regex_t regex, int reti, int n)
{
	FILE *file;
	file = fopen("input.txt", "r");
	for (int i = 0; i < n; i++)
	{
		bird *tmp = (bird *)malloc(sizeof(bird));
		if (tmp == NULL)
		{
			exit(1);
		}
		fscanf(file, "%d", &tmp->ringed);
		fscanf(file, "%d", &tmp->age);
		fscanf(file, "%d", &tmp->house.square);
		fscanf(file, "%d", &tmp->house.height);
		fscanf(file, "%d", &tmp->house.num_feeders);
		fscanf(file, "%d", &tmp->house.nest);
		fscanf(file, "%d", &tmp->sex);
		fseek(file, sizeof(char), 1);

		char species[128] = {0};
		fgets(species, 128, file);
		reti = regexec(&regex, species, 0, NULL, 0);
		if (!reti)
		{
			sprintf(tmp->species, species);
		}
		else if (reti == REG_NOMATCH)
		{
			printf("\nВведенная строка не подходит\n");
		}

		tmp->next = list->head;
		tmp->prev = NULL;
		if (list->head)
		{
			list->head->prev = tmp;
		}
		list->head = tmp;
		if (list->tail == NULL)
		{
			list->tail = tmp;
		}
		list->size++;
	}

	fclose(file);
}

void write_out(D_LinkedList *list, regex_t regex, int reti)
{
	printf("\n");
	bird *tmp = list->tail;
	while (tmp)
	{
		reti = regexec(&regex, tmp->species, 0, NULL, 0);
		if (!reti)
		{
			if (tmp->ringed == 2)
			{
				printf("ringed, ");
			}
			else if (tmp->ringed == 1)
			{
				printf("non ringed, ");
			}
			printf("%d, ", tmp->age);
			printf("%d, ", tmp->house.square);
			printf("%d, ", tmp->house.height);
			printf("%d, ", tmp->house.num_feeders);
			if (tmp->house.nest == 2)
			{
				printf("have nest, ");
			}
			else if (tmp->house.nest == 1)
			{
				printf("haven't nest, ");
			}
			if (tmp->sex == 2)
			{
				printf("male, ");
			}
			else if (tmp->sex == 1)
			{
				printf("female, ");
			}
			printf("%s", tmp->species);
		}
		tmp = tmp->prev;
	}
}

int count_lines()
{
	/*Подсчёт количества строк в файле, что бы понимать сколько структур будет*/
	int lines_count = 0;
	FILE *file;
	file = fopen("input.txt", "r");
	while (!feof(file))
	{
		if (fgetc(file) == '\n')
		{
			lines_count++;
		}
	}
	fclose(file);
	return lines_count;
}