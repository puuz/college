/**
 * @file StringManip.java
 * 
 * @brief Outputs the different manipulations done
 * on the inputted string.
 * 
 * Outputs the different manipulations done
 * on the inputted string.
 * 
 * @author Sam Farris
 * @date 2/16/2022
 */
package part1;
import java.util.Scanner;

public class StringManip {
    public static void main(String args[]) {
        System.out.println("Please enter a string to be manipulated: ");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println(reverseString(str));
        System.out.println(middleChar(str));
        System.out.println("\nPlease enter a character to be counted in the inputted string: ");
        char ch = sc.next().charAt(0);
        sc.close();
        System.out.println(countChar(str, ch));
        System.out.println(countWords(str));
    }
    /**
     * @brief Reverses the characters from beginning to end for the given string.
     * 
     * Reverses the characters from beginning to end for the given string.
     *
     * @param str The string to reverse each character in it.
     *
     * @return String The new reversed string.
     */
    public static String reverseString(String str) {
        String nStr = "";
        char ch;
        for (int i = 0; i < str.length(); i++) {
            ch = str.charAt(i);
            nStr = ch + nStr;
        }
        return nStr;
    }
    /**
     * @brief Finds the middle character in the string if the counted
     * characters are odd, or the two middle characters if it's even.
     * 
     * Finds the middle character in the string if the counted
     * characters are odd, or the two middle characters if it's even.
     *
     * @param str The string to use for finding the middle character(s).
     *
     * @return String The middle character(s) in the str param.
     */
    public static String middleChar(String str) {
        int strLength = str.length();
        if (strLength % 2 == 0) {
            return str.substring(strLength / 2 - 1, strLength / 2 + 1);
        }
        return str.substring(strLength / 2, strLength / 2 + 1);
    }
    /**
     * @brief Counts the number of times the character is in the
     * the string.
     * 
     * Counts the number of times the character is in the
     * the string.
     *
     * @param str The string to use for where the character should appear.
     * @param ch The character to use for finding how many times it appears in the string.
     *
     * @return String A statement stating what character was searched and how many times
     * it appeared in the string.
     */
    public static String countChar(String str, char ch) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ch) {
                count++;
            }
        }
        return "The letter " + ch + " is repeated " + count + " times in " + str;
    }
    /**
     * @brief Counts the number of words in a string and prints out the
     * information regarding it.
     * 
     * Counts the number of words in a string and prints out the
     * information regarding it. Also changing the number to a word number.
     *
     * @param str The string to count the number of words in it.
     *
     * @return String A statement stating how many words are in the string with a converison
     * to a word number instead of just a number.
     */
    public static String countWords(String str) {
        //simple regex manipulation (i know this from js)
        //all this does is filters out all the spaces that appear one or more times
        //and puts it into an array leaving the length property to use on the created array
        int num = str.split(" +").length;
        String wordNum = "";
        while (num != 0) {
            if (num >= 1 && num < 20) {
                switch (num) {
                    case 1:
                        wordNum += "one";
                        num = 0;
                        break;
                    case 2:
                        wordNum += "two";
                        num = 0;
                        break;
                    case 3:
                        wordNum += "three";
                        num = 0;
                        break;
                    case 4:
                        wordNum += "four";
                        num = 0;
                        break;
                    case 5:
                        wordNum += "five";
                        num = 0;
                        break;
                    case 6:
                        wordNum += "six";
                        num = 0;
                        break;
                    case 7:
                        wordNum += "seven";
                        num = 0;
                        break;
                    case 8:
                        wordNum += "eight";
                        num = 0;
                        break;
                    case 9:
                        wordNum += "nine";
                        num = 0;
                        break;
                    case 10:
                        wordNum += "ten";
                        num = 0;
                        break;
                    case 11:
                        wordNum += "eleven";
                        num = 0;
                        break;
                    case 12:
                        wordNum += "twelve";
                        num = 0;
                        break;
                    case 13:
                        wordNum += "thirteen";
                        num = 0;
                        break;
                    case 14:
                        wordNum += "fourteen";
                        num = 0;
                        break;
                    case 15:
                        wordNum += "fifteen";
                        num = 0;
                        break;
                    case 16:
                        wordNum += "sixteen";
                        num = 0;
                        break;
                    case 17:
                        wordNum += "seventeen";
                        num = 0;
                        break;
                    case 18:
                        wordNum += "eighteen";
                        num = 0;
                        break;
                    case 19:
                        wordNum += "nineteen";
                        num = 0;
                        break;
                }
            } else if (num >= 20 && num < 30) {
                wordNum += "tweenty";
                num -= 20;
            } else if (num >= 30 && num < 40) {
                wordNum += "thirty";
                num -= 30;
            } else if (num >= 40 && num < 50) {
                wordNum += "fourty";
                num -= 40;
            } else if (num >= 50 && num < 60) {
                wordNum += "fifty";
                num -= 50;
            } else if (num >= 60 && num < 70) {
                wordNum += "sixty";
                num -= 60;
            } else if (num >= 70 && num < 80) {
                wordNum += "seventy";
                num -= 70;
            } else if (num >= 80 && num < 90) {
                wordNum += "eighty";
                num -= 80;
            } else if (num >= 90 && num < 100) {
                wordNum += "ninty";
                num -= 90;
            } else {
                wordNum += "onehundred or more";
                num = 0;
            }
        }
        return "The " + str + " consist of " + wordNum + " words.";
    }
}