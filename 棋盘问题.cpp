#include <iostream>
#include <cstring>
using namespace std;
int board[10][10]={};
int place[10]={};
int n, k;
int ans = 0;


void solve(int row, int num){
    if(num==0){
        ans++;
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=row; j<n; j++){
            if(board[j][i] == 0 && place[i] == 0){
                place[i] = 1;
                solve(j+1, num-1);
                place[i] = 0;
            }
        }
    }

    return;
}
 



int main(){
    while(cin >> n >> k, n!=-1){
        cin.ignore();
        memset(board, 0, sizeof(board));
        memset(place, 0, sizeof(place));
        ans = 0;

        for(int i=0; i<n; i++){
            string x;
            cin >> x;
            for(int j=0; j<n; j++){
                if(x[j] == '.'){
                    board[i][j]=1;
                }
            }
        }


        solve(0,k);
        cout << ans << endl;


    }


    return 0;
}

void test(){
}
