#include<stdio.h>
#include<conio.h>

int DaysYear(int year)
{
	if (year%4) return 365;
	else if (year%100) return 366;
	else if (year%400) return 365;
	else return 366;
}

int DaysMonth(int month,int year)
{
	switch(month)
	{
		case 4: return 30;
		case 6: return 30;
		case 9: return 30;
		case 11: return 30;
		case 2: {if (year%4) return 28;
	else if (year%100) return 29;
	else if (year%400) return 28;
	else return 29;}
		default: return 31;
	}
}

int  NumbericalOrderDay(int day, int month, int year)
{
	int Days=day;
	for(int i=1;i<month;i++) Days+=DaysMonth(i,year);
	return Days;
	
	
}

int Again(int day, int month, int year)
{
	if ((day>DaysMonth(month,year))||(day<=0)||(year==0)||(month>12)||(month<=0)) return 1;
	else return 0;
	
}

main(){
	
	struct Date
			{
				int day;
				int month;
				int year;
			} Date1, Date2;
	
	do
	{
		printf("Thoi diem thu nhat:\n");
		printf("\tNgay: "); scanf("%d",&Date1.day) ;
		printf("\tThang: "); scanf("%d",&Date1.month) ;
		printf("\tNam: "); scanf("%d",&Date1.year) ;
	} while (Again(Date1.day,Date1.month,Date1.year));
	
	do{
	
	printf("Thoi diem thu nhat:\n");
		printf("\tNgay: "); scanf("%d",&Date2.day) ;
		printf("\tThang: "); scanf("%d",&Date2.month) ;
		printf("\tNam: "); scanf("%d",&Date2.year) ;
	} while(Again(Date2.day,Date2.month,Date2.year));
	
	int Days=0;
	
	for(int i=Date1.year+1;i<Date2.year;i++)
	{
		if (i==0) continue;
	 	Days+=DaysYear(i);
	}
	if (Date1.year!=Date2.year)
	Days+=DaysYear(Date1.year) - NumbericalOrderDay(Date1.day,Date1.month,Date1.year) + NumbericalOrderDay(Date2.day,Date2.month,Date2.year);
	else Days+=-NumbericalOrderDay(Date1.day,Date1.month,Date1.year) + NumbericalOrderDay(Date2.day,Date2.month,Date2.year);
	
	printf("%d", Days);
	
	
	
	
	
}
