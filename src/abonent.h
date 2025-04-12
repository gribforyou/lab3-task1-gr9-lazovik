/*abonent.h*/
#ifndef ABONENT_H
#define ABONENT_H

struct Date {
  int day;
  int month;
  int year;
};

struct ABON1 {
  char name[50];
  char phone_number[15];
  struct Date connection_date;
  char tarif_plan[20];
  float accrued_payment;
  float account_balance;
};

/*method for getting abons from console*/
struct ABON1 *get_abons(int abons_count);

/*print all abons*/
void print_abons(struct ABON1 *abons, int abons_count);

/*method for sort abons by name*/
void sort_abons(struct ABON1 *abons, int abons_count);

/*method for add 10 to balance for old clients*/
void give_bonus(struct ABON1 *abons, int abons_count);

/*print clients with potential negative balance*/
void print_negative_abons(struct ABON1 *abons, int abons_count);

/*print statistics of users by tarifs*/
void print_tarif_statistics(struct ABON1 *abons, int abons_count);
#endif