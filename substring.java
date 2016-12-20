/*
 * check string 2 is substring of string 1.
 * 
 */
public class Substring {

	public static Boolean match(String s1, String s2)
	{
		int m = s2.length();
		int n = s1.length();
		for(int i=0; i<=(n-m);i++)
		{
			int j=0;
			while(j<m && s1.charAt(i+j)==s2.charAt(j))
			{
				j++;
			}
			if(j==m) return true;
		}
		
		return false;
	}
	public static void main(String[] args) 
	{
		String s1 = "abate";
		String s2 = "bat";
		if(match(s1,s2))
		{
			System.out.println("found");
		}
		else
		{
			System.out.println("not found");
		}
	}

}
