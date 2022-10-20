//https://leetcode.com/problems/maximum-units-on-a-truck/
class Solution
{
public:
	int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
	{
		sort(boxTypes.begin(), boxTypes.end(), [](auto &b1, auto &b2)
			 { return b1[1] > b2[1]; });

		int ans = 0;

		for (int i = 0; i < boxTypes.size(); i++)
		{
			if (truckSize > boxTypes[i][0])
			{
				truckSize -= boxTypes[i][0];
				ans += boxTypes[i][0] * boxTypes[i][1];
			}
			else
			{
				ans += truckSize * boxTypes[i][1];
				return ans;
			}
		}
		return ans;
	}
};