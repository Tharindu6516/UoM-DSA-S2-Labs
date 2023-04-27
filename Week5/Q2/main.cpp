#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;

void insertIntoSortedArray(vector<int>& arr, int element) {
    int i = 0;
    while (i < arr.size() && arr[i] < element) {
        i++;
    }
    arr.insert(arr.begin() + i, element);
}

bool stringIsInt(string s) {
    for (int i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i])) continue;
        if (i == 0 && s[i]=='-') continue;
        return false;
    }
    return true;
}

void print_arr(vector<int> arr) {
    cout << "{";
    for (int i = 0; i < arr.size()-1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[arr.size()-1] << "}";
}

int main() {

    vector<int> arr = {};
    string input = "";

    cout << "Enter integers one by one. Enter \"end\" to stop stream.\n\n";

    while (true)
    {
        cout << ">";
        cin >> input;
        if (input == "end") break;
        if (!stringIsInt(input)) throw invalid_argument("Integer value expected. Enter end to stop stream.");

        stringstream ss;
        int next;
        ss << input;
        ss >> next;

        insertIntoSortedArray(arr, next);

        float median = (arr[(arr.size() - 1) / 2] + arr[arr.size() / 2]) / 2.0;

        cout << "Array: ";
        print_arr(arr);    
        cout << "     | Median: " << median << endl << endl;    
        
    }

    return 0;
}