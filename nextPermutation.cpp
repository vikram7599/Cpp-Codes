#include <iostream>
#include<algorithm>
using namespace std;

void nextPermutations(int *arr , int n){
    int j,i;
    int tog= 1;
    for(i=n-2; i >= 0 ; i--){
        if(arr[i] < arr[i+1]){
            tog = 0;
            break;
        }
    }


    if(tog){
        return ;
    }

    int x = arr[i], smallest = i+1;
    for (j = i+2; j < n; j++)
        if (arr[j] > x && arr[j] < arr[smallest])
            smallest = j;

    int temp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = temp;

    sort(arr+i+1, arr+n);
    return ;

}


int main() {


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

	    nextPermutations(arr,n);

	    for(i=0; i<n ;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;


	}
	return 0;
}
