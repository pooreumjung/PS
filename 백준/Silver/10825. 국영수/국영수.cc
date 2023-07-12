#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct student {	
	string name;	
	int ko;	
	int en;	
	int ma;	
};

bool cmp(student a, student b)	
{
	if (a.ko == b.ko)	
	{
		if (a.en == b.en)	
		{
			if (a.ma == b.ma)	
			{
				return a.name < b.name;	
			}

			return a.ma > b.ma;	
		}

		return a.en < b.en;	
	}
	return a.ko > b.ko;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;	

	vector<student>v(n);

	for (int i = 0; i < n; i++)	
	{
		cin >> v[i].name >> v[i].ko >> v[i].en >> v[i].ma;
	}

	sort(v.begin(), v.end(), cmp);	

	for (int i = 0; i < n; i++)	
		cout << v[i].name<<'\n';

	return 0;
}