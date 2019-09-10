#include<stdio.h>
#include<Windows.h>

char map[20][20];
int sudah[20],nilai[20];
const int batas=8;

void initMap()
{
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j <= 8 ; j++)
		{
			map[i][j]='.';
		}
	}
}

void printMap()
{
	for(int i = 0 ; i<8 ; i++)
	{
		printf("  %d ",i+1);
	}
	printf("\n");

	for(int i = 0 ; i<8 ; i++)
	{
		printf("====");
	}
	printf("=\n");

	for(int i = 0 ; i < 8 ; i++)
	{
		for(int j = 0 ; j <= 8 ; j++)
		{
			if(j==8)
			{
				printf("| %d ",i+1);
			}
			else
			{
				printf("| %c ",map[i][j]);
			}
		}
		printf("|\n");
	}
	for(int i = 0 ; i<8 ; i++)
	{
		printf("====");
	}
	printf("=\n");
}

bool isWin()
{
	/*for(int i = 0 ; i < batas ; i ++)
	{
		for(int j = 0 ; j < batas ; j ++)
		{
			if(map[i][j]=='.')
			{
				return false;
			}
		}
	}*/
	int queenIndex = 0;
	for(int i = 0 ; i < batas ; i ++)
	{
		for(int j = 0 ; j < batas ; j ++)
		{
			if(map[i][j]=='Q')
			{
				queenIndex++;
			}
		}
	}
	if(queenIndex!=batas)
	{
		return false;
	}

	return true;
}

void initQueen(int x , int y)
{
	if(map[y][x]=='*')
	{
		return;
	}
	for(int i = 0 ; i < batas ; i++)
	{
		for(int j = 0 ; j < batas ; j++)
		{
			if(map[i][j]!='Q')
			{
				if( j==x || i==y )
					map[i][j]='*';
				if((i+j)==(x+y))
					map[i][j]='*';
				if((i-j)==(y-x))
					map[i][j]='*';
			}
		}
	}
	map[y][x] = 'Q';
}

void resetMap(){
	for(int i=0;i<batas;i++){
		for(int j=0;j<batas;j++)map[i][j]='.';
	}
}

void ai_map(int kolom){

	if(kolom==batas){//cetak posisi

		for(int i=0;i<batas;i++)
		{
			initQueen(i,nilai[i]);
		}

		if(isWin())printMap();
		resetMap();
		return ;
	}

	for(int i=0;i<batas;i++){//iterasi semua baris

		if(sudah[i]==0){//belum dikunjungi
			sudah[i]=1;//tandai kunjungi
			nilai[kolom]=i;// simpan posisi(nilai kolom = baris berapa?)
			ai_map(kolom+1);
			sudah[i]=0;
		}

	}

}

int main()
{
	initMap();
	printMap();
	int x,y;
	while(!isWin())
	{
		//do{
			printf("x-pos : ");
			scanf("%d",&x);
			printf("y-pos : ");
			scanf("%d",&y);
		//}while( x<1 || x>8 || y < 1 || y > 8 );
		system("cls");
		if(x==0 && y ==0)
		{
			for(int i=0;i<batas;i++)sudah[i]=0;
			ai_map(0);
			printf("Give Up");
			getchar();
			getchar();
			return 0;
		}
		else
		{
			initQueen(x-1,y-1);
		}
		printMap();
	}
	printMap();
	printf("You Win..");
	getchar();
	getchar();
	return 0;
}
