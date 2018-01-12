#include<stdio.h>
#include<conio.h>

struct time
	{
		int h;
		int m;
		int s;
	};

void InputTime(time *t, char Name[]);
time operator + (time t1, time t2);
time operator - (time t1, time t2);
int TimeToSecond(time t);
time SecondToTime(int second);


void InputTime(time *t, char Name[])
{
	
		printf("Nhap thoi gian %s: \n",Name);
		printf("\tGio: ");scanf("%d",&(t->h));
		printf("\tPhut: ");scanf("%d",&(t->m));
		printf("\tGiay: ");scanf("%d",&(t->s));

}

time operator + (time t1, time t2)
{
	time t; //t=t1+t2
	
//	t.s=(t1.s + t2.s) % 60;
//	t.m=(t1.m + t2.m + (t1.s + t2.s)/60 ) %60;
//	t.h= t1.h + t2.h + (t1.m + t2.m + (t1.s + t2.s)/60 )/60;
	
	t=SecondToTime( TimeToSecond(t1) + TimeToSecond(t2) );
	return t;
}

time operator - (time t1, time t2)
{
	time t; //t=t1-t2
	t=SecondToTime( TimeToSecond(t1) - TimeToSecond(t2) );
	return t;
	
}

int TimeToSecond(time t)
{
	int second=0;
	second=t.h * 3600 + t.m * 60 + t.s;
	return second;
}

time SecondToTime(int second)
{
	time t;
	t.h=second/3600;
	second=second%3600;
	t.m=second/60;
	second=second%60;
	t.s=second;
	return t;
}

main()
{
	time t1,t2,t;
	
	InputTime(&t1,"t1");
	InputTime(&t2,"t2");
	
	
	
	t=t1+t2;
	printf("tong thoi gian= %dh %dm %ds\n", t.h,t.m,t.s);
	
	t=TimeToSecond(t1) > TimeToSecond(t2) ? t1-t2 : t2-t1;
	printf("khoang cach giua 2 moc thoi gian= %dh %dm %ds\n", t.h,t.m,t.s);
	
	getch();
	
}
