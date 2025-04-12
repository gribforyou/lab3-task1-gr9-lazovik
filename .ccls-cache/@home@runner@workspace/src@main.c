/* main.c */
#include "marks.h"
#include "abonent.h"
#include "customer.h"
#include <stdio.h>

int main ()
{
	//marks task
	compare_marks();
	printf("\n");
	
	//abons task
	struct ABON1* abons = get_abons(3);
	print_abons(abons, 3);

	sort_abons(abons, 3);
	printf("\nSorted by name: \n");
	print_abons(abons, 3);

	give_bonus(abons, 3);
	printf("\nAfter bonuses: \n");
	print_abons(abons, 3);

	print_tarif_statistics(abons, 3);
	printf("\n");
	
	//customer task
	struct Customer test_customers[] = {
			{"Ivanov", "Ivan", "Ivanovich", 'M', "Belarusian", 180.5, 75.3,
			 {1990, 5, 15}, "+375291234567",
			 {"225710", "Belarus", "Brest Region", "Pinsk District", "Pinsk", 
				"Sovetskaya", "10", "25"}, "1234567812345678", "BY00ALFA301234567890"},

			{"Petrova", "Anna", "Sergeevna", 'F', "Belarusian", 165.2, 55.1,
			 {1995, 8, 20}, "+375297654321",
			 {"220000", "Belarus", "Minsk Region", "Minsk District", "Minsk", 
				"Nezavisimosti", "15", "10"}, "8765432187654321", "BY00ALFA309876543210"},

			{"Sidorov", "Alex", "Petrovich", 'M', "Russian", 175.0, 70.0,
			 {1985, 3, 10}, "+375299876543",
			 {"225710", "Belarus", "Brest Region", "Pinsk District", "Pinsk", 
				"Lenina", "5", "3"}, "1122334455667788", "BY00ALFA303456789012"}
	};
	struct Customer* from_pinsk = get_customers_from_pinsk(test_customers, 3);
	print_customers(from_pinsk, 2);
	return 0;
}
