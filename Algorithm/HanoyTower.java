import java.util.*;
public class HanoyTower
{

	void tower(int disk,char from, char to, char temp)
	{
		if(disk == 1)
		{
			System.out.printf("Move Disk 1 from tower %c to tower %c\n", from,to);
			return;
		}

		tower(disk-1,from,temp,to);
		System.out.printf("Move Disk %d from tower %c to tower %c\n",disk,from,to);
		tower(disk-1,temp,to,from);
	}

	HanoyTower()
	{
		tower(3,'A','C','B');
	}

	public static void main(String args[])
	{
		new HanoyTower();
	}
}