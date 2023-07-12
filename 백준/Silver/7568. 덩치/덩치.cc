#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int N;
  cin >> N;
  int weight, height, count;
  vector<pair<int, int>> vec;
  
  for(int i = 0; i<N; i++)
    {
      cin >> weight >> height;
      vec.push_back(make_pair(weight, height));
    }

  for(int i = 0; i<vec.size(); i++)
    {
      count = 1;
      for(int j = 0; j<vec.size(); j++)
        {
          if(vec[i].first < vec[j].first && vec[i].second < vec[j].second)
            count++;
        }
        cout<<count<<' ';
    }

  return 0;
}