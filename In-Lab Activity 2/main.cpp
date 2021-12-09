#include <iostream>

using namespace std;

int main() {
	
   int n;
   bool isPrime;
   cin >> n;
   for(int prime = 2; prime <= n; prime++)
   {
      isPrime = true;

      for(int j = 2; j < prime; j++)
      {
         if(prime % j == 0)
         {
               isPrime = false;
         }
      }
         if(isPrime)
            cout << prime << " ";
   }

   return 0;
}