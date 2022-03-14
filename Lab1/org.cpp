#include<stdio.h>
#include<iostream>
#include<sys/time.h>
using namespace std;
const int n = 100;//size
const int r = 1000;//repeat time
const double MAX = 999999, MIN = -999999;
double x[n][n];
double y[n];
double res1[n], res2[n];
double randou(double max, double min) {
	srand((unsigned)time(0));
	return min + rand() / (double)(RAND_MAX / (max - min));
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = randou(MAX, MIN);
		}
	}
	for (int i = 0; i < n; i++) {
		y[i] = randou(MAX, MIN);
		res1[i] = 0;
		res2[i] = 0;
	}
}

void normal() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res1[i] += x[j][i] * y[j];
		}
	}
}
void improve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res2[j] += x[i][j] * y[i];
		}
	}
}

int main()
{
	init();
	struct  timeval   tv_begin,tv_end;
	gettimeofday(&tv_begin,NULL);
	for(int i=0;i<r;i++){
		normal();
	}
	gettimeofday(&tv_end,NULL);
	cout.precision(10);
	cout<<"Normal:"<<(((double)tv_end.tv_sec-(double)tv_begin.tv_sec)*1000+((double)tv_end.tv_usec-(double)tv_begin.tv_usec)/1000)/r<<"ms"<<endl;


	//init();
	gettimeofday(&tv_begin,NULL);
	for(int i=0;i<r;i++){
		improve();
	}
	gettimeofday(&tv_end,NULL);
	
	cout<<"Optim:"<<(((double)tv_end.tv_sec-(double)tv_begin.tv_sec)*1000+((double)tv_end.tv_usec-(double)tv_begin.tv_usec)/1000)/r<<"ms"<<endl;
	
}

