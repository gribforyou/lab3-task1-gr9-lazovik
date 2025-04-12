/*customer.c*/
#include "customer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Customer* get_customers_from_pinsk(struct Customer* customers, int count){
  int pinsk_count = 0;
  for (int i = 0; i < count; i++)
    if (strcmp(customers[i].home_address.city, "Pinsk") == 0){
      pinsk_count++;
    }

  struct Customer* pinsk_customers = (struct Customer*)malloc(pinsk_count * sizeof(struct Customer));
  int cur = 0;
  for (int i = 0; i < count; i++){
    if (strcmp(customers[i].home_address.city, "Pinsk") == 0){
      pinsk_customers[cur] = customers[i];
      cur++;
    }
  }
}

void print_customers(struct Customer* customers, int count){
  for (int i = 0; i < count; i++)
    printf("%s %s %s %s\n", customers[i].last_name, customers[i].first_name, customers[i].middle_name, customers[i].home_address.city);
}