#include <iostream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
int result = 0;

int findUnion(vector<int>& arrayOfRelationship, int indexFromUnion);
void doLink(vector<int>& arrayOfRelationship, int firstIndex, int secondIndex);

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	int m;
	in >> n >> m;
	vector<int> arrayOfRelationship(n, -1);
	pair<int, int> tmp;
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		in >> tmp.first >> tmp.second;
		doLink(arrayOfRelationship, --tmp.first, --tmp.second);
	}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << arrayOfRelationship.at(i) << ' ';
	//	if (arrayOfRelationship.at(i) < 0)
	//	{
	//		result++;
	//	}
	//}
	//cout << endl;
	//cout << result << endl;
	out << result;

	//system("pause");
	return 0;
}

int findUnion(vector<int>& arrayOfRelationship, int indexFromUnion)
{
	if (arrayOfRelationship.at(indexFromUnion) < 0)
	{
		return indexFromUnion;
	}
	arrayOfRelationship.at(indexFromUnion) = findUnion(arrayOfRelationship, arrayOfRelationship.at(indexFromUnion));
	return arrayOfRelationship.at(indexFromUnion);
}

void doLink(vector<int>& arrayOfRelationship, int firstIndex, int secondIndex)
{
	int firstParent = findUnion(arrayOfRelationship, firstIndex);
	int secondParent = findUnion(arrayOfRelationship, secondIndex);
	if (firstParent == secondParent)
	{
		result++;
		return;
	}
	if (arrayOfRelationship.at(firstParent) < arrayOfRelationship.at(secondParent))
	{
		arrayOfRelationship.at(firstParent) += arrayOfRelationship.at(secondParent);
		arrayOfRelationship.at(secondParent) = firstParent;
	}
	else
	{
		arrayOfRelationship.at(secondParent) += arrayOfRelationship.at(firstParent);
		arrayOfRelationship.at(firstParent) = secondParent;
	}
}
