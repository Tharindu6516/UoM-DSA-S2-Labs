#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

  
// function to heapify the tree
void heapify(vector<int>& arr, int n, int root)
{
   // build heapify

   int max = root;
   int l = 2 * root + 1;
   int r = 2 * root + 2;

   if (l < n && arr[l] > arr[max]) max = l;
   if (r < n && arr[r] > arr[max]) max = r;

   if (max == root) return;

   swap(arr[root], arr[max]);
   heapify(arr, n, max);  
   
}
  
// implementing heap sort
void heapSort(vector<int>& arr, int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
   
  
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
   }   
}
  
/* print contents of array */
void displayArray(vector<int> arr)
{
   for (int i : arr)
   cout << i << " ";
   cout << "\n";
}
  
// main program
int main()
{
   string line;
   getline(cin, line);

   // extract integers from the string using a stringstream
   vector<int> arr;
   stringstream ss(line);
   int num;
   while (ss >> num) {
      arr.push_back(num);
   }

   
   int n = arr.size();
   cout<<"Input array:"<<endl;
   displayArray(arr);
  
   heapSort(arr, n);
  
   cout << "Sorted array:"<<endl;
   displayArray(arr);

   return 0;
}