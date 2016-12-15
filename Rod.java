/*
Connect n ropes with minimum cost
There are given n ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected.

Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first 
(we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). Finally we connect 13 and 2. 
Total cost in this way is 10 + 13 + 15 = 38.
*/

import java.util.Iterator;
import java.util.TreeSet;


public class Rod {

	public static void main(String[] args) {
		TreeSet<Integer> t = new TreeSet<Integer>();
		t.add(4);
		t.add(3);
		t.add(2);
		t.add(6);
		Iterator<Integer> i = t.iterator();
		System.out.println("Given length of rods are:");
		while(i.hasNext())
		{
			System.out.print(i.next()+ " ");
		}
		System.out.println();
		int sum = 0;
		while(t.size() > 1)
		{
			Integer val1 = t.first();
			t.remove(val1);
			Integer val2 = t.first();
			t.remove(val2);
			Integer total = val1 + val2;
			sum += total;
			t.add(total);
		}
		System.out.println("cost:"+sum);
	}

}
