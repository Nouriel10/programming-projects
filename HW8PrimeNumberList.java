package hw8.primenumberlist;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * This program has a method- isPrime- to determine if a number is prime or
 * not. This program uses that method to determine all of the prime numbers
 * between 1-100, and then stores all of those numbers in a file- Prime Numbers
 * List.txt
 * @author Nouriel Eshaghian
 */
public class HW8PrimeNumberList
{
    public static void main(String[] args) throws IOException
    {
        int i; // 'for loop' iteration variable
        
        /**
         * Initial FileWriter and PrintWriter statements simply create the file
         * at first with a header statement (so that the file is somewhat
         * documented upon creation and doesn't just open as a random list of
         * numbers).
         */
        FileWriter fw = new FileWriter("Prime Numbers List.txt", true);
        PrintWriter pw = new PrintWriter(fw);
        pw.println("Here are all the prime numbers between 1 and 100:");
        pw.println();
        
        /**
         * For loop goes through all the numbers between 1-100, uses isPrime
         * method to determine if number of current iteration is prime, and if
         * so, then that number is appended to the Prime Numbers List file
         * created earlier. ^_^
         */
        for (i = 1; i <= 100; i++)
        {
            if (isPrime(i)) // use isPrime to determine if current number is prime
            {
                pw.println(i); // if so, then add number to list in file
            }
        }
        pw.close(); // close the PrintWriter
    }
    
    /**
     * isPrime checks to see if a number is prime or not.
     * 
     * @param number The number passed into the method to be determined if it's
     * prime.
     * 
     * @return True or false, depending on whether or not the number passed in
     * is prime.
     */
    
    private static boolean isPrime(int number)
    {
        // boolean variable is initialized here so that NetBeans doesn't SCREAM
        // at me, telling me that the variable might not be initialized- that is,
        // if I wait to initialize it only in the 'for loop'.
        boolean status = false;
        
        /**
         * 'For loop' goes through all the numbers from 2 until the number argument
         * passed into the method, checking to see what is the remainder of
         * division between each current iteration number, and the number argument.
         * If the modulus ever comes out to 0 when dividing the number argument
         * by ANY number from 2 until the number argument, then number argument
         * is automatically NOT prime, and in such a case, 'for loop' is set to
         * break, and leave the result of the boolean variable status as false,
         * and then it's returned. OTHERWISE, boolean variable is set to true,
         * and then returned.
         */
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                status = false;
                break;
            }
            
            else
            {
                status = true;
            }
        }
        return status;
    }
}