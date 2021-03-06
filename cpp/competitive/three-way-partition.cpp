/* 8 April 2018 -- RC

Three way partitioning of an array around a given range

Given an array and a range [lowVal, highVal], partition the array around the range such that array is divided in three parts.
1) All elements smaller than lowVal come first.
2) All elements in range lowVal to highVVal come next.
3) All elements greater than highVVal appear in the end.
The individual elements of three sets can appear in any order.

Examples:

Input: arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}  
        lowVal = 14, highVal = 20
Output: arr[] = {1, 5, 4, 2, 1, 3, 14, 20, 20, 98, 87, 32, 54}

Input: arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}  
       lowVal = 20, highVal = 20       
Output: arr[] = {1, 14, 5, 4, 2, 1, 3, 20, 20, 98, 87, 32, 54} 

*/

#include <iostream>
#include <algorithm>

using namespace std;

void threewaypartition(int arr[], int n, int low, int high) {
	int start = 0, end = n-1;

	for (int i = 0; i < end;) {
		if(arr[i] < low)
			swap(arr[i++], arr[start++]);

		else if(arr[i] > high)
			swap(arr[i], arr[end--]);
		
		else
			i++;
	}
}


int main() {
	int arr[] = {5,10,30,12,4};

	threewaypartition(arr, sizeof(arr)/sizeof(int), 10, 12);

	for(int& i:arr){
		cout<<i<<" ";
	}

	cout<<endl;
}
