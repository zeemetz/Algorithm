import java.util.*;
public class Diamond
{

	static Scanner scan = new Scanner(System.in);
	static int times = 5;
	public static void main(String args[])
	{
		for(int i = -times ; i <= times ; i++ )
		{
			for(int j = -times ; j <= times ; j++ )
			{
				if(Math.abs(i)+Math.abs(j)<=times)
				{
					System.out.print("*");
				}
				else
				{
					System.out.print(" ");
				}
			}
			System.out.printf("\n");
		}
	}
}