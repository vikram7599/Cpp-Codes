#include <iostream>
#include<unordered_map>
using namespace std;

void fibFill(int fibArra[]){

    for(int i=2; i<101; i++){
        fibArra[i] = fibArra[i-1] + fibArra[i-2];
    }
    return ;
}

int main() {
	//code
	int fibArra[101] ;
	fibArra[0] = 0;
	fibArra[1] = 1;
	fibFill(fibArra);

	unordered_map<int, int> omap;
	for(int i=0; i<101; i++)
	omap[fibArra[i]] = 1;

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

	    for(i=0; i<n; i++){
	        if(omap.count(arr[i]) > 0){
	            cout << arr[i] <<" ";
	        }
	    }
	    cout << endl;
	}

	return 0;
}
