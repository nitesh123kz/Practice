/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

import java.util.*;


public class Check 
{
	public static int max(int a, int b)
	{
		return a>b?a:b;
	}
	public static int lengthOfLongestSubstring(String s) {
	    HashMap<Character, Integer> map = new HashMap<Character, Integer>();
	    if (s == null || s.length() == 0) return 0;
	    if (s.length() == 1) return 1;
	    int rightPointer = 0, leftPointer = rightPointer - 1, answer = 0;
	    while (rightPointer != s.length()) {
	         Integer previousOccurrence = map.put(s.charAt(rightPointer), rightPointer);
	         if (previousOccurrence != null) {
	             leftPointer = max(leftPointer, previousOccurrence);
	         }
	         answer = max(answer, rightPointer - leftPointer);
	         rightPointer++;
	    }
	    return answer;
	}
	 public static void main(String [] args)
	 {
	        System.out.println(lengthOfLongestSubstring("abcabcabc"));//output:3
	  }
}
