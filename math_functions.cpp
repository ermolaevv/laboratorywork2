#define _USE_MATH_DEFINES
#include <math.h>

unsigned long long my_factorial(unsigned long long n)
{
	unsigned long long result = 1;
	for (int i = 2; i <= n; i++)
		result *= i;
	return result;
}

double my_pow(double num, int power)
{
	double result = 1;
	for (int i = 0; i < power; i++)
		result *= num;
	return num;
}

double my_exp(double num, int n)
{
	double result = 0;
	for (int i = 0; i <= n; i++)
		result += my_pow(num, i) / my_factorial(i);
	return result;
}

double my_exp2(double num, int n)
{
	double a = 1;
	double result = 1;

	for (int i = 1; i <= n; i++)
	{
		a *= num / i;
		result += a;
	}

	return result;
}


double my_sin(double num, int n)
{
	double a = num;
	double result = a;

	for (int i = 3; i <= n; i += 2)
	{
		a *= -(num * num) / ((i - 1) * i);
		result += a;
	}
	return result;
}

double my_cos(double num, int n)
{
	double a = 1;
	double result = a;

	for (int i = 2; i <= n; i += 2)
	{
		a *= -num * num / ((i - 1) * i);
		result += a;
	}
	return result;
}

// y in (0, 2]
double my_ln(double y, int n)
{
	double x = y - 1;
	double result = x, a = x;
	for (int i = 2; i <= n; i++)
	{
		a *= -x;
		result += a / i;
	}
	return result;
}

//ln(y) = 2(x + x^3/3 + x^5/5 + x^7/7 + ...) for all y = (1+x)/(1-x)
double my_ln2(double y, int n)
{
	double x = -(1 - y) / (y + 1);
	double a = x;
	double result = 0;

	for (int i = 1; i <= n; i += 2)
	{
		result += a / i;
		a *= x * x;
	}

	return 2 * result;
}

// sin(y) = sin(2pik+x) = sin(x)
double fast_sin(double y, int n)
{
	if (y > 0)
		y -= floor(y / (M_PI)) * M_PI;
	else
		y += -floor(-y / (M_PI)) * M_PI;
	return my_sin(y, n);
}

// cos(y) = cos(2pik+x) = cos(x)
double fast_cos(double y, int n)
{	
	if (y > 0)
		y -= floor(y / (M_PI)) * M_PI;
	else
		y += -floor(-y / (M_PI)) * M_PI;

	return my_cos(y, n);
}

// e^y = 2^k*e^x
// y = k*ln(2) + x
double fast_exp(double y, int n)
{
	double k = floor(y / M_LN2);

	return pow(2, k) * my_exp2(y - k * M_LN2, n);
}