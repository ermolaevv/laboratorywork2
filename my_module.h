#pragma once

struct programInfo
{
	double a, b, h;
	double* x, * fx, * fprx;
	double (*func1) (double, int);
	double (*func2) (double);
	int n;
	int size;
};

// Math Functions
unsigned long long my_factorial(unsigned long long n);
double my_pow(double num, int power);
double my_exp(double num, int n);
double my_exp2(double num, int n);
double fast_exp(double y, int n);
double my_sin(double num, int n);
double fast_sin(double y, int n);
double my_cos(double num, int n);
double fast_cos(double y, int n);
double my_ln(double y, int n);
double my_ln2(double y, int n);

// Service Functions
void print(programInfo * info);
void setArrayValues(programInfo* info);
void initSegment(programInfo* info);
