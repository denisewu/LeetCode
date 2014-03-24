int candy(vector<int> &ratings) {
	int sum = 0;
	vector<int> candies = vector<int>(ratings.size());
	for(int i = 0; i < ratings.size(); i++)
	{
		if(i == 0 || ratings[i] <= ratings[i - 1])
			candies[i] = 1;
		else if(ratings[i] > ratings[i - 1])
			candies[i] = candies[i - 1] + 1;

	}
	for(int i = ratings.size() - 2; i >= 0; i--)
	{
		if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
			candies[i] = candies[i + 1] + 1;
	}
	for(int i = 0; i < ratings.size(); i++)
		sum += candies[i];
	return sum;

}

