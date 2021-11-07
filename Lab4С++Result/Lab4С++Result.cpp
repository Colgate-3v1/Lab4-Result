#include <iostream>
#include "Result.h"
#include <string>
#include <regex>
int main()
{
	setlocale(LC_ALL, "Russian");
	Result c1("Футбол", "Барселона", 5),c3("Футбол", "Атлетико", 2);
	cout << c1<< endl;
	c1 = Result(c3);
	cout << c1<<endl;
	Result c2;
	c2 = plus_place(c1);
	cout << c2<< endl;
	return 0;
}