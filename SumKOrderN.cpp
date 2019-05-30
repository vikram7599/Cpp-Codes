#include <iostream>
#include<unordered_map>
using namespace std;

int countPairs(int *arr, int n, int k){
    unordered_map<int, int> omap;

    int i, twice_count =0 ;

    for(i=0; i<n; i++){
        omap[arr[i]]++;
    }

    for(i=0; i<n; i++){

        twice_count += omap[k-arr[i]];

        if(k-arr[i] == arr[i]){
            twice_count--;
        }
    }

    return (twice_count/2);

}

int main() {
	//code

	int t;
	cin >> t;
	while(t--){

	    int n, k;
	    cin >> n >> k;

	    int arr[n];
	    int i;
	    for(i=0; i<n; i++){
	        cin >> arr[i];
	    }

	    int ans = countPairs(arr,n, k);
	    cout << ans <<endl;
	}
	return 0;
}
