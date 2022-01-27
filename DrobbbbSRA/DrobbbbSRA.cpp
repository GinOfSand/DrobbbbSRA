#include <iostream>
#include "Drobi.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	// числитель, знаменатель, целые
	Drobi d1(0,0,10), d2(1,4,6), d3, d4, d5, d6;
	cout << "Первое число\n";
	d1.Display();
	cout << "Второе число\n";
	d2.Display();
	cout << "Сложение\n";
	d5 = d1 + d2;
	d5.Display();
	cout << "Вычитиние\n";
	d3 = d1 - d2;
	d3.Display();
	cout << "Умножение\n";
	d4 = d1 * d2;
	d4.Display();
	cout << "Деление\n";
	d6 = d1 / d2;
	d6.Display();
}
