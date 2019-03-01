#include <iomanip>
#include <stdio.h>

using namespace std;

int Get_indent(int rezult);
void show(int a, int b, int indent);

int main()
{
	int numA, numB;
	printf("input numA: ");
	scanf_s("%u", &numA);
	printf("input numB: ");
	scanf_s("%u", &numB);

	system("cls");

	int indent = Get_indent(numA * numB);
	
	show(numA, numB, indent);
	printf("\n%*u ", indent, numA * numB);
	return 0;
}

int Get_indent(int rezult)                 //Функция для посчета отступа
{                                         
	int indent = 2;
	do
	{
		indent++;
		rezult /= 10;
	} while (rezult);
	return indent;
}


void show(int numA, int numB, int indent)
{
	printf("%*u", indent, numA);
	printf("\nx");
	printf("\n%*u ", indent, numB);
	printf("\n ---------");

	if (numB / 10)
	{
		do
		{
			if (numB / 10 == 0) printf("\n%*u", indent, numA* (numB % 10));
			else printf("\n+%*u", --indent, numA * (numB % 10));
			numB /= 10;
		} while (numB);
		printf("\n ---------");
	}
}
