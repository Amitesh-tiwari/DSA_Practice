You are given a sorted array ‘arr’ of ‘n’ numbers such that 
every number occurred twice in the array except one,which appears only once.

Return the number that appears once.

Example:
Input: 'arr' = [1,1,2,2,4,5,5]

Output: 4

//code

int singleNonDuplicate(vector<int>& arr)
{
	int answer = 0;

	for(int element : arr){
		answer ^= element;
	}
	return answer;
}