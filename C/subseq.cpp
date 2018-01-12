#include <stdio.h>
#include <stdlib.h>
//#include "Timer.h"

#define MAX 1000000

int n;// number of elements
int a[MAX];

void generate(int n, char* fn){
	FILE*f = fopen(fn,"w");
	fprintf(f,"%d\n",n);
	
	for(int i = 0; i < n; i++){
		// generate a random value and write to file
		int x = 100-rand()%200;
		fprintf(f,"%d ",x);
	}
	fclose(f);
}

void readData(char* fn){
	FILE* f = fopen(fn,"r");
	fscanf(f,"%d",&n);
	for(int i = 0; i < n; i++){
		fscanf(f,"%d",&a[i]);
	}
	
	fclose(f);
}

void algo1(){
	int max = -999999999;
	int i_max;// stores the value of i
	int j_max;// stores the value of j
	
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int w = 0;
			for(int k = i; k <= j; k++)
				w += a[k];
			if(w > max){
				max = w;
				i_max = i;
				j_max = j;
			}
		}
	}
	for(int k = i_max; k <= j_max; k++)
		printf("%d ",a[k]);
	printf("\n");
	printf("alog1, result = %d\n",max);
	
}

void algo2(){
	
	int max = 0;
	for(int i = 0; i < n; i++){
		int s = 0;
		for(int j = i; j < n; j++){
			s += a[j];
			if(s > max){
				max = s;
			}
		}
	}
	printf("algo2, result = %d\n",max);
}

int maxLeft(int* a, int l, int r){
	int max = -9999999;
	int s = 0;
	for(int i = r; i >= l; i--){
		s += a[i];
		if(s > max) max = s;
	}
	return max;
}

int maxRight(int* a, int l, int r){
	int max = -99999999;
	int s = 0;
	for(int i = l; i <= r; i++){
		s += a[i];
		if(s > max) max = s;
	}
	return max;
}

int maxSeq(int* a, int l, int r){
	if(l == r) return a[l];
	
	int max;
	int mid = (l+r)/2;
	int mL = maxSeq(a,l,mid);
	int mR = maxSeq(a,mid+1,r);
	int mLR = maxLeft(a,l,mid) + maxRight(a,mid+1,r);
	
	max = mL;
	if(max < mR) max = mR;
	if(max < mLR) max = mLR;
	return max;
}

void algo3(){
	int max = maxSeq(a,0,n-1);
	printf("algo3, result = %d\n",max);
}

int main(){
	//char* filename = argv[1];
	
	//n = atoi(argv[2]);
	//generate(10000,"list-10000");
	
	
	//Timer ti;
	
	readData("list-10000.txt");
	//algo1();
	//algo2();
	algo3();
	
	//printf("execution time = %lf",ti.getElapsedTime());
	
}
