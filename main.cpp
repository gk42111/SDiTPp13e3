#include "Test.h"
#include <iostream>
#include <algorithm>
#include <time.h>
#include <Windows.h>
using namespace std;

int main() {
	Test test, test1, test2, test3;
	clock_t start, stop, start1, stop1, start2, stop2, start3, stop3;
	start = clock();
	test.sort_b();
	stop = clock();
	start1 = clock();
	test1.sort_wstawianie();
	stop1 = clock();
	start2 = clock();
	std::sort(test2.a.begin(), test2.a.end());
	stop2 = clock();
	start3 = clock();
	test3.a = test3.mergeSort(test3.a);
	stop3 = clock();
	double czas, czas1, czas2, czas3;
	czas = (stop - start); czas1 = (stop1 - start1); czas2 = (stop2 - start2);  czas3 = (stop3 - start3);
	cout << "babelkowo: " << czas << " wstawianie: " << czas1 << " wbud.: " << czas2 <<" scal: "<<czas3<< endl;
	system("pause");
	return 0;
}