#include <iostream>
#include <cstring>

using namespace std;

int number_fix = 0;

int calculate1(int number, int decrement)
{
	if (decrement == 0)
	{
		return number;
	}

	number += decrement;

	calculate1(number, --decrement);
}

void reverse_msg()
{
	char m;

	cin >> m;
	if (m == '.')
	{
		return;
	}

	reverse_msg();

	cout << m << endl;
}

int factorial(int n)
{
	if (n == 0)
	{
		return 0;
	}

	cout << n * factorial(n - 1) << endl;
}

int fib(int num)
{
	int prev = 0;
	int next = 1;
	int temp;

	cout << prev << " ";

	for (size_t inc = 0; inc < 10; inc++)
	{
		temp = prev + next;
		prev = next;

		cout << next << " ";

		next = temp;
	}
}

void fib_rec(int num, int prev = 0, int next = 1)
{
	int temp = prev + next;

	if (num == 0)
		return;

	prev = next;
	cout << next << endl;
	next = temp;

	fib_rec(--num, prev, next);
}

int exer1(int n)
{
	if (n == 0)
		return n;

	exer1(--n);

	cout << n << " ";

	if (number_fix-1 == n)
		cout << n+1 << " ";
}

void ex2(int n)
{
	if (n == -1)
		return;

	cout << n << " ";
	ex2(--n);
}
void ex3(int n)
{
	if (n == 0)
		return;

	cout << n << " ";
	n--;
	ex3(n);

	cout << n << ' ';
	if (n == 4)
		cout << (n = 5) << " ";
}

void ex4(int n, int c = 0)
{
	if (c == n)
	{
		return;
	}

	cout << c << " ";

	ex4(n, ++c);

	cout << c << " ";
	if (c == 1)
	{

		cout << (c = 0) << " ";
	}
}
int gcd_div(int n1, int n2, int i =1, int prev =0)
{
	if (i > n2)
		return prev;

	if (n1%i == 0 && n2%i == 0)
		prev = i;

	gcd_div(n1, n2, ++i, prev);
}

int gcd_sub(int n1, int n2)
{
	if (n1 == n2)
		return n2;

	if (n1 > n2)
		gcd_sub(n1-n2, n2);
	else
		gcd_sub(n1, n2-n1);
}

int dividor(int n1, int n2)
{
	while (n1 != n2)
		if (n1 > n2)
			n1-=n2;
		else
			n2-=n1;

	return n2;
}

int main()
{
	cout << gcd_sub(36, 16);
}
