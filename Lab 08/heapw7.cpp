#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int max = root;   
   int leftRo = 2*root + 1;  // left child node
   int rightRo = 2*root + 2;  // right child node
 
   // if left child is larger than root
   if (leftRo < n && arr[leftRo] > arr[max]){
      max = leftRo;
   }
   
   // if right child is larger than largest  
   if (rightRo < n && arr[rightRo] > arr[max]){
       max = rightRo;
   }
   
    
   if (max != root) {
      swap(arr[root], arr[max]);
 
      // recursively heapify the affected sub-tree
      heapify(arr, n, max);
   }
  
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
   // extracting elements from heap one by one
   for (int i=n-1; i>=0; i--) {
      
      swap(arr[0], arr[i]);
  
     
      heapify(arr, i, 0);
   }
  
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   cout<<"Enter array size :- "<<endl;
   int n ;
   cin>> n;
   int heap_arr[n] ;
   for (int i=0; i< n ; i++){
       
       int elem;
       cin>> elem;
       heap_arr[i]=elem;
   }
   
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}