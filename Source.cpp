#include<iostream>
#include<string>
#include<fstream>
#include"Directory.h"

using namespace std;

int main()
{
	Firm fm("Novus", "Vova", "097-111-11-11", "sldkfja", "trade");
	Firm fm2("Lita", "Dima", "097-222-22-22", "slkdfj;'sdfj", "trade");
	Directory dr;
	dr.AddToHead(fm);
	dr.AddToTail(fm2);
	dr.ShowDirectory();
	

	system("pause");
	return 0;
}