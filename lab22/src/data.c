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

void read_list(D_LinkedList *list, regex_t regex, int reti)
{
	int n=1;
	while(n){
		bird *tmp = (bird *)malloc(sizeof(bird));
		if (tmp == NULL)
		{
			exit(1);
		}
		printf("\nВведите окольцована ли птица(1-да, 2-нет)\n");
		scanf("%d", &tmp->ringed);
		printf("\nВведите название вида птицы\n");
		char species[128];
		scanf("%s", &species);
		fgets(species, 128, stdin);
		reti = regexec(&regex, species, 0, NULL, 0);
		if (!reti) {
    		sprintf(species, tmp->species);
		}
		else if (reti == REG_NOMATCH) {
   			printf("\nВведенная строка не подходит\n");
		}
		printf("\nВведите возраст птицы\n");
		scanf("%d", &tmp->age);
		printf("\nВведите площадь дома\n");
		scanf("%d", &tmp->house.square);
		printf("\nВведите высоту дома\n");
		scanf("%d", &tmp->house.height);
		printf("\nВведите колличество кормушек\n");
		scanf("%d", &tmp->house.num_feeders);
		printf("\nВведите есть ли гнездо в доме(1-да, 2-нет)\n");
		scanf("%d", &tmp->house.nest);
		printf("\nВведите пол птицы(1-мужской, 2-женский)\n");
		scanf("%d", &tmp->sex);

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

		printf("\nЖелаете продолжить заполнение? (1-да, 0-нет)\n");
		scanf("%d",&n);
	}
}

void write_out(D_LinkedList *list)
{
	printf("\n");
	bird *tmp = list->tail;
	while (tmp)
	{
		if (tmp->ringed == 2)
		{
			printf("ringed, ");
		}
		else if (tmp->ringed == 1)
		{
			printf("non ringed, ");
		}
		printf("%s, ", tmp->species);
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
			printf("male");
		}
		else if (tmp->sex == 1)
		{
			printf("female");
		}
		printf("\n");
		tmp = tmp->prev;
	}
}
