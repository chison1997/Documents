#include <stdio.h>
#include <iostream>

using namespace std;

main()
{
    int k = 1;
    int n;

    cout<<"Nhap n: ";
    cin>>n;

    cout << "Nhap n: ";
    cin >> n;
    cout<<"Nhap n: ";
    cin>>n;
    while(n>=10)
    {
        n = n / 10;
        k++;
    }
    
    cout<<"Co " << k << " chu so" << endl;
}