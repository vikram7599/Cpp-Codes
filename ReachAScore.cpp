#include<iostream>
using namespace std;

int helper(int denominations[], int num, int val){

    if(val == 0){
        return 1;
    }

    if(val < 0){
        return 0;
    }

    if(num <1 && val >0){
        return 0;
    }


    return helper(denominations, num-1, val) + helper(denominations, num, val - denominations[num-1]) ;
}


int countWaysToMakeChange(int arr[], int num, int val){


    //int ans = helper(denominations, num, val);

    int **dp = new int*[num];

    for(int i=0; i< num; i++){
        dp[i] = new int[val+1];
    }

    for(int i=0; i< num; i++){
        dp[i][0] = 1;
    }

    for(int j= 1; j <= val; j++){

        for(int i =0; i<num; i++){
            int x = (i >= 1 )? dp[i-1][j] : 0;

            int y = (j - arr[i] >= 0)? dp[i][j- arr[i]] : 0;

            dp[i][j] = x+y;
            //cout << i << " " << j << dp[i][j] <<endl;
        }

    }
    int ans = dp[num-1][val];

    for(int i=0; i< num; i++){
        delete [] dp[i];
    }

    delete [] dp;

    return ans;

}


int main() {
	//code

	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[] = {3,5,10};

	    int ans = countWaysToMakeChange(arr,3,n);
	    cout <<ans <<endl;
	}

	return 0;
}
