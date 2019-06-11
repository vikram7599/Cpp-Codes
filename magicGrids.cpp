#include <bits/stdc++.h>
using namespace std;

int main()
{
    //
    int t;
    cin >> t;
    while(t--){
        int r,c;
        cin >> r >> c;
        int **arr= new int*[r];
        int **dp = new int*[r];
        for(int i=0; i<r; i++){
            dp[i] = new int[c];
            arr[i] = new int[c];
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> arr[i][j];
            }
        }

        dp[r-1][c-1] = 1;
        dp[r-2][c-1] = 1;
        dp[r-1][c-2] = 1;

        for(int i = r-3; i>=0; i--){
            dp[i][c-1] = dp[i+1][c-1] - arr[i+1][c-1];
            if(dp[i][c-1] <= 0){
                dp[i][c-1] = 1;
            }
        }

        for(int i = c-3; i>=0; i--){
            dp[r-1][i] = dp[r-1][i+1] - arr[r-1][i+1];
            if(dp[r-1][i] <= 0){
                dp[r-1][i] = 1;
            }
        }

        for(int i= r-2; i>=0 ; i--){

            for(int j= c-2; j>=0; j--){
                dp[i][j] = min(dp[i+1][j] - arr[i+1][j] , dp[i][j+1] - arr[i][j+1]);
                if(dp[i][j] <=0){
                    dp[i][j] = 1;
                }
            }

        }
        cout << dp[0][0] <<endl;

        for(int i=0; i<r; i++){
            delete [] arr[i];
            delete [] dp[i];
        }
        delete [] dp;
        delete [] arr;

    }
}
