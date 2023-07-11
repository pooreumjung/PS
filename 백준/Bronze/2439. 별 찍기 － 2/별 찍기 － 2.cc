#include<iostream>
using namespace std;
int main()
{
  int num;
  cin >> num;
  int stars = 1;
  for (int a = 0; a < num; a++)
  {
    for (int b = 0; b < num; b++)
    {
      if (b >= num - stars)
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << "\n";
    stars++;
  }
  return 0;
}
