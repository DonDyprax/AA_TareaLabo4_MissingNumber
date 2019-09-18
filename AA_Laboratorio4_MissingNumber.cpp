#include <iostream>
#include <cstdlib>

using namespace std;

int particionar(int *A, int p, int r) {
    int i, j, x, temp;

    x = A[r];
    i = p - 1;
    for(j = p; j < r; j++) {
        if(A[j] <= x) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    i++;
    temp = A[i];
    A[i] = A[r];
    A[r] = temp;

    return i;
}

void quicksort(int *A, int p, int r) {
    int q;

    if(p < r) {
        q = particionar(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}


int main() {
    int missing, i;
    int A[] = {3,0,2};
    int n = sizeof(A) / sizeof(A[0]);

    quicksort(A, 0, n-1);

    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    cout << endl;

    missing = 2;

    for(i = 0; i < n; i++) {
        if(A[i] >= missing) {
            missing += 2;
        }
    }

    cout << "El numero que falta es: " << missing;


    return 0;
}
