//IMP Question

Given that integers are read from a data stream. 
Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list. 
If the size of the list is even there is no middle value. 
So the median is the floor of the average of the two middle values.

For example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.


//code

vector<int> findMedian(vector<int> &arr, int n){
	
	vector<int> medians;
	priority_queue<int> lo;
	priority_queue <int,vector<int>, greater<int> > hi;

	for(int i=0;i<n;i++){
		int num = arr[i];
		lo.push(num);

		hi.push(lo.top());
		lo.pop();

		if(lo.size() < hi.size()){
			lo.push(hi.top());
			hi.pop();
		}

		int median;
		if(lo.size() > hi.size()){
			median = lo.top();
		}
		else{
			median = (lo.top() + hi.top())/2;
		}
		medians.push_back(median);
	}
	return medians;
}
