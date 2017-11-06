/**
 * caesar.c
 *
 * Nouriel M. Eshaghian
 * nouiele10@gmail.com
 *
 * Encrypts a string of text taken from the user 
 * (when program is run) using the caesar cipher
 * using a number key entered by the user as
 * the second command line argument.
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET 26
#define UPRCSE 65
#define LWRCSE 97
/** 
 * Declare function- error message- to be called 
 * if/ when user runs program incorrectly (defined later).
 */
void ErrMsg(void);

int main(int argc, string argv[])
{
    // Declare HERE the variables within which to store the plain text
    // & number key inputted by the user so that their scope should
    // not be limited to any range, allowing them to be accessed 
    // throughout the rest of the program.
    string text;
    int key;
    // As the program should only execute if two command line arguments are
    // given, with the second argument needing to be a positive integer,
    // "if" statement checks to see if these conditions have been met.
    // If so, program proceeds to prompt user for string of text to encode,
    // storing it in variable "text". If not, error message is 
    // generated and program is exited.
    if (argc == 2 && (key = atoi(argv[1])) >= 0)
    {
        text = GetString();
    }
    else
    {
        ErrMsg();
        return 1;
    }
    // "For" loop proceeds to iterate through each char of the plain text, 
    // checking to see if it's alphabetical, adding the number key to it's
    // numerical value, then returning the letter which is that many places
    // down from it in the alphabet. If any char in the text is not 
    // alphabetical, the char is returned unchanged.
    for (int chr = 0, len = strlen(text); chr < len; chr++)
    {
        if (isalpha(text[chr]))
        {
            // Simply adding the key to each char in the text won't work. Every
            // char on the keyboard has a corresponding numerical value, as per
            // the ASCII chart. As such, by simply adding the key to each char,
            // non-alphabetical chars/ wrongly-cased letters will end up being
            // returned, depending on which char is that many places down from
            // that letter in the ASCII chart when adding the key to it. E.g.,
            // for a key of 1 and a plain text of 'Z', the char '[' will be
            // returned, as '[' is one char down the ASCII chart from 'Z'.
            // Therefore, each alphabetical char in the text must be reduced
            // to a standard value, between 0 - 25 based on it's number order  
            // in the alphabet, add the key to it's value, then go back
            // & return the letter in the corresponding slot in the ASCII chart
            // (by re-adding the difference between the alphabet value and the
            // ASCII value). However, to accomodate for a key which, when added
            // to each reduced char value of the plain text, equals a non-
            // alphabetical value, i.e., > 25, the modulus of the key [added
            // to the reduced char value] to the number 26 has to be used so
            // that the result always remains within the 0 - 25 range (an
            // alphabetical letter). As the lowercase and uppercase letters
            // are not grouped next to each other in the ASCII chart, they have
            // be reduced to a standard value (0 - 25) separately. Hence, the 
            // "if (islower)" and else clauses.
            if (islower(text[chr]))
            {
                printf("%c", (text[chr] - LWRCSE + key) % ALPHABET + LWRCSE );
            }
            else
            {
                printf("%c", (text[chr] - UPRCSE + key) % ALPHABET + UPRCSE);
            }
        }
        // return any non-alphabetical char in the plain text as is
        else
        {
            printf("%c", text[chr]);
        }    
    }
    // once the plain text has been enciphered, end of program; print new line  
    printf("\n"); 
}
/**
 * Definition of previously declared ErrMsg function;
 * function prints error message to user and returns 1,
 * terminating the program. Called if/ whenever user does not
 * give EXACTLY 2 command line arguments, OR if the second
 * argument is a negative integer.
 */
void ErrMsg(void)
{
    printf("Sorry, that's invalid. Restart program. Goodbye :-).\n");
}
