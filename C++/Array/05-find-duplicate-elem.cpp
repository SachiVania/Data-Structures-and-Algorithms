/*
AN ARRAY OF SIZE N IS GIVEN. ARRAY ELEMENTS ARE 1 TO N-1, AT LEASE ONCE. AND ONLY ONE ELEMENT IS REPEATED. FIND THAT ELEMENT.

// The repeated number is from 1 to N-1 only
// 1 2 3 4 4 so (sum of all elements) - (sum of 1 to N-1) = that duplicate element
// works for both arrays, either sorted or unsorted

*/

// time complexity = O(n)
// space complexity = O(1)

#include <iostream>
using namespace std;

int find_duplicate_element (int arr[], int size) {
    int expected_sum = 0, actual_sum = 0;

    // for 1 to n, sum = n(n+1)/2
    // so, 
    // for 1 to n-1, sum = (n-1)n/2 -> n(n-1)/2
    expected_sum = (size * (size - 1)) / 2;
    
    for (int i = 0; i < size ; i++) {
        actual_sum = actual_sum + arr[i];
    }
    
    // cout << actual_sum << endl;
    // cout << expected_sum << endl;
    
    return (actual_sum - expected_sum);
}

void printArray(int arr[], int size) {
    for (int i=0 ; i < size ; i++)
        cout << arr[i] << " ";
    cout << endl;    
}

int main(){
    int arr[] = {1, 3, 3, 4, 2};
	int size = sizeof(arr)/sizeof(arr[0]);	
	
	cout << "The given array is : ";
	printArray(arr, size);	

	cout << "The duplicate element in the array is : " << find_duplicate_element (arr, size) << endl;

    return 0;
}