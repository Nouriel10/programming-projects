/**
 * greedy.c
 *
 * Nouriel M. Eshaghian
 * nouriele10@gmail.com
 *
 * Calculates the minimum number of coins needed 
 * to give a customer exact change requested.
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // prompt user for amount of change to be returned
    printf("Hey, tell me how much change you need: ");
    float change = GetFloat();
    
    // demand input from user until valid one is given 
    while (change < 0)
    {
        printf("Sorry, that's invalid. Try again: ");
        change = GetFloat();
    }
    
    int coins = 0;
    
    /** 
     * convert input of change to an integer value- cents- to avoid 
     * using imprecise floats when calculating amount of coins 
     * to use, which would return the wrong number
     */
    int cents = round(change * 100);
    
    /** 
     * set up 4 for loops, one for each coin denomination,
     * from highest to lowest, to calculate how many 
     * of each coin can be used to equal total amount of
     * change given and add that to coin total
     */
    for (float quarter = 25; quarter <= cents; cents = cents - quarter)
    {
        coins++;
    }
    
    for (float dime = 10; dime <= cents; cents = cents - dime)
    {
        coins++;
    }
    
    for (float nickel = 5; nickel <= cents; cents = cents - nickel)
    {
        coins++;
    }
    
    for (float penny = 1; penny <= cents; cents = cents - penny)
    {
        coins++;
    }
    
    // print final coin amount
    printf("%i\n", coins);
}

// Yay, I figured it out!! :-) 
// Thankfully this didn't as long as Mario, phew... O_O
