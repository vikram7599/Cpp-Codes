#include <iostream>
using namespace std;

int binarySearch(int *arr, int si, int ei){
    if(ei >= si){

        int mid = (si+ei)/2;
        cout << "mid = " << mid <<endl;
        cout << "Si = " <<si << " Ei= " <<ei <<endl;
        if((mid == 0 || arr[mid-1]== 1) && arr[mid] == 0){
            return mid;
        }

        if(arr[mid] == 1){
            return binarySearch(arr, mid+1, ei);
        }
        else{
            return binarySearch(arr, si, mid-1);
        }

    }

    return -1;




}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    int i;
	    for(i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    int index = binarySearch(arr, 0, n-1);

	    if(index == -1){
	        cout << "0" <<endl;
	        continue;
	    }
	    cout << n-index <<endl;

	}
	return 0;
}
