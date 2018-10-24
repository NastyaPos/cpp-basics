#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double kEps = 1e-15;

	double F, a, b, c, xn, xk, dx;
	cout << "vvedite a" << endl;
	cin >> a;
	cout << "vvedite b" << endl;
	cin >> b;
	cout << "vvedite c" << endl;
	cin >> c;
	cout << "vvedite xn" << endl;
	cin >> xn;
	cout << "vvedite xk" << endl;
	cin >> xk;
	cout << "vvedite dx" << endl;
	cin >> dx; 

	if ( dx<kEps ) 
	{
		cout << "dx vvedeno neverno!" << endl;
		return 1;
	}

	cout << setw(50) << "_________________________________\n";
	cout << setw(50) << "|       X       |       F       |\n";
	cout << setw(50) << "|---------------|---------------|\n";
 
	cout << fixed;
	cout.precision(3);


	for (double x = xn; x <= xk; x += dx)
	{
		if (c < 0 && !(abs(b)<kEps)) F = a * x*x + b * b*x;
		else if (abs(b)<kEps && c > 0) F = (x + a) / (x + c);
		else 
		{
			if (abs(c) < kEps)
			{
				cout << " division by 0 \n";
				continue;
			}
			else F = x / c;
		} 
		if ((int(a) && int(b)) | (int(a) && int(c)) != 0)
			cout << setw(22) << "|     " << x << "     |     " << F << "     |\n";

		else
			cout << setw(22) << "|    " << x << "    |    " << int(F) << "    |\n";

	}

	cout << setw(50) << "|_______________|_______________|\n";

	return 0;
}