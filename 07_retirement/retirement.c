#include <stdio.h>
#include <stdlib.h>

//Declare the retire_info structure
struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

//Function to calculate the balance for either working or retired
double calculator(double result, retire_info stage) {
  result = result + result * stage.rate_of_return + stage.contribution;
  return result;
}

//Main function
void retirement(int startAge, double initial, retire_info working, retire_info retired) {

  double balance = initial;
  int age = startAge;

  for (int i = 0; i < working.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", age/12, age%12, balance);
    balance = calculator(balance, working);
    age++;
  }

  for (int j = 0; j < retired.months; j++) {
    printf("Age %3d month %2d you have $%.2lf\n", age/12, age%12, balance);
    balance = calculator(balance, retired);
    age++;
  }
}

int main (void) {
  retire_info working;
  retire_info retired;
  int startAge = 327;
  int initial = 21345;  
  
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(startAge, initial, working, retired);

  return EXIT_SUCCESS;

}

  
