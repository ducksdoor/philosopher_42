
#include "philosophers.h"
//hay que trabajar en este showme

void	showme(t_list *list)
{
	int		x;
	t_list	*aux;

	aux = list;
	x = 1;
	printf ("\n\nEste es estado de la lista filo.\n");
	while (list != NULL)
	{
		if (list->next != NULL)
		{
			printf("Tu filo se llama: %d\n", list->philo->name);
			printf("comera %d veces aun\n", list->philo->n_times_each_philosopher_must_eat);
			printf("usara el fork %d\n\n", list->philo->fork);
/*			printf("Tu hilo se llama %d\n", list->philo->name);
			printf("Tu hilo se llama %d\n", list->philo->name); */

/* 				printf("Tu ultimo valor binario es 0\n");
			printf ("este es el binario de [%d] =", list->inde);
			printBinary(list->inde);
			printf("MODULO %d, contenido= [%d], indice= [%d] y apunta a [%d]\n\n", x, list->cont, list->inde, list->next->cont);
 */		}
		else
		{
			printf("Tu hilo se llama: %d\n", list->philo->name);
			printf("comera %d veces aun\n", list->philo->n_times_each_philosopher_must_eat);
			printf("usara el fork %d\n\n", list->philo->fork);
/* 			else
				printf("caracola\n");
			printf ("este es el binario de [%d] =", list->inde);
			printBinary(list->inde);
			printf("MODULO %d, contenido= [%d], indice= [%d] y apunta a [NULL]\n\n", x, list->cont, list->inde);
 */		}

		list = list->next;
		x++;
	}
	list = aux;
/* 	printf("\n\n------pruebas extras----\n");
	printf("queremos sacar el nombre del segundo filósofo");
	printf("Tu hilo se llama: %d\n", list->next->philo->name);
	printf ("\n||Aqui se acaba el resultado del depurador.||\n");*/
	printf ("--------------------------------------------\n\n");
}