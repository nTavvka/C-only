
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int Get_size(int rezult);
void show(int a, int b);

int main()
{
	long int a, b;
	cin >> a >> b;
	system("cls");

	show(a, b);

	return 0;
}

int Get_size(int rezult)
{
	int size = 1;
	do
	{
		size++;
		rezult /= 10;
	} while (rezult);
	return size;
}

void show(int a, int b)
{
	int size = Get_size(a*b) ;
	if (b > a) swap(a, b);
	int rezult = a * b;

	cout << setw(size) << right << a << endl << 'x' << endl << setw(size) << right << b << endl;
	cout << setfill('-') << setw(size) << '-' << endl;
	cout.fill(' ');
	
	if (b / 10)
	{
		int i = 0;
		cout.setf(ios::showpos);
		do
		{
			if (b / 10 == 0) cout.unsetf(ios::showpos);
			cout << setw(size - i) << a * (b % 10) << endl;
			b /= 10;
			i++;
		} while (b);
		cout << setfill('-') << setw(size) << '-' << endl;
	}
	cout.fill(' ');
	cout << setw(size) << right << rezult << endl;
}
