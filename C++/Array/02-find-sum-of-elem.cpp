// time complexity = O(n)
// space complexity = O(1)

#include <iostream>
using namespace std;

long long int find_sum_of_all_elements (int arr[], int size) {
    long long int sum = 0;
    // can't take sum as 'int' as all values can be INT_MAX
    // can't take sum as 'unsinged int' as the elements can be negative values

    for (int i=0 ; i < size ; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

long long int find_sum_of_alternate_elements (int arr[], int size) {
    long long int sum = 0;
    // can't take sum as 'int' as all values can be INT_MAX
    // can't take sum as 'unsinged int' as the elements can be negative values

    for (int i=0 ; i < size ; i+=2) {
        sum = sum + arr[i];
    }
    return sum;
}

void printArray(int arr[], int size) {
    for (int i=0 ; i < size ; i++)
        cout << arr[i] << " ";
    cout << endl;    
}

int main(){
    int arr[] = {8, 9, 5, 1, 0, 36, 99};	// edge case : {INT_MAX, INT_MAX, INT_MAX};
	int size = sizeof(arr)/sizeof(arr[0]);	
	
	cout << "The given array is : ";
	printArray(arr, size);	
	
	cout << "The sum of all elements in the array is : " << find_sum_of_all_elements(arr, size) << endl;
	cout << "The sum of alternate elements in the array is : " << find_sum_of_alternate_elements(arr, size) << endl;
	 
    return 0;
}