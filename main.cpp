// A Naive recursive C++ program to find minimum of coins
// to make a given change V
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int max_coin( int *coin, int left, int right )
{
	if (left > right)
	return 0;

	int a = coin[left] + min( max_coin( coin, left+2,right ), max_coin( coin, left+1,right-1 ) );
//	cout << a << endl; 
	int b = coin[right] + min( max_coin( coin, left+1,right-1 ), max_coin( coin, left,right-2 ) );

	return max(a,b);
}
int minCoins(int coins[], int m, int V)
{
   // base case
   if (V == 0) return 0;
 
   // Initialize result
   int res = INT_MAX;
 
   // Try every coin that has smaller value than V
   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         int sub_res = minCoins(coins, m, V-coins[i]);
 
         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
         if (sub_res != INT_MAX && sub_res + 1 < res)
            res = sub_res + 1;
     }
   }
   return res;
}
 
//int max_coin( int *coin, int left, int right )
// Driver program to test above function
int main()
{
    int coins[] =  {9, 6, 5, 1, 7};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "max sum is "
         << max_coin(coins, 0, 4) << " " << sum(coins) <<
	<< endl;
    return 0;
}
