/*
 Given a string, reverse the string word by word.
 Example:
 String: "This is a string"
 Output: "string a is This"
 */
public class reverseWords {
	public static void reverse(char str[],int i,int j)
	{
		while(i<j)
		{
			char temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			i++;
			j--;
		}
	}
	public static void main(String[] args) 
	{
		String str = "This is a string";
		char []s = str.toCharArray();
		System.out.println(str);
		int start=0;
		for(int i=0; i<s.length; i++)
		{
			if(s[i] == ' ')
			{
				reverse(s,start,i-1);
				start = i+1;
			}
			else if(i == s.length -1)
			{
				reverse(s,start,i);
			}
		}
		reverse(s,0,s.length-1);
		System.out.println(s);
	}

}
