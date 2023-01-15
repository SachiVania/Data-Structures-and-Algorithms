// time complexity = O(n)
// space complexity = O(1)

#include <iostream>
using namespace std;

pair<int, int> find_max_and_min_element (int arr[], int size) {
    int max, min;
    max = min = arr[0];

    for (int i=1 ; i < size ; i++) {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)    
            min = arr[i];
    }

    pair <int, int> result;

    result.first = max;
    result.second = min;
    
    return result;
}

void printArray(int arr[], int size) {
    for (int i=0 ; i < size ; i++)
        cout << arr[i] << " ";
    cout << endl;    
}

int main() {

    int arr[] = {8, 9, 5, -1, 0, 36, -99};
	int size = sizeof(arr)/sizeof(arr[0]);	
	
	cout << "The given array is : ";
	printArray(arr, size);	

	pair<int, int> result = find_max_and_min_element(arr, size);
	cout << "The maximum element in the array is : " << result.first << endl;
	cout << "The minimum element in the array is : " << result.second << endl;

    return 0;
}