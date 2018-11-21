#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void PrintTableHead() {
	cout << "| - - - - - - - - | - - - - - - - - ";
	cout << "| - - - - - - - - | - - - - - - - |\n";
	cout << "|        x        |  ln(1-x) (mine) ";
	cout << "| ln(1-x) (cmath) |   iterations  |\n";
	cout << "| - - - - - - - - | - - - - - - - - ";
	cout << "| - - - - - - - - | - - - - - - - |\n";
}

double ComputeSeries(double xn, int &n, const int MaxIters, double eps) {
	double ln = 0;
	for (n = 1; n <= MaxIters; n++)
	{
		double ch_r = pow(xn, n) / n;
		ln -= ch_r;
		if ((abs(ch_r) < eps) || (n > MaxIters)) break;
	}
return ln;	
}

void PrintTableRow(double xn, double ln, int n, const int MaxIters) {
	cout << "|" << setw(13) << xn << setw(5) << "|";

	if (n > MaxIters)
	{
		cout << setw(13) << "limit exceeded" << setw(4);
		cout << "|" << setw(13) << "limit exceeded" << setw(4);
		cout << "|" << setw(9) << "limit exceeded" << setw(3) << "|\n";

	}
	else
	{
		cout << setw(13) << ln << setw(5);
		cout << "|" << setw(13) << log(1 - xn) << setw(5);
		cout << "|" << setw(9) << n << setw(8) << "|\n";
	}
}
int main()
{
	const int MaxIters = 1000;
	double xn, xk, dx, eps;


	cout << "Dopustimyye znachenniya x: -1<=x<1" << endl;
	cout << "vvedite znachenie xn: ";
	cin >> xn;
	cout << "vvedite znachenie xk: ";
	cin >> xk;
	cout << "vvedite znachenie dx: ";
	cin >> dx;
	cout << "vvedite znachenie tochnosti eps: ";
	cin >> eps;

	if ((xn < -1) || (xn >= 1) || (xk < -1) || (xk >= 1) || (fabs(dx) < eps) || (eps <= 0))
	{
		cout << "wrong input data!!!";
		return 1;
	}

	PrintTableHead();

	cout << fixed;
	cout.precision(6);

	for (; xn <= xk; xn += dx)
	{
		int n;
		double ln = ComputeSeries(xn, n, MaxIters, eps);
		PrintTableRow(xn, ln, n, MaxIters);
	}
	cout << "| - - - - - - - - | - - - - - - - - ";
	cout << "| - - - - - - - - | - - - - - - - |";
	return 0;
}