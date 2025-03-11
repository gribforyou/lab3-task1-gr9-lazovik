/*marks.c*/
#include "marks.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLASS_SIZE 20
#define COMPARABLE_NUM 5

/*generate random marks*/
float *generate_marks() {
  float *marks = (float *)malloc(sizeof(float) * CLASS_SIZE);
  for (int i = 0; i < CLASS_SIZE; i++)
    marks[i] = ((float)(rand() % 1000)) / 100;
  return marks;
}

/*out marks*/
void print_classes_marks(float *first, float *second) {
  printf("Num\tFirst\tSecond\n");
  for (int i = 0; i < CLASS_SIZE; i++)
    printf("%d-th\t%.2f\t%.2f\n", i + 1, first[i], second[i]);
}

/*help method for get_fifth_mark*/
void insert(float *marks, float mark) {
  if (mark <= marks[0]) {
    return;
  }

  marks[0] = mark;
  for (int i = 1; i < COMPARABLE_NUM; i++) {
    if (mark > marks[i]) {
      float temp = marks[i];
      marks[i] = marks[i - 1];
      marks[i - 1] = temp;
    } else
      break;
  }
}

/*compare method for sorting arrays*/
int compare(const void *a, const void *b) {
  float floatA = *(float *)a;
  float floatB = *(float *)b;
  return (floatA > floatB) - (floatA < floatB);
}

/*find fifth best mark*/
float get_comparable_mark(float *marks) {
  float *five_best = (float *)malloc(sizeof(float) * 5);
  for (int i = 0; i < COMPARABLE_NUM; i++)
    five_best[i] = marks[i];

  qsort(five_best, COMPARABLE_NUM, sizeof(float), compare);
  for (int i = COMPARABLE_NUM; i < CLASS_SIZE; i++) {
    insert(five_best, marks[i]);
  }
  return five_best[0];
}

void compare_marks() {
  srand(time(NULL));
  float *first_class_marks = generate_marks();
  float *second_class_marks = generate_marks();

  print_classes_marks(first_class_marks, second_class_marks);
  printf("\n");

  float first = get_comparable_mark(first_class_marks);
  float second = get_comparable_mark(second_class_marks);

  printf("First class %d-th best mark: %.2f\n", COMPARABLE_NUM, first);
  printf("Second class %d-th best mark: %.2f\n", COMPARABLE_NUM, second);
  printf("\n");

  if (first > second) {
    printf("First class has better %d-th best mark\n", COMPARABLE_NUM);
  } else if (first < second) {
    printf("Second class has better %d-th best mark\n", COMPARABLE_NUM);
  } else {
    printf("Both classes have the same %d-th best mark\n", COMPARABLE_NUM);
  }
}
