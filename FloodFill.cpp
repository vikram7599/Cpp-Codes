#include <iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &v, int row, int col, int m, int n, int color, int k){
    if(v[row][col] != color){
        return ;
    }

    v[row][col] = k;


    if(col-1 >=0){
        helper(v,row,col-1,m,n,color,k);
    }
    if(col+1 < m){
        helper(v,row,col+1,m,n,color,k);
    }
    if(row-1 >= 0){
        helper(v,row-1, col,m,n,color,k);
    }
    if(row+1 < n){
        helper(v,row+1,col,m,n,color,k);
    }
    return ;

}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    vector<vector<int>> v;
	    int j,i;
	    for(i =0; i < n; i++){
	        vector<int> temp;

	        for(j=0; j<m ;j++){
	            int tempv ;
	            cin >> tempv;
	            temp.push_back(tempv);
	        }
	        v.push_back(temp);
	    }

	    int x , y, k;
	    cin >> x >> y >> k;
	    int color = v[x][y];

	    helper(v,x,y, m,n, color,k);

	    for(i=0; i< n; i++){
	        for(j=0; j<m; j++){
	            cout << v[i][j] << " ";
	        }
	    }
	    cout << endl;

	}

	return 0;
}
