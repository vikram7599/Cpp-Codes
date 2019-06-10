#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){

	    int n , m;
	    cin >> n >> m;
	    int **arr= new int*[n];
	    for(int i=0; i<n; i++){
	        arr[i] = new int[m];
	    }

	    for(int i=0; i<m; i++){
	        arr[n-1][i] = 1;
	    }

	    for(int i=0; i<n; i++){
	        arr[i][m-1] = 1;
	    }

	    for(int i=n-2; i>=0; i--){

	        for(int j= m-2; j>=0; j--){
	            arr[i][j] = arr[i][j+1] + arr[i+1][j];
	        }
	    }

	    int ans = arr[0][0];
	    for(int i=0; i<n; i++){
	        delete [] arr[i];
	    }
	    delete [] arr;
	    cout << ans <<endl;
	}
	return 0;
}
