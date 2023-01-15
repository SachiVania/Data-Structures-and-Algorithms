/*

FIND A UNIQUE ELEMENT IN AN ARRAY. EACH ELEMENT IS REPEATED EXACTLY TWICE EXCEPT FOR 1 ELEMENT.

// So total size will be 2n+1, always odd
// each element is repeated so elem ^ elem = 0
// 1 3 2 9 2 1 9 -> 1^ 3^ 2^ 9^ 2^ 1^ 9 can be seen as 
// 1^1^3^2^2^9^9 -> so 0^3^0^0 -> so 3
// works for sorted and unsorted both. Works only if only 1 element is unique and others are exactly 2

*/

// time complexity = O(n)
// space complexity = O(1)

#include <iostream>
using namespace std;

int find_unique_element (int arr[], int size) {
    int result = arr[0];

    for (int i = 1; i < size ; i++) {
        result = result ^ arr[i];
    }
    return result;
}

void printArray(int arr[], int size) {
    for (int i=0 ; i < size ; i++)
        cout << arr[i] << " ";
    cout << endl;    
}

int main(){
    int arr[] = {1, 8, 32, 1, 8};
	int size = sizeof(arr)/sizeof(arr[0]);	
	
	cout << "The given array is : ";
	printArray(arr, size);	

	cout << "The unique element in the array is : " << find_unique_element (arr, size) << endl;
    return 0;
}