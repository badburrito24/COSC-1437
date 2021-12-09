#include <iostream>

using namespace std;

double average(int arr[], int n){
      int sum = 0;
      for(int i = 0; i < n; i++){
         sum += arr[i];
      }
      return (double)sum / (double)n;
   }
int main(){
   
   int n;
   cin >> n;
   
   int *arr;
   arr = new int[n];
   
   for(int i = 0; i < n; i++){
      cin >> arr[i];
   }
   cout << average(arr, n);

   delete [] arr;
   
   
   //Write your solution here   
   
}