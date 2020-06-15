#pragma once
#include <vector>
class Test
{
public:
	std::vector<int> a;
	Test();
	Test(int);
	void sort_b();
	void sort_wstawianie();
	std::vector<int> merge(std::vector<int>, std::vector<int>);
	std::vector<int> mergeSort(std::vector<int>);
};

