/* Ryan Cummings
 * CSCI 112, Lab2
 * 9/21/2018
 *
 * This program calculates and compares the total cost of purchasing a house
 * over a 5 year period.
 */

#include <stdio.h>

double initialCost;
double fuelCost;
double taxRate;

// gets user input
void input(void){
    
    //get price of house
    printf("Please enter the price of the house: ");
    scanf("%lf", &initialCost);

    // get fuel cost
    printf("Please enter the fuel cost for one year: ");
    scanf("%lf", &fuelCost);

    //get tax rate
    printf("Please enter the tax rate in decimal: ");
    scanf("%lf", &taxRate);

    return;
}

// calculates 5-year cost
double calculate(void){
    double oneYearTax;
    double totalFiveYearCost;

    // obtain cost of taxes
    oneYearTax = initialCost * taxRate;

    // calculate total five-year cost
    totalFiveYearCost = ((initialCost + (5 * fuelCost)) + (5 * oneYearTax));
    printf("Total Cost: %1.2lf\n", totalFiveYearCost);

    return totalFiveYearCost;
}

int main (void) {
    input();
    calculate();

    return 0;  // exit with no errors
}
