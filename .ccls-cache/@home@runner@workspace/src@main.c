/* main.c */
#include "marks.h"
#include "abonent.h"
#include <stdio.h>

int main ()
{
	struct ABON1* abons = get_abons(3);
	print_abons(abons, 3);

	sort_abons(abons, 3);
	printf("\nSorted by name: \n");
	print_abons(abons, 3);

	give_bonus(abons, 3);
	printf("\nAfter bonuses: \n");
	print_abons(abons, 3);

	print_tarif_statistics(abons, 3);
	
	return 0;
}
