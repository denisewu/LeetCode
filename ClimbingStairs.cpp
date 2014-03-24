#include <vector>
using namespace std;

class Solution
{
	int climbStairs(int n)
	{
		if ( n <= 0)
			return 0;

		vector<int> records = vector<int>(n);
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
				records[i] = 1;
			else if (i == 1)
				records[i] = 2;
			else
				records[i] = records[i - 1] + records[i - 2];
		}
		return records[n - 1];		 
		
	}
};
