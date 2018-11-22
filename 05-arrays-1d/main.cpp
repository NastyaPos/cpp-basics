#include <iostream>

using namespace std;

int main() {
	int const n = 12;
	int arr[n] = { -3, 32, 8, 0, 45, 23, -12, 1, 0, 10, 15,-6 };
	cout << "Initial array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	
	int arr_min = arr[0];

	for (int i = 1; i < n; i++)
		if (arr[i] < arr_min) arr_min = arr[i];
	cout << "\nmin = " << arr_min << endl;

	int firstpos = -1, lastpos = -1;

	for (int i = 0; i < n; i++)
		if (arr[i] > 0)
		{
			firstpos = i;
			break;
		}
	for (int i = n - 1; i >= 0; i--)
		if (arr[i] > 0)
		{
			lastpos = i;
			break;
		}
	if ((firstpos > -1) && (firstpos < lastpos))
	{
		int sum = 0;
		for (int i = firstpos + 1; i < lastpos; i++)
			sum += arr[i];

		cout << "sum = " << sum << endl;
	}
	else
	{
		cout << "\nNo two positive elements were found.";
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] != 0 && arr[j + 1] == 0)
				swap(arr[j], arr[j + 1]);

	cout << "\nchanged array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}