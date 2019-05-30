#include <iostream>
#include<queue>
using namespace std;

void negInteger(int *arr , int n, int k){

    queue<int> Di;

    int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push(i);

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; i++)
    {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!Di.empty())
            cout << arr[Di.front()] << " ";

        // else the window does not have a
        // negative integer
        else
            cout << "0" << " ";

        // Remove the elements which are out of this window
        while ( (!Di.empty()) && Di.front() < (i - k + 1))
            Di.pop();  // Remove from front of queue

        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push(i);
    }

    // Print the first negative
    // integer of last window
    if (!Di.empty())
           cout << arr[Di.front()] << " ";
    else
        cout << "0" << " ";


}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int *arr = new int[n];
	    int i;
	    for(i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    int k;
	    cin >> k;

	    negInteger(arr, n,  k);
	    cout << endl;

	}
	return 0;
}
