class Solution 
{
public:
	string countAndSay(int n) 
	{ 
		string ret = "";
		if(n <=0 )
			return ret;
		if(n == 1)
			return "1";
		string lastResult = "1";
		for(int i = 1; i < n; i++)
		{
			int cnt = 1;
			string result;
				for(int j = 1; j < lastResult.size(); j++)
				{
					if(lastResult[j] == lastResult[j - 1])
						cnt ++;
					else
					{
						result.push_back(cnt + '0');
						result.push_back(lastResult[j - 1]);
						cnt = 1;
					}	
				}
			result.push_back(cnt + '0');
			result.push_back(lastResult[lastResult.size() - 1]);
			lastResult = result;
		}
		return lastResult;

    }
};
