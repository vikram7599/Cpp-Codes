#include<iostream>
using namespace std;


void RotateMatrix(int arr[][10], int n){

    for(int x=0; x< n/2; x++){

        for(int y=x; y <n-1-x; y++){
            int temp = arr[x][y];

            //From Left to Top
            arr[x][y] = arr[n-1-y][x];

            //From bottom to left
            arr[n-1-y][x] = arr[n-1-x][n-1-y];

            //From Right to bottom

            arr[n-1-x][n-1-y] = arr[y][n-1-x];

            //From temp to Right;

            arr[y][n-1-x] = temp;

        }
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
	    int arr[10][10];
	    int i, j ;
	    for(i=0; i<n; i++){
	        for(j=0; j<n; j++){
	            cin >> arr[i][j];
	        }
	    }

	    RotateMatrix(arr,n);

	    for(i=0; i<n; i++){
	        for(j=0; j<n; j++){
	            cout << arr[i][j] <<" ";
	        }
	    }
	    cout << endl;

	}
	return 0;
}
