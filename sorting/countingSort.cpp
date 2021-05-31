// C++ Program for counting sort
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255

// The main function that sort
// the given string arr[] in
// alphabatical order
void countSort(int arr[])
{
	// The output intacter array
	// that will have sorted arr
	int output[strlen(arr)];

	// Create a count array to store count of inidividul
	// intacters and initialize count array as 0
	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count));

	// Store count of each intacter
	for (i = 0; arr[i]; ++i)
		++count[arr[i]];

	// Change count[i] so that count[i] now contains actual
	// position of this intacter in output array
	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i - 1];

	// Build the output intacter array
	for (i = 0; arr[i]; ++i) {
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

	/* 
	For Stable algorithm 
	for (i = sizeof(arr)-1; i>=0; --i) 
	{ 
		output[count[arr[i]]-1] = arr[i]; 
		--count[arr[i]]; 
	} 
	
	For Logic : See implementation 
	*/

	// Copy the output array to arr, so that arr now
	// contains sorted intacters
	for (i = 0; arr[i]; ++i)
		arr[i] = output[i];
}

// Driver code
int main()
{
	int arr[] = {1,2,3,4,5,5,6,6,7,7,3,4,3,4,2,4,5,3,45,12,1,4,3};

	countSort(arr);

	cout << "Sorted intacter array is " ;
    for(int i : arr)
        cout << i << ' ';
    cout << endl;
	return 0;
}

// This code is contributed by rathbhupendra
