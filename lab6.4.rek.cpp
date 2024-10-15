#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Create(double* a, const int n, const double Low, const double High) {
    if (n == 0) return;
    a[0] = Low + rand() * (High - Low) / RAND_MAX;
    Create(a + 1, n - 1, Low, High);
}

void Print(double* a, const int n) {
    if (n == 0) {
        cout << endl;
        return;
    }
    cout << setw(10) << a[0];
    Print(a + 1, n - 1);
}


int CountGreaterThanC(double* a, const int n, const double C) {
    if (n == 0) return 0;
    return (a[0] > C) + CountGreaterThanC(a + 1, n - 1, C);
}


double ProductAfterMax(double* a, const int n) {
    static int maxIndex = 0;

    if (n == 1) return 1;

    if (fabs(a[n - 1]) > fabs(a[maxIndex])) {
        maxIndex = n - 1;
    }

    if (n - 1 == maxIndex) return 1;

    return a[n - 1] * ProductAfterMax(a, n - 1);
}


void RearrangeArray(double* a, const int n, double* temp = nullptr, int negIndex = 0, int posIndex = 0) {
    if (temp == nullptr) {
        temp = new double[n];
    }

    if (n == 0) {
        for (int i = 0; i < negIndex + posIndex; i++) {
            a[i] = temp[i];
        }
        delete[] temp;
        return;
    }

    if (a[0] < 0) {
        temp[negIndex++] = a[0];
    }
    else {
        temp[negIndex + posIndex++] = a[0];
    }

    RearrangeArray(a + 1, n - 1, temp, negIndex, posIndex);
}

int main() {
    srand((unsigned)time(NULL));

    int n;
    cout << "Vvedit (n): ";
    cin >> n;

    double C;
    cout << "Vvedit C: ";
    cin >> C;

    auto* a = new double[n];

    double Low = -10.0;
    double High = 10.0;

    Create(a, n, Low, High);
    Print(a, n);

    
    int count = CountGreaterThanC(a, n, C);
    cout << "Count elem >  C: " << count << endl;

    
    double product = ProductAfterMax(a, n);
    cout << "Dobutok pislya maxymalnogo za modulem: " << product << endl;

   
    RearrangeArray(a, n);
    cout << "Modified mas: ";
    Print(a, n);

    delete[] a;
    return 0;
}
