#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    int arr[] = {7, 3, 1, 0, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Measure execution time
    auto start = high_resolution_clock::now();
    selectionSort(arr, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    // Measure space complexity
    int space = sizeof(arr) + sizeof(n);
    cout << "Space complexity: " << space << " bytes" << endl;

    return 0;
}

/*Waktu: Dalam kasus terburuk, Selection Sort memiliki kompleksitas waktu O(n^2). Pada setiap iterasi, elemen terkecil dipilih dari sisa array yang belum diurutkan dan ditukar dengan elemen pertama yang belum diurutkan. Dalam kasus terburuk, di mana array dalam keadaan terbalik, setiap elemen perlu dipertukarkan dengan elemen yang belum diurutkan, menghasilkan n-1 perulangan dalam iterasi pertama, n-2 perulangan dalam iterasi kedua, dan seterusnya, memberikan total n(n-1)/2 perulangan.
Ruang: Selection Sort menggunakan jumlah ruang konstan, yaitu O(1), karena hanya ada penggunaan variabel tambahan dan tidak ada alokasi memori tambahan yang bergantung pada ukuran input.
Jadi Selection Sort memiliki kompleksitas waktu yang tetap, tidak peduli apakah array sudah terurut atau tidak. Oleh karena itu, metode pengurutan ini lebih cocok digunakan untuk jumlah data yang kecil atau ketika perpindahan data menjadi faktor yang penting. Namun, untuk jumlah data yang besar, metode pengurutan lain seperti Quick Sort atau Merge Sort yang memiliki kompleksitas waktu lebih baik seperti O(nlogn) biasanya lebih disukai.
*/
