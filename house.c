/* Ryan Cummings
 * CSCI 112, Lab2
 * 9/21/2018
 *
 * This program calculates and compares the total cost of purchasing a house
 * over a 5 year period.
 */

#include <stdio.h>

/* gets initial cost from the user */
double getInitialCost(void){

    double initialCost;

    printf("Please enter the price of the house: ");
    scanf("%lf", &initialCost);

    return initialCost;
}

/* gets cost of fuel from the user */
double getFuelCost(void){

    double fuelCost;

    printf("Please enter the fuel cost for one year: ");
    scanf("%lf", &fuelCost);

    return fuelCost;
}

/* gets tax rate from user */
double getTaxRate(void){

    double taxRate;

    printf("Please enter the tax rate in decimal: ");
    scanf("%lf", &taxRate);

    return taxRate;
}

/* calculates 5-year cost */
double calculate(double cost, double fuel, double tax){

    double oneYearTax;
    double totalFiveYearCost;

    // obtain cost of taxes for one year
    oneYearTax = cost * tax;

    // calculate total five-year cost
    totalFiveYearCost = ((cost + (5 * fuel)) + (5 * oneYearTax));
    printf("Total Cost: %1.2lf\n", totalFiveYearCost);

    return totalFiveYearCost;
}

int main (void) {

    double cost = getInitialCost();
    double fuel = getFuelCost();
    double tax = getTaxRate();

    calculate(cost, fuel, tax);

    return 0;  // exit with no errors
}
