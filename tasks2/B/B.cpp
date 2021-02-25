#include <iostream>
using namespace std;

int check_field(int field) {
    int ans = field;
    if (field != -1) {
        ans++;
    }
    return ans;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    int* mines_coords = new int[2*K];
    int** field = new int*[N];
    for (int i = 0; i < N; i++) {
        field[i] = new int[M];
        for (int j = 0; j < M; j++) {
            field[i][j] = 0;
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> mines_coords[2*i] >> mines_coords[2*i+1];
        field[mines_coords[2*i]-1][mines_coords[2*i+1]-1] = -1;
        int y = mines_coords[2*i]-1;
        int x = mines_coords[2*i+1]-1;
        if (mines_coords[2*i] == 1 && mines_coords[2*i+1] != 1 && mines_coords[2*i+1] != M) {
            field[y][x+1] = check_field(field[y][x+1]);
            field[y][x-1] = check_field(field[y][x-1]);
            field[y+1][x+1] = check_field(field[y+1][x+1]);
            field[y+1][x-1] = check_field(field[y+1][x-1]);
            field[y+1][x] = check_field(field[y+1][x]);
        }
        if (mines_coords[2*i] == N && mines_coords[2*i+1] != 1 && mines_coords[2*i+1] != M) {
            field[y][x+1] = check_field(field[y][x+1]);
            field[y][x-1] = check_field(field[y][x-1]);
            field[y-1][x+1] = check_field(field[y-1][x+1]);
            field[y-1][x-1] = check_field(field[y-1][x-1]);
            field[y-1][x] = check_field(field[y-1][x]);
        }
        if (mines_coords[2*i+1] == 1 && mines_coords[2*i] != 1 && mines_coords[2*i] != N) {
            field[y+1][x+1] = check_field(field[y+1][x+1]);
            field[y-1][x+1] = check_field(field[y-1][x+1]);
            field[y][x+1] = check_field(field[y][x+1]);
            field[y+1][x] = check_field(field[y+1][x]);
            field[y-1][x] = check_field(field[y-1][x]);
        }
        if (mines_coords[2*i+1] == M && mines_coords[2*i] != 1 && mines_coords[2*i] != N) {
            field[y+1][x-1] = check_field(field[y+1][x-1]);
            field[y-1][x-1] = check_field(field[y-1][x-1]);
            field[y][x-1] = check_field(field[y][x-1]);
            field[y+1][x] = check_field(field[y+1][x]);
            field[y-1][x] = check_field(field[y-1][x]);
        }
        if (mines_coords[2*i] == 1 && mines_coords[2*i+1] == 1) {
            field[y+1][x+1] = check_field(field[y+1][x+1]);
            field[y][x+1] = check_field(field[y][x+1]);
            field[y+1][x] = check_field(field[y+1][x]);
        }
        if (mines_coords[2*i] == 1 && mines_coords[2*i+1] == M) {
            field[y][x-1] = check_field(field[y][x-1]);
            field[y+1][x] = check_field(field[y+1][x]);
            field[y+1][x-1] = check_field(field[y+1][x-1]);
        }
        if (mines_coords[2*i] == N && mines_coords[2*i+1] == M) {
            field[y][x-1] = check_field(field[y][x-1]);
            field[y-1][x] = check_field(field[y-1][x]);
            field[y-1][x-1] = check_field(field[y-1][x-1]);
        }
        if (mines_coords[2*i] == N && mines_coords[2*i+1] == 1) {
            field[y][x+1] = check_field(field[y][x+1]);
            field[y-1][x] = check_field(field[y-1][x]);
            field[y-1][x+1] = check_field(field[y-1][x+1]);
        }
        if (mines_coords[2*i] < N && mines_coords[2*i+1] > 1 && mines_coords[2*i] > 1 && mines_coords[2*i+1] < M) {
            field[y][x+1] = check_field(field[y][x+1]);
            field[y][x-1] = check_field(field[y][x-1]);
            field[y+1][x+1] = check_field(field[y+1][x+1]);
            field[y+1][x-1] = check_field(field[y+1][x-1]);
            field[y+1][x] = check_field(field[y+1][x]);
            field[y-1][x+1] = check_field(field[y-1][x+1]);
            field[y-1][x-1] = check_field(field[y-1][x-1]);
            field[y-1][x] = check_field(field[y-1][x]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < N; i++) {
        delete[] field[i];
    }
    delete[] field;
    return 0;
}
