#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

struct Algorythm
{
    string name;
    void (*algorythem)(int[], int, int);
};

void print_arr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int** generate_arrays(int N, int array_lengths[], unsigned int random_seed) {
    srand(random_seed);
    int** arrays = new int* [N];
    for (int i = 0; i < N; i++) {
        int length = array_lengths[i];
        int* array = new int[length];
        for (int j = 0; j < length; j++) {
            array[j] = rand() % 10000001;
        }
        arrays[i] = array;
    }
    return arrays;
}

float time_algorithm( Algorythm sorting_algorythm, int** arrays, int N, int array_lengths[]) {
    
    cout << sorting_algorythm.name << endl;
    for (int i = 0; i < N; i++) {
        int length = array_lengths[i];

        #ifdef PRINT_ARRAYS
            print_arr(arrays[i], length);
        #endif

        auto start = chrono::high_resolution_clock::now();
        sorting_algorythm.algorythem(arrays[i], 0, length-1);
        auto finish = chrono::high_resolution_clock::now();

        #ifdef PRINT_ARRAYS
            print_arr(arrays[i], length);
        #endif
        cout << chrono::duration_cast<chrono::microseconds>(finish - start).count()/1000.0 << endl;
        
    }
    cout << endl;
}