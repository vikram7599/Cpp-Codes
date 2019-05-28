#include <iostream>
using namespace std;

int numberOfPaths(int m, int n){
    if(n == 1 || m == 1){
        return 1;
    }

    return (numberOfPaths(m-1,n) + numberOfPaths(m,n-1));
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int m,n;
	    cin >> m >> n;
	    int ans = numberOfPaths(m,n);
	    cout << ans <<endl;
	}
	return 0;
}
