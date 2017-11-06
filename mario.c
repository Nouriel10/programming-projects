/**
 * mario.c
 *
 * Nouriel M. Eshaghian
 * nouriele10@gmail.com
 * 
 * Recreates half pyramid from level 1-1 of Super Mario Bros. 
 * using hashes based on user's input of pyramid height 
 * from 1 through 23.
 */
#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    // prompt user for input for pyramid height
    printf("Hi! Please give me a number from 1 through 23: ");
    int height = GetInt();
     
    /** 
     * a few "ifs" to prompt user with alternate retry displays- 
     * if user is uncooperative several times over-for fun ;) 
     */
    for (int try = 1; try <= 3; try++)
    {
        if ( height < 0 || height > 23)
        { 
            printf("Try again :-): ");
            height = GetInt();
        }
    }
    if ( height < 0 || height > 23)
    { 
        printf("Ummm... Are you ok? I need a number from 1 through 23: ");
        height = GetInt();
    }
    if ( height < 0 || height > 23)
    { 
        printf("Hello?! What's with you? I need a number from 1 through 23!: ");
        height = GetInt();
    }
    /** 
     * after a while, while loop (no pun intended) prompts
     * for valid input through angry face display- 
     * again, for fun
     */
    while ( height < 0 || height > 23)
    {
        printf(">:-(: ");
        height = GetInt();
    }     
           
    /** 
     * set relation of rows to inputed height 
     * to make correct amount of rows
     */
    for (int row = 1; row <= height; row++)
    {   
        /** 
         * set relation of spaces to height/ rows 
         * to print correct amount of spaces in each row
         */  
        for (int space = 1; space <= height - row; space++)
        {
            printf(" ");
        }           
        /** 
         * set relation of hashes to height/ rows 
         * to print correct amount of hashes on each row
         */
        for (int hash = 1; hash <= row + 1; hash++)
        {
            printf("#");
        }
        /** 
         * make new row after printing correct amount 
         * of each character on each row
         */
        printf("\n");
    }
}

// yay, I FINALLY understood how to make this work!!!
// I think I've logged AT LEAST 20 HOURS on this part of the pset,
// trying to make it work O_O... I found some good help on reddit.
