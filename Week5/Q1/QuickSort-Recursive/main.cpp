// #define PRINT_ARRAYS
#include "helpers.cpp"

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low = 0, int high = -1) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int main() {
    const int number_of_arrays = 21;
    int array_lengths[number_of_arrays] = { 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000, 110000, 120000, 130000, 140000, 150000, 160000, 170000, 180000, 190000, 200000 };
    const Algorythm SortingAlgorythem = {"Quick Sort", &quicksort};
    unsigned int random_seed = time(NULL);

    int** arrays = generate_arrays(number_of_arrays, array_lengths, random_seed);
    time_algorithm(SortingAlgorythem, arrays, number_of_arrays, array_lengths);
}