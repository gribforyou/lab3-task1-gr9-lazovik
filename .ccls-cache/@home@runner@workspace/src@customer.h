/*customer.h*/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "abonent.h"

struct Address{
  char postal_code[10];    
  char country[50];        
  char region[50];         
  char district[50];       
  char city[50];           
  char street[50];         
  char house[10];          
  char apartment[10];      
};

struct Customer{
  char last_name[50];            
  char first_name[50];           
  char middle_name[50];          
  char gender;   // ('M'/'F')
  char nationality[50];          
  float height;                  
  float weight;                  
  struct Date birth_date;        
  char phone[20];                
  struct Address home_address;   
  char credit_card[20];          
  char bank_account[30];         
};

struct Customer* get_customers_from_pinsk(struct Customer* customers, int count);

void print_customers(struct Customer* customers, int count);

#endif