Problem statement
A thief wants to loot houses. 
He knows the amount of money in each house. 
He cannot loot two consecutive houses. 
Find the maximum amount of money he can loot.

//code
int maxMoneyLooted(vector<int> &houses, int n)
{
	if(n ==0 ){
		return 0;
	}

	if(n == 1){
		return houses[0];
	}

	if(n == 2){
		return max(houses[0], houses[1]);
	}

	int curr;
	int prev1 = max(houses[0], houses[1]);
	int prev2 = houses[0];
	for(int i=2;i<n;i++){
		curr = max(prev1,houses[i] + prev2);
		prev2 = prev1;
		prev1 = curr;

	}
	return curr;
}