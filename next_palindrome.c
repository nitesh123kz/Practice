/*
An integer is said to be a palindrome if its value is the same when read from both the right and left side. For a given positive Integer X , write a program that outputs the value of the smallest palindrome greater than X. 
Input
Integer X such that X<10000.
Output
Output the smallest palindrome larger than X.
Note : Numbers are always displayed without leading zeros.
Case 1
Input:
606
Output:
616
Case 2
Input:
2133
Output:
2222

*/

import java.util.Scanner;


public class palin {
    public static int reverse(int a)
    {
    	int res=0;
    	while(a>0)
    	{
    		int digit = a%10;
    		res = res*10 + digit;
    		a = a/10;
    	}
    	return res;
    }
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		String str = Integer.toString(a);
		System.out.println("String: "+str);
        int len = str.length();
        System.out.println("length: "+len);
        
        if(len%2 == 0)
        {
        	String val1 = str.substring(0,len/2);
            String val2 = str.substring(len/2);
            System.out.println("val1: "+val1);
            System.out.println("val1: "+val2);
            int ab = Integer.parseInt(val1);
            int bc = Integer.parseInt(val2);
            System.out.println("val1_int: "+ab);
            System.out.println("val1_int: "+bc);
	        if(reverse(ab) > bc)
	        {
	        	System.out.println(val1+reverse(ab));
	        }
	        else
	        {
	        	ab = ab+1;
	        	System.out.println(Integer.toString(ab)+reverse(ab));
	        }
        }
        else
        {
        	String val1 = str.substring(0,len/2);
            String val2 = str.substring(1+len/2);
            String x = str.substring(len/2, 1+len/2);
            System.out.println("val1: "+val1);
            System.out.println("val1: "+val2);
            System.out.println("X: "+x);
            int ab = Integer.parseInt(val1);
            int bc = Integer.parseInt(val2);
            int mid = Integer.parseInt(x);
            System.out.println("val1_int: "+ab);
            System.out.println("val1_int: "+bc);
            System.out.println("mid: "+mid);
            if(reverse(ab) > bc)
            {
            	System.out.println(val1+x+reverse(ab));
            }
            else if(mid<9)
            {
            	mid = mid+1;
            	System.out.println(val1+mid+reverse(ab));
            }
            else if(mid == 9)
            {
            	ab = ab+1;
	        	System.out.println(Integer.toString(ab)+0+reverse(ab));
            }
        }
	}

}
