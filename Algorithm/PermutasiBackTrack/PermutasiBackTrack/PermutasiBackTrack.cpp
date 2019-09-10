#include<stdio.h>

#define batas 5

int map[10][10];
int sudah[10];
int nilai[10];


void init()
{
	for(int i = 0 ; i < batas; i++)
	{
		for(int j = 0 ; j < batas ; j++)
		{
			map[i][j]=0;
		}
	}
	for(int i = 0 ; i < batas ; i++)
	{
		sudah[i] = 0;
		nilai[i] = 0;
	}
}

void back_track(int kolom)
{
	if(kolom==batas)
	{
		for(int i = 0 ; i < batas ; i ++)
		{
			printf(" %d,%d",nilai[i],i);
		}
		printf("\n");
		return;
	}

	for(int i = 0 ; i < batas ; i ++)
	{
		if(sudah[i]==0)
		{
			sudah[i]=1;
			nilai[kolom]=i;
			back_track(kolom+1);
			sudah[i]=0;
		}
	}
}

int main()
{
	init();
	back_track(0);
	getchar();
	return 0 ;
}