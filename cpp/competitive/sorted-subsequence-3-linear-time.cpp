/* 08 April 2017 -- RC

Find a sorted subsequence of size 3 in linear time*

Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time. If there are multiple such triplets, then print any one of them.

Examples:

Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
Output: 5, 6, 30

Input:  arr[] = {1, 2, 3, 4}
Output: 1, 2, 3 OR 1, 2, 4 OR 2, 3, 4

Input:  arr[] = {4, 3, 2, 1}
Output: No such triplet

*/

#include <iostream>
#include <climits>
#include <cstdio>

using namespace std;

void print_subsequence(int arr[], int n) {
	int i=0, j=INT_MIN, k=INT_MIN;
	bool flag = false;

	for (int var = 1; var < n; ++var) {
		if(j == INT_MIN) {
			if(arr[var] > arr[i])
				j = var;
			else
				i = var;
		}
		else if(j!=INT_MIN && k == INT_MIN) {
			if(arr[var] > arr[j]) {
				k = var;
				flag = true;
				break;
			}
			else
				continue;
		}
	}

	if(flag)
		printf("%d %d %d\n", arr[i], arr[j], arr[k]);
	else
		cout<<"No triplet"<<endl;
}

int main() {
	int arr[] = {12, 11, 10, 5, 6, 2, 30};

	print_subsequence(arr, sizeof(arr)/sizeof(int));

	return 0;
}
