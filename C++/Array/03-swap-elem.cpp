// time complexity = O(n)
// space complexity = O(1)

#include <iostream>
using namespace std;

long long int swap_alternate_elements (int arr[], int size) {
    int temp;

    for (int i = 0, j = size-1 ; i < j ; i+=2, j-=2) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i=0 ; i < size ; i++)
        cout << arr[i] << " ";
    cout << endl;    
}

int main(){
    int arr[] = {8, 9, 5, 1, 0, 36, 99};
	int size = sizeof(arr)/sizeof(arr[0]);	
	
	cout << "The given array is : ";
	printArray(arr, size);	

    swap_alternate_elements (arr, size);

	cout << "After swapping the alternate elements, the array is : " ;
	printArray(arr, size);	
 
    return 0;
}