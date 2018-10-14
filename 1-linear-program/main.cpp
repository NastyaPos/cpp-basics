#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	float z1, z2, a;
	cout << "vvedite znachenie argumenta" << endl;
	cin >> a;
	z1 = cos(a) + cos(2 * a) + cos(6 * a) + cos(7 * a);
	z2 = 4 * cos(a / 2)*cos(5 * a / 2)*cos(4 * a);
	cout << "\nz1= " << z1 << "\nz2= " << z2 << endl;
	return 0;
}
