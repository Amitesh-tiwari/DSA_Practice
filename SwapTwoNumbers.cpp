roblem statement
You are given two numbers 'a' and 'b' as input.

You must swap the values of 'a' and 'b'.

For Example:
Input: 
'a' = 8, 'b' = 5

//code

void swapNumber(int &a, int &b) {

	a = a+b;
	b = a-b;
	a = a-b;

}