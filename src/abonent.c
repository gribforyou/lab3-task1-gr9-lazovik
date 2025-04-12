/*abonent.c*/
#include "abonent.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*getting abon from console*/
struct ABON1 get_abon() {
    struct ABON1 abonent;

    printf("Введите фамилию и инициалы: ");
    fgets(abonent.name, sizeof(abonent.name), stdin);
    abonent.name[strcspn(abonent.name, "\n")] = 0;

    printf("Введите номер телефона: ");
    fgets(abonent.phone_number, sizeof(abonent.phone_number), stdin);
    abonent.phone_number[strcspn(abonent.phone_number, "\n")] = 0; 

    printf("Введите дату подключения (ГГГГ ММ ДД): ");
    scanf("%d %d %d", &abonent.connection_date.year, 
                   &abonent.connection_date.month, 
                   &abonent.connection_date.day);
    while (getchar() != '\n');
  
    printf("Введите тарифный план: ");
    scanf(" %[^\n]", abonent.tarif_plan);
    while (getchar() != '\n');

    printf("Введите начисленную сумму оплаты: ");
    scanf("%f", &abonent.accrued_payment);
    while (getchar() != '\n');

    printf("Введите сумму на счёту: ");
    scanf("%f", &abonent.account_balance);
    while (getchar() != '\n');

    return abonent;
}

struct ABON1 *get_abons(int abons_count) {
  struct ABON1 *abons = (struct ABON1*)malloc(sizeof(struct ABON1) * abons_count);
  for (int i = 0; i < abons_count; i++){
    abons[i] = get_abon();
    printf("\n");
  }
  return abons;
}

/*comparing abons by name*/
int compare_abonents(const void *a, const void *b) {
    const struct ABON1 *abonentA = (const struct ABON1 *)a;
    const struct ABON1 *abonentB = (const struct ABON1 *)b;

    return strcmp(abonentA->name, abonentB->name);
}


void sort_abons(struct ABON1 *abons, int abons_count){
  qsort(abons, abons_count, sizeof(struct ABON1), compare_abonents);
}

/*print abon*/
void print_abon(struct ABON1 abonent){
  printf("Фамилия и инициалы: %s\n", abonent.name);
  printf("Номер телефона: %s\n", abonent.phone_number);
  printf("Дата подключения: %d.%d.%d\n", abonent.connection_date.day, abonent.connection_date.month, abonent.connection_date.year);
  printf("Тарифный план: %s\n", abonent.tarif_plan);
  printf("Начисленная сумма оплаты: %.2f\n", abonent.accrued_payment);
  printf("Сумма на счёту: %.2f\n", abonent.account_balance);
}

void print_abons(struct ABON1 *abons, int abons_count){
  for (int i = 0; i < abons_count; i++){
    print_abon(abons[i]);
    printf("\n");
  }
}

/*method returns true if abon registrated more than 10 years ago*/
bool is_old_client(struct ABON1 abonent) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    int current_year = tm_info->tm_year + 1900;
    int current_month = tm_info->tm_mon + 1;
    int current_day = tm_info->tm_mday;
    int abonent_year = abonent.connection_date.year;

    if (current_year - abonent_year > 10) {
        return true;
    } else if (current_year - abonent_year == 10) {
        if (current_month > abonent.connection_date.month) {
            return true;
        } else if (current_month == abonent.connection_date.month) {
            return current_day >= abonent.connection_date.day;
        }
    }
    return false;
}

/*add bonus to abons who registrated more than 10 years ago*/
void give_bonus(struct ABON1 *abons, int abons_count){
  for (int i = 0; i < abons_count; i++){
    if (is_old_client(abons[i]))
      abons[i].account_balance += 10;
  }
}

/*print abons with negative balance after paying*/
void print_negative_abons(struct ABON1 *abons, int abons_count){
  for (int i = 0; i < abons_count; i++)
    if(abons[i].account_balance < abons[i].accrued_payment){
      print_abon(abons[i]);
      printf("\n");
    }
}

int compare_tarifs(const void *a, const void *b) {
  const struct ABON1 *abon1 = (const struct ABON1 *)a;
  const struct ABON1 *abon2 = (const struct ABON1 *)b;
  return strcmp(abon1->tarif_plan, abon2->tarif_plan);
}

/*calculating and printing statistics of users by tarifs*/
void print_tarif_statistics(struct ABON1 *abons, int abons_count) {
  if (abons == NULL || abons_count <= 0) {
      printf("Invalid input parameters.\n");
      return;
  }

  struct ABON1 *copy = (struct ABON1 *)malloc(abons_count * sizeof(struct ABON1));
  memcpy(copy, abons, abons_count * sizeof(struct ABON1));

  qsort(copy, abons_count, sizeof(struct ABON1), compare_tarifs);

  printf("Tarif plan usage statistics:\n");
  int count = 1;
  for (int i = 1; i <= abons_count; i++) {
      if (i < abons_count && strcmp(copy[i].tarif_plan, copy[i-1].tarif_plan) == 0) {
          count++;
      } else {
          printf("- %s: %d\n", copy[i-1].tarif_plan, count);
          count = 1;
      }
  }

  free(copy);
}