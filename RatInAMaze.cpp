#include<iostream>
using namespace std;

void printPathHelper(int **arr, int n, int **solution, int x, int y){

    if(x == n-1 && y== n-1){
        solution[x][y] = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return ;
    }

    if(x < 0 || y <0 || x >=n || y >= n || arr[x][y] == 0 || solution[x][y] == 1){
        return ;
    }
    solution[x][y] = 1;

    printPathHelper(arr, n, solution, x-1, y);
    printPathHelper(arr, n, solution, x+1, y);
    printPathHelper(arr, n, solution, x, y-1);
    printPathHelper(arr, n, solution, x, y+1);

    solution[x][y] = 0;
    return ;


}

bool hasPath(int **arr, int n){

    int **solution;
    solution = new int *[n];
    for(int i=0; i<n; i++){
        solution[i] = new int[n];
        for(int j=0; j<n ;j++){
            solution[i][j] = 0;
        }
    }

    printPathHelper(arr,n,solution,0,0);
    return true;

}

int main(){
    int n;
    cin >> n;
    int **arr;
    arr = new int *[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n ;j++){
            cin >> arr[i][j];
        }

    }

    cout << hasPath(arr,n) <<endl;

}
