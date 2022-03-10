#include<stdio.h>
#include<iostream>
#include<sys/time.h>
using namespace std;
//#include<stdlib.h>
const int n = 1000;
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
void ifright() {
	for (int i = 0; i < n; i++) {
		if (res1[i] != res2[i])
			cout << "Wrong";
	}
}
int main()
{
	init();
	struct  timeval   tv_begin,tv_end;
	gettimeofday(&tv_begin,NULL);
	improve();
	gettimeofday(&tv_end,NULL);
	cout<<tv_end.tv_sec-tv_begin.tv_sec<<' '<<tv_end.tv_usec-tv_begin.tv_usec<<endl;


	init();
	gettimeofday(&tv_begin,NULL);
	normal();
	gettimeofday(&tv_end,NULL);
	
	cout<<tv_end.tv_sec-tv_begin.tv_sec<<' '<<tv_end.tv_usec-tv_begin.tv_usec<<endl;
	
}

