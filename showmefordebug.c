
#include "philosophers.h"
//hay que trabajar en este showme

void	showme(t_list *list, char *a)
{
	int	x;

	x = 0;
	ft_putstr(a);
	printf ("Este es el resultado del depurador.\n");
	while (list != NULL)
	{
		if (list->next != NULL)
		{
			if ((list->inde >> 0) & 1)
				printf("Tu ultimo valor binario es 1\n");
			else
				printf("Tu ultimo valor binario es 0\n");
			printf ("este es el binario de [%d] =", list->inde);
			printBinary(list->inde);
			printf("MODULO %d, contenido= [%d], indice= [%d] y apunta a [%d]\n\n", x, list->cont, list->inde, list->next->cont);
		}
		else
		{
			if ((list->inde >> 0) & 1)
				printf("hola\n");
			else
				printf("caracola\n");
			printf ("este es el binario de [%d] =", list->inde);
			printBinary(list->inde);
			printf("MODULO %d, contenido= [%d], indice= [%d] y apunta a [NULL]\n\n", x, list->cont, list->inde);
		}

		list = list->next;
		x++;
	}
	printf ("Aqui se acaba el resultado del depurador.\n\n");
}