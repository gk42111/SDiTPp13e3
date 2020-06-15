#include "Test.h"
#include <cstdlib>
using namespace std;
Test::Test()
{
	for (int i = 0; i < 1000; i++) {
		a.push_back(std::rand());
	}
}

Test::Test(int b)
{
	a.resize(b);
}

void Test::sort_b()
{
	int p;
	int pmin = 0;
	int pmax = a.size() - 1;
	do
	{
		p = -1;
		for (int i = pmin; i < pmax; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				if (p < 0) pmin = i;
				p = i;
			}
		if (pmin) pmin--;
		pmax = p;
	} while (p >= 0);

}

void Test::sort_wstawianie()
{
	int pom, j;
	for (int i = 1; i < a.size(); i++)
	{
		pom = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > pom)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = pom;
	}
}


std::vector<int> Test::merge(vector<int> left, vector<int> right)
{
	vector<int> result;
	while ((int)left.size() > 0 || (int)right.size() > 0) {
		if ((int)left.size() > 0 && (int)right.size() > 0) {
			if ((int)left.front() <= (int)right.front()) {
				result.push_back((int)left.front());
				left.erase(left.begin());
			}
			else {
				result.push_back((int)right.front());
				right.erase(right.begin());
			}
		}
		else if ((int)left.size() > 0) {
			for (int i = 0; i < (int)left.size(); i++)
				result.push_back(left[i]);
			break;
		}
		else if ((int)right.size() > 0) {
			for (int i = 0; i < (int)right.size(); i++)
				result.push_back(right[i]);
			break;
		}
	}
	return result;
}



std::vector<int> Test::mergeSort(std::vector<int> m)
{

	if (m.size() <= 1)
		return m;

	vector<int> left, right, result;
	int middle = ((int)m.size() + 1) / 2;

	for (int i = 0; i < middle; i++) {
		left.push_back(m[i]);
	}

	for (int i = middle; i < (int)m.size(); i++) {
		right.push_back(m[i]);
	}

	left = mergeSort(left);
	right = mergeSort(right);
	result = merge(left, right);

	return result;
}
