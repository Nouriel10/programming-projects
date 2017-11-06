/**
 * vigenere.c
 *
 * Nouriel M. Eshaghian
 * nouiele10@gmail.com
 *
 * Takes a keyword from a user as a second command line
 * argument and uses it to encipher a string of plain
 * text taken from the user (when program is run) using
 * the vigenere cipher.
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
 * Declare function to be called if/ when user runs program
 * incorrectly (defined later).
 */
void ErrMsg(void);

int main(int argc, string argv[])
{
    // As the program should only run if two command line
    // arguments are given, "if" statement checks to see if
    // argc == 2. If so, rest of program is executed. If not,
    // error message is returned to user through function 
    // ErrMsg.  
    if (argc == 2)
    {
        // As a vigenere cipher, each alphabteical char of the plain text
        // is enciphered using the next letter of the keyword. The following
        // for loop first iterates through the chars in argv[1] checking
        // to see if they are all alphabetical (and if not, to terminate the
        // program). As well, each of the letters in both the plain text and
        // the keyword have to be reduced down from their ASCII numerical
        // values to their standard alphabetical values (from 0 - 25) in order
        // to be encoded properly. Otherwise, when adding each keyword char 
        // to each plain text letter, the computer will use their ASCII
        // values in the equation and end up returning the char equivalent
        // in the ASCII chart of the sum of those two letters. As such, the
        // letters in argv[1] are first all converted to uppercase letters
        // (so that their numerical values are all consecutive ints) and
        // stored in a char array (Keyword) and then converted to their
        // standard alphabetical values and stored as an array of ints (KW). 
        // At first, the variables and arrays that store these values,
        // including argv[1], were declared OUTSIDE of this "if"
        // statement so as to avoid limting them to its scope. However,
        // when program is run as such, terminal window returns
        // "Segmentation fault (core dumped)" whenever a second command
        // line argument is not given, as the program would be telling
        // the computer to store argv[1] in a variable, but as it wouldn't
        // exist in that case, that error message is given. As such, by
        // declaring these variables INSIDE of the "if" clause, the program
        // has already checked to see if argv[1] exists, and if so, stores
        // it in the declared variable (else, program returns 1 and
        // terminates). Being so, the rest of the entire body of the 
        // program was included in this "if" clause as well, so that
        // these variables would be accessible by the rest of the program
        // (and not be limited by this "if" clause's scope), with its "else"
        // coming all the way at the end.
        string keyword = argv[1];
        int len = strlen(keyword);
        char KYWRD[len];
        int KWVLS[len];
        for (int kwc = 0; kwc < len; kwc++)
        {
            if (!isalpha(keyword[kwc]))
            {
                ErrMsg();
                return 1;
            }
            KYWRD[kwc] = toupper(keyword[kwc]);
            KWVLS[kwc] = KYWRD[kwc] - UPRCSE;
        }
        // If all keyword chars entered are alphabetical, program 
        // proceeds to prompt user for string of text to encode.
        string text = GetString();
               
        // For loop iterates through each letter of the plain text,
        // encoding each one with the next char of the keyword.
        for (int chr = 0, kwc = 0, n = strlen(text); chr < n; chr++)
        {
            // if the current plain text char is alphabetical, encode it
            if (isalpha(text[chr]))
            {
                // As the lower and uppercase letters in the alphabet are not
                // grouped together in the ASCII chart, each one has to be
                // reduced to its alphabetical value separately, using "if
                // (islower)" and else clauses.
                if (islower(text[chr]))
                {
                    // The modulus operator is used to wrap each letter back around the alphabet,
                    // as well as to wrap the int array back to its beginning (for when the plain
                    // text is longer than the keyword) so that, if/ when adding a keyword char to
                    // the plain text char, the result is higher than 25, the modulus operator returns
                    // the value back to a value within a range of 0 - 25, so that the result remains
                    // a value that corresponds to an alphabetical letter. Afterwards, the value is
                    // converted back to the ASCII chart value that corresponds to the alphabetical
                    // value so that the program prints the actual cipher letter.
                    printf("%c", (text[chr] - LWRCSE + KWVLS[kwc % len]) % ALPHABET + LWRCSE);
                }
                else
                {
                    printf("%c", (text[chr] - UPRCSE + KWVLS[kwc % len]) % ALPHABET + UPRCSE);
                }
                // As the plain text may include non-alphabetical chars, the
                // program shouldn't use the next keyword char until the loop
                // gets to the next letter in the plain text. As such, the
                // plain text and keyword have to be iterated through with
                // separate indexes, where the index being used for the keyword
                // is incremented ONLY if the current plain text char is a letter.
                // To do so, the keyword index is declared in the loop header, but
                // instead of incrementing it there as well, the incrementation is
                // done HERE, within the "if" statement checking to see if the
                // current plain text char is alphabetical. That way, it'll only be
                // incremented if that is true.
                kwc++;
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
    // the "else" of the initial "if" in the program, terminating it if argc != 2
    else
    {
        ErrMsg();
        return 1;
    } 
}
/**
 * Definition of previously declared ErrMsg function;
 * function prints error message to user and returns 1,
 * terminating the program. Called if/ whenever user does not
 * give EXACTLY 2 command line arguments, OR if second
 * argument contains any non-alphabetical chars. Takes no
 * arguments.
 */
void ErrMsg(void)
{
    printf("Sorry, that's invalid. Restart program. Goodbye :-).\n");
}
// yay, I'm done!!!!!!
