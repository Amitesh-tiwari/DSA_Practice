Problem statement
You have been given an array/list 'ARR' consisting of 'N' integers.
 Your task is to find the majority element in the array. 
 If there is no majority element present, print -1.

Note:
A majority element is an element that occurs more than floor('N' / 2) times in the array.



//code

int majorityElement = -1;
	int count = 0;

	for(int i=0;i<n;i++){
		if(count == 0){
			majorityElement = arr[i];
			count = 1;
			continue;
		}

		if(arr[i] == majorityElement){
			count++;
		}
		else{
			count--;
		}
	}
	count = 0;

	for(int i=0;i<n;i++){
		if(arr[i] == majorityElement){
			count++;
		}
	}

	if(count > n/2){
		return majorityElement;
	}

	return -1;