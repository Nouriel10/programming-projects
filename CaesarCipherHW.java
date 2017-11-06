package caesarcipherhw;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner;

public class CaesarCipherHW
{
    public static String encrypt(String plainText, int key)
    {
        final int ASCII_UPPER = 65;
        
        if (key < 0)
        {
            throw new IllegalArgumentException("Your key must be >= 0!");
        }

        plainText = plainText.toUpperCase();

        String cipherText = "";

        for (int index = 0; index < plainText.length(); index++)
        {
            char c = plainText.charAt(index);
            if (Character.isAlphabetic(c))
            {
                char cipherChar = (char) ((c - ASCII_UPPER + key) % 26 +
                        ASCII_UPPER);
                cipherText += cipherChar;
            }
            else
            {
                cipherText += c;
            }
        }
        
        return cipherText;
    }
    
    public static String decrypt(String cipherText, int key)
    {
        return encrypt(cipherText, -key);
    }
    
    public static void main(String[] commandLineArgs) throws FileNotFoundException
    {
        String inputFileName = commandLineArgs[0];
        
        String outputFileName = commandLineArgs[1];
        
        Random generator = new Random();
        
        File file = new File(inputFileName);
        
        Scanner fileReader = new Scanner(file);
        
        PrintWriter pw = new PrintWriter(outputFileName);
        
        while (fileReader.hasNext())
        {
            pw.println(encrypt(fileReader.nextLine(), generator.nextInt(26)));
        }
        
        fileReader.close();
        pw.close();
    }
}
