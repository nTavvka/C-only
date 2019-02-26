
#include <iomanip>
#include <algorithm>
#include <stdio.h>

using namespace std;

int Get_indent(int rezult);
void show(int a, int b, int indent);

int main()
{
  int numA, numB;
  scanf_s("%u", &numA);
  scanf_s("%u", &numB);

  system("cls");
  
  if (numA < numB)
  {
	  numA = numA ^ numB;
	  numB = numA ^ numB;
	  numA = numA ^ numB;
  }

  int indent;

  indent = Get_indent(numA * numB);
  show(numA, numB, indent);
  printf("\n%*u ", indent, numA * numB);
	return 0;
}

int Get_indent(int rezult)
{
	int indent = 1;
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

	int i = 1;
	if (numB / 10)
	{
		do
		{
			if (numB / 10 == 0) printf("\n%*u", indent - i, numA* (numB % 10));
			else printf("\n+%*u", indent - i, numA * (numB % 10));
			numB /= 10;
			i++;
		} while (numB);
		printf("\n ---------");
	}
}
