#include <iostream>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arrv[n] , arr2[n];
	    int i;
	    for(i=0; i<n; i++){
	        cin >> arrv[i];
	        arr2[i] = arrv[i];
	    }

        sort(arr2,arr2+n);
        unordered_map<int, int> omap;

        for(i=0; i<n; i++){
            omap[arr2[i]] = i;
        }



	    for(i=0; i<n; i++){
	        cout << omap[arrv[i]] <<" ";
	    }
	    cout << endl;

	}
	return 0;
}
