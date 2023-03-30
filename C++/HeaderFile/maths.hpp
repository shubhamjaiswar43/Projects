#ifndef iostream
#include <iostream>
#endif
#ifndef PI
#define PI 3.141592654
#define E 2.718281828459045
#endif
using namespace std;
template <class T>
T absolute(T x) // absolute(modulus)
{
	if (x < 0)
	{
		x *= (-1);
	}
	return x;
}
double power(double x, int y) // power
{
	double ans = 1;
	for (int i = 0; i < y; i++)
	{
		ans *= x;
	}
	return ans;
}
unsigned long long int factorial(int x) // factorial
{
	unsigned long long int fact = 1;
	if (x > 20)
	{
		return -1;
	}
	for (int i = 1; i <= x; i++)
	{
		fact *= i;
	}
	return fact;
}
int permutation(int n, int r) // permutation
{
	int ans;
	ans = (factorial(n)) / (factorial(n - r));
	return ans;
}
int combination(int n, int r) // combination
{
	int ans;
	ans = (factorial(n)) / (factorial(r) * factorial(n - r));
	return ans;
}
double sine(double rad) // sine(radian)
{
	double ans = 0;
	int sign = 1;
start:
	while (rad >= PI)
	{
		rad -= PI; // because sin(rad) = sin(pi + rad)
	}
	while (rad < 0)
	{
		rad = PI - rad; // because -sin(rad) = sin(pi - rad)
	}
	if (rad >= PI || rad < 0)
		goto start;
	if (rad == 0 || rad == PI)
	{
		return 0;
	}
	for (int i = 1; i <= 20; i += 2) // 10 iteration of sine expansion
	{
		sign ? ans += power(rad, i) / factorial(i) : ans -= power(rad, i) / factorial(i);
		sign = sign ? 0 : 1;
	}
	return ans;
}
double cosine(double rad)
{
	double ans = 0;
	int sign = 0;
start:
	while (rad >= (2 * PI))
	{
		rad -= (2 * PI); // cos(2pi+rad) = cos(rad)
	}
	while (rad < 0)
	{
		rad = (-1) * rad; // cos(-rad) = rad
	}
	if (rad >= (2 * PI) || rad < 0)
		goto start;

	for (int i = 0; i <= 20; i += 2) // 10 iteration of sine expansion
	{
		if (i > 0)
		{
			sign ? ans += power(rad, i) / factorial(i) : ans -= power(rad, i) / factorial(i);
			sign = sign ? 0 : 1;
		}
		else
		{
			ans += 1;
		}
	}
	return ans;
}
double tangent(double rad)
{
	double ans;
start:
	while (rad >= (2 * PI))
	{
		rad -= PI; // tan(rad) = tan(pi + rad)
	}
	while (rad < 0)
	{
		rad = PI + rad; //-tan(rad)=tan(pi-rad)
	}
	if (rad < 0 || rad >= (2 * PI))
		goto start;
	if (rad != (PI / 2) && rad != (3.142 / 2) && rad != (3.1415 / 2) && rad != (3.14 / 2))
	{
		ans = sine(rad) / cosine(rad);
		return ans;
	}
	ans = 0.0 / 0.0; // nan
	return ans;
}
double cosecant(double rad) // inverse of sine
{
	double ans;
	if (rad != 0 && rad != (PI) && rad != (3.142) && rad != (3.1415) && rad != (3.14))
	{
		ans = 1.0 / sine(rad);
		return ans;
	}
	ans = 0.0 / 0.0;
	return ans;
}
double secant(double rad) // inverse of cos
{
	double ans;
	if (rad != (PI / 2) && rad != (3.142 / 2) && rad != (3.1415 / 2) && rad != (3.14 / 2))
	{
		ans = 1.0 / cosine(rad);
		return ans;
	}
	ans = 0.0 / 0.0;
	return ans;
}
double cotangent(double rad) // inverse of tan
{
	double ans;
	if (rad == (PI / 2) || rad == (3.142 / 2) || rad == (3.1415 / 2) || rad == (3.14 / 2))
	{
		return 0;
	}
	else if (rad != 0 && rad != (PI) && rad != (3.142) && rad != (3.1415) && rad != (3.14))
	{
		ans = 1.0 / tangent(rad);
		return ans;
	}
	ans = 0.0 / 0.0;
	return ans;
}
double logBaseE(double x) // Natural logrithm
{
	/*
	NATURAL LOGRITHM GENERAL DEFINATION IS USED IN THIS(INSTEAD OF EXPANSION) :
	NATURAL LOG OF ANY NUMBER IS, HOW MANY TIMES OF E IS EQUAL TO THAT NUMBER
	i.e => ln(x)=b
		=> e^(b) = x
	*/
	bool sign = 0;
	if (x == 0) // ln(0)=nan
	{
		return (0.0 / 0.0);
	}
	if (x < 1)
	{
		x = 1 / x;
		sign = 1;
	}
	double ans = 0, temp = x;
	while (temp > E)
	{
		ans++;
		temp /= E;
	}
	// if it become less than e than taking power of 10 and adding 1 after the decimal
	for (int i = 0; i < 6; i++)
	{
		temp = power(temp, 10);
		while (temp > E)
		{
			ans += 0.1 / power(10, i);
			temp /= E;
		}
	}

	/*ALTERNATE METHOD FOR PRECESION*/
	// double p = 1.0;
	// for (int i = 0; i < 60; i++)
	// {
	// 	temp *= temp;
	// 	p /= 2;
	// 	if (temp > E)
	// 	{
	// 		ans += p;
	// 		temp /= E;
	// 	}
	// }

	if (sign)
	{
		ans *= (-1);
	}
	return ans;
}
double logXbaseY(double x, double y)
{
	// Using base changing rule in this
	if (x == 0 || y == 0 || y == 1)
	{
		return (0.0 / 0.0);
	}
	if (x == (1 / y))
	{
		return -1;
	}
	if (x == y)
	{
		return 1;
	}
	double ans;
	ans = logBaseE(x) / logBaseE(y);
	return ans;
}
double exponent(double x)
{
	double ans = 1;
	// Instead of using expansion , I hard coding the value of roots , and using rule of indices(x^(y) = x^(a)*x(b)    ,where a+b=y)
	//  			Roots      	1  10           100          1000       10000
	const float eRoot[5] = {E, 1.105170918, 1.010050167, 1.0010005, 1.000100005};
	int temp = x; // taking
	bool sign = 0;
	if (x < 0)
	{
		sign = 1;
		x *= (-1);
		temp = x;
	}
	for (int i = 0; i < 5; i++)
	{
		ans *= power(eRoot[i], temp);
		x -= temp;
		x *= 10;
		temp = x;
		if (x == 0)
			break;
	}
	if (sign)
	{
		ans = 1 / ans;
	}
	return ans;
}
double xRaiseToy(double x, double y)
{
	/* 	Using log property for this
		ans = x^(y)
		ln(ans) = y*ln(x)
		ans = e^(y*ln(x))
	*/
	double ans;
	ans = exponent((double)y * logBaseE(x));
	return ans;
}
double squareRoot(double x)
{
	return xRaiseToy(x, 0.5);
}