import java.io.*;

public class BuffReader
{
	public static void main(String args[])
	{
		try{
			BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

			String temp = input.readLine();
			/*
			System.out.println(temp);

			int x = Integer.parseInt(temp);
			*/
			System.out.print(temp.trim());

			int a = 5;
			int b = ++a;
			int c = a++;
			System.out.print(b);
			System.out.print(c);

			for(int i = 0 ; i < 5 ; ++i)
			{
				System.out.print(i);
			}

		}catch(Exception e){System.out.println("ERROR");}
	}
}