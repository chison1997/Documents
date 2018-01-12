#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

 main()
{
	string name[5000], like[10000];
	int countLike=0, countFriend=0, i, j;

	string sLine = "";
	ifstream friendFile, likeFile;

	//doc danh sach ban tu friedFile.txt
	friendFile.open("friendFile.txt");
	do
	{
		getline(friendFile, sLine); 
		if(sLine != "B?n bè" && isalpha(sLine[0]) )
		{
			name[ countFriend ] = sLine;
			countFriend++;
		}
	}	while ( ! friendFile.eof());
	friendFile.close();

	//doc danh sach ban be like cac bai viet tu likeFile.txt
	likeFile.open("likeFile.txt");
	do
	{
		getline(likeFile, sLine);
		like[ countLike ]=sLine;
		countLike++;
	}	while ( ! likeFile.eof());
	
	likeFile.close();

	// In ra danh sach ban be khong like
	printf("\n Xoa bo: \n");

	for(i = 0; i < countFriend; i++) 
	{
		if (name[i] == "B?n bè") continue;
		for(j = 0; j < countLike; j++)
		{
			if ( name[ i ] == like[ j ]) break;
		}
		if (( j == countLike) && ( isalpha( name[ i ][ 0 ])) )cout << name[i] << endl << endl;
	}
	
	getch();
}

