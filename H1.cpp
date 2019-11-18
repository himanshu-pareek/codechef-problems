#include <iostream>
using namespace std;

#define N (3)
#define STATES (181440)
#define M (98765432)

int matrix[N * N];
int queue[STATES];
int ans[M] = {0};
int front, rear;
int new_index, current_index;

int powers[] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
bool check_prime[] = {0, 1, 2, 3, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0};

void swap (int i, int j) {
    int diff = matrix[j] - matrix[i];
    new_index = current_index + diff * powers[i] - diff * powers[j];
    if (!ans[new_index/10]) {
        ans[new_index/10] = ans[current_index/10] + 1;
        queue[rear++] = new_index;
    }
}

void initialize () {
    front = 0;
    while (front < rear) {
        current_index = queue[front];
        int local_index = current_index;
        for (int i = 8; i >= 0; i--) {
            matrix[i] = local_index % 10;
            local_index /= 10;
        }
        if (check_prime[matrix[0] + matrix[1]]) {
            swap (0, 1);
        }
        if (check_prime[matrix[0] + matrix[3]]) {
            swap (0, 3);
        }
        if (check_prime[matrix[1] + matrix[2]]) {
            swap (1, 2);
        }
        if (check_prime[matrix[1] + matrix[4]]) {
            swap (1, 4);
        }
        if (check_prime[matrix[2] + matrix[5]]) {
            swap (2, 5);
        }
        if (check_prime[matrix[3] + matrix[4]]) {
            swap (3, 4);
        }
        if (check_prime[matrix[3] + matrix[6]]) {
            swap (3, 6);
        }
        if (check_prime[matrix[4] + matrix[5]]) {
            swap (4, 5);
        }
        if (check_prime[matrix[4] + matrix[7]]) {
            swap (4, 7);
        }
        if (check_prime[matrix[5] + matrix[8]]) {
            swap (5, 8);
        }
        if (check_prime[matrix[6] + matrix[7]]) {
            swap (6, 7);
        }
        if (check_prime[matrix[7] + matrix[8]]) {
            swap (7, 8);
        }

        front++;
    }
}

int main() {
    rear = 0;
    ans[12345678] = 1;
    queue[rear] = 123456789;
    rear++;
    initialize();
    int t;
    cin >> t;
    while (t--) {
        int index = 0;
        int x;
        for (int i = 0; i < N*N; i++) {
            cin >> x;
            index = (index << 3) + (index << 1) + x;
        }
        cout << (ans[index / 10] - 1) << endl;
    }
    return 0;
}