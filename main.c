// Program to determine the day of the week of a particular day
// As in Ch9Q2 the textbook is wrong thus 08/08/2004 is a Sunday

#include <stdio.h>

// Define Structures
struct date {
int day;
int month;
int year;
};

// Declare Functions
struct date getDate (void);

int f (struct date);
int g (struct date);
int dateNumber (struct date);
int dayOfWeek (struct date);

void printDate (struct date);

int main(void) {
  struct date dateId = getDate ();

  printDate (dateId);
  
  return 0;
}

// Define Functions
struct date getDate (void) {
  struct date output;

  printf ("Enter date mm/dd/yyyy: ");
  scanf ("%d/%d/%d", &output.month, &output.day, &output.year);

  return output;
}

int f (struct date input) {
  if (input.month <= 2)
    return input.year - 1;
  else
    return input.year;
}
int g (struct date input) {
  if (input.month <= 2) {
    return input.month + 13;
  }
  else {
    return input.month + 1;
  }
}

int dateNumber (struct date input) {
  return (1461 * f (input)) / 4 + (153 * g (input)) / 5 + input.day;
}

int dayOfWeek (struct date input) {
  int weekNumber = dateNumber (input);
  printf ("week Number: %d\n", weekNumber);
  weekNumber -= 621049;
//  printf ("-621049: %d\n", weekNumber);
  weekNumber %= 7;
//  printf ("%%7: %d\n", weekNumber);

  return weekNumber;
}

void printDate (struct date input) {
  int weekDay = dayOfWeek (input);

  switch (weekDay) {
    case 0:
      printf ("%.2d/%.2d/%.4d: is a Sunday\n", input.month, input.day, input.year); 
      break;

    case 1:
      printf ("%.2d/%.2d/%.4d: is a Monday\n", input.month, input.day, input.year);
      break;

    case 2:
      printf ("%.2d/%.2d/%.4d: is a Tuesday\n", input.month, input.day, input.year);
      break;

    case 3:
      printf ("%.2d/%.2d/%.4d: is a Wednesday\n", input.month, input.day, input.year);
    break;

    case 4:
      printf ("%.2d/%.2d/%.4d: is a Thursday\n", input.month, input.day, input.year);
      break;

    case 5:
      printf ("%.2d/%.2d/%.4d: is a Friday\n", input.month, input.day, input.year);
      break;

    case 6:
      printf ("%.2d/%.2d/%.4d: is a Saturday\n", input.month, input.day, input.year);
      break;
  }
}