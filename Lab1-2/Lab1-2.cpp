#include<stdio.h>
#include <sys/time.h>
#include<iostream>
using namespace std;

const int n = 67108864;
const int r=1;
const double Max = 9999, Min = 0;
double a[n],are[n],atree[n];
double sum1, sum2, sum3;
void normal() {
	for (int i = 0; i < n; i++) {
		sum1 += a[i];
	}
}
void doulink() {
	double x = 0, y = 0;
	for (int i = 0; i < n; i+=2) {
		x += a[i];
		y += a[i + 1];
	}
	sum2 = x + y;
}
void recursion(int size=n) {
	if (size == 1)
		return;
	else {
		for (int i = 0; i < size / 2; i++) {
			are[i] += are[size - i - 1];
		}
		recursion(size / 2);
	}
}

void treelike() {
	for (int m = n; m > 1; m /= 2) {
		for (int i = 0; i < m / 2; i++) {
			atree[i] = atree[i * 2] + atree[i * 2 + 1];
		}
	}
}
double randou(double max, double min) {
	srand((unsigned)time(0));
	return min + rand() / (double)(RAND_MAX / (max - min));
}
void init() {
	sum1 = 0; sum2 = 0; sum3 = 0;
	for (int i = 0; i < n; i++) {
		a[i] = i; //randou(Max, Min);
		are[i] = a[i];
		atree[i] = a[i];
	}
}

int main(int argc,char *argv[]) {
	init();
	struct  timeval   tv_begin,tv_end;
	if(argv[1][0]=='1'){
	gettimeofday(&tv_begin,NULL);
		normal();
	gettimeofday(&tv_end,NULL);
	cout.precision(10);
	cout<<"Normal:"<<fixed<<(((double)tv_end.tv_sec-(double)tv_begin.tv_sec)*1000.0+((double)tv_end.tv_usec-(double)tv_begin.tv_usec)/1000.0)/r<<endl;
	}
	else if(argv[1][0]=='2'){
	gettimeofday(&tv_begin,NULL);
		doulink();
	gettimeofday(&tv_end,NULL);
	cout<<"doulink:"<<fixed<<(((double)tv_end.tv_sec-(double)tv_begin.tv_sec)*1000.0+((double)tv_end.tv_usec-(double)tv_begin.tv_usec)/1000.0)/r<<endl;
	}
	else if(argv[1][0]=='3'){
	gettimeofday(&tv_begin,NULL);
		recursion();
	gettimeofday(&tv_end,NULL);
	cout<<"recursion:"<<fixed<<(((double)tv_end.tv_sec-(double)tv_begin.tv_sec)*1000.0+((double)tv_end.tv_usec-(double)tv_begin.tv_usec)/1000.0)/r<<endl;
	}
	else if(argv[1][0]=='4'){
	gettimeofday(&tv_begin,NULL);
		treelike();
	gettimeofday(&tv_end,NULL);
	cout<<"treelike:"<<fixed<<(((double)tv_end.tv_sec-(double)tv_begin.tv_sec)*1000.0+((double)tv_end.tv_usec-(double)tv_begin.tv_usec)/1000.0)/r<<endl;
	}
	cout.precision(5);
	cout <<fixed<< sum1 << ' ' << sum2 << ' ' << are[0] << ' ' << atree[0]<<endl;
}
