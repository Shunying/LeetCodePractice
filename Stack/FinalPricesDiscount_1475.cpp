/*
Reference link:
  1. 
  2. https://www.youtube.com/watch?v=X98Yc4YtgyA&list=PLLuMmzMTgVK7eabhqdNs1wQv0cFEbd048
*/

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public: 
  vector<int> finalPrices(vector<int> prices) {
    stack<int*> s;
    for (auto & p : prices) 
    {
        while (!s.empty() && *s.top() >= p) {
            *s.top() -= p;
            s.pop();
        } 
        s.push(&p);
    }
    return prices;
  }  
};

class Solution2 {
public:
  vector<int> finalPrices(vector<int> prices) {
    stack<int> s;
    for (int i=0; i < prices.size(); ++i) {
      while (!s.empty() && prices[s.top()] >= prices[i]) {
        prices[s.top()] -= prices[i];
        s.pop();
      }
      s.push(i);
    }
    return prices;
  }
};

/*=== Main Function for Testing ===*/
int main()
{
  Solution solution_obj;
  vector<int> prices1;
  prices1 = {8, 4, 6,2, 3};
  vector<int> prices2;
  prices2 = {3, 4, 5, 1};
  
  cout << "Prices1:" << endl;
  for (auto & p : prices1)
  {
    cout << p << " ";
  }
  cout << endl;

  cout << "Final prices for prices1:" << endl;
  vector<int> prices1_final = solution_obj.finalPrices(prices1);
  for (auto & p : prices1_final)
  {
    cout << p << " ";
  }
  cout << endl;

  cout << "Prices2:" << endl;
  for (auto & p : prices2)
  {
    cout << p << " ";
  }
  cout << endl;
  
  cout << "Final prices for prices2:" << endl;
  vector<int> prices2_final = solution_obj.finalPrices(prices2);
  for (auto & p : prices2_final)
  {
    cout << p << " ";
  }
  cout << endl;
  return 0;
}