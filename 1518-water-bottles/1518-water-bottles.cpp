class Solution {
public:
	int numWaterBottles(int nbs, int neb) {
		long long sum=nbs;
		while(nbs/neb>0)
		{
			sum+=nbs/neb;
			int r=nbs%neb;
			nbs=nbs/neb;
			nbs=nbs+r;
		}
		return sum;
	}
};