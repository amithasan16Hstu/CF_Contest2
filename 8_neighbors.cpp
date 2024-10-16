#include <bits/stdc++.h>

using namespace std;
bool checkNeighbors(const vector<vector<char>> &A, int N, int M, int X, int Y) {
   
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

   
    for (int i = 0; i < 8; ++i) {
        int nx = X + dx[i];
        int ny = Y + dy[i];
        
        
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (A[nx][ny] != 'x') {
                return false;
            }
        }
    }
    return true; 
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<char>> A(N, vector<char>(M));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    
    int X, Y;
    cin >> X >> Y;
    
    
    X--; Y--;
    
    
    if (checkNeighbors(A, N, M, X, Y)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}
