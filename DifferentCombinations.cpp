#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;



void printCombinations(int arr[], vector<int> v, int currSum, int n, int sumv , int index, map<vector<int>, int> &omap , bool &tog){
    if( (currSum) == sumv){
    if(tog == 0){
        tog = 1;
    }
        if(omap.count(v) == 0){
        cout << "(";
            for(int i=0; i< v.size()-1; i++){
                cout << v[i] << " ";
            }

            cout << v[v.size()-1] << ")";
            omap[v] = 1;
        }

        return ;
    }

    if(index == n){
        return;
    }

    int val = arr[index];
    while(val + currSum <= sumv){
        vector<int> tempVector = v;
        tempVector.push_back(arr[index]);


        printCombinations(arr, tempVector, val+ currSum, n,sumv, index+1, omap, tog);
        index++;
        val = arr[index];
    }



    return ;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    int i,j;
	    for(i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    int sumv ;
	    cin >> sumv;

	    sort(arr, arr+n);
	    vector<int> v;
	    map<vector<int>, int> omap;
	    bool tog = 0 ;

	    printCombinations(arr, v, 0 , n, sumv,0 , omap , tog);

	    if(tog == 0){
            cout << "Empty" ;
	    }
	    cout << endl;
	}
	return 0;
}
