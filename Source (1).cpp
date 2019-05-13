#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	vector<int> heap;
	in >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		in >> tmp;
		heap.push_back(tmp);
	}
	bool flag = true;
	for (int i = 1; i <= n / 2; i++)
	{
		if (heap.at(2 * i - 1) < heap.at(i - 1))
		{
			flag = false;
		}
		if (2 * i < n)
		{
			if (heap.at(2 * i) < heap.at(i - 1))
			{
				flag = false;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	out << ((flag) ? "Yes" : "No");
	return 0;
}