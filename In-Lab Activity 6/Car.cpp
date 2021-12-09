#include <iostream>
#include <math.h>
#include "Car.h"
using namespace std;

 // Write the implementation of the Destructor
   Car::~Car(){
      delete [] parts;
     // cout << "deconstructor";
   }
 
 // Write the implementation of the Copy Constructor
   Car::Car(const Car& orig){
      modelYear = orig.modelYear;
      purchasePrice = orig.purchasePrice;
      currentValue = orig.currentValue;
      num_parts = orig.num_parts;
      parts = new string[num_parts]; // allocate memory for the new car object\
      
      for (int i = 0; i < num_parts; i++) {
         parts[i] = orig.parts[i];   // assign the empty elements in the new parts array to the elements
                                       // in the original parts array (copying values)
      }
   }
      
      
      
 
// Write the implementation of the copy-assignment operator
   Car& Car::operator =(const Car& RHS){
      if(this != &RHS)
      {
         delete [] parts;
         parts = new string[num_parts];
         for (int i = 0; i < num_parts; i++) {
            parts[i] = RHS.parts[i];
         }
         
      }
   }

//////////////////////////////////////Don't need to change below here!
//set the num_parts and parts
void Car::setParts(int numpart, string new_parts[]){
   num_parts = numpart;
   parts = new string[numpart];
   
   for (int i=0; i < num_parts; i++)
      parts[i] = new_parts[i];
}

int Car::getNumParts() const{
   return num_parts;  
}

string Car::getPart(int index) const{
   return parts[index];  
}

string * Car::getParts() const{
   return parts;  
}

Car::Car(){
   modelYear = 2021;
   purchasePrice = 0;
}

Car::Car(int year, int price){
   modelYear = year;
   purchasePrice = price;
}

void Car::SetModelYear(int userYear){
   modelYear = userYear;
}

int Car::GetModelYear() const {
   return modelYear;
}

void Car::SetPurchasePrice(int userPrice){
   purchasePrice = userPrice;
}

int Car::GetPurchasePrice() const {
   return purchasePrice;
}

void Car::CalcCurrentValue(int currentYear) {
   double depreciationRate = 0.15;
   int carAge = currentYear - modelYear;
      
   // Car depreciation formula
   currentValue = (int) 
      round(purchasePrice * pow((1 - depreciationRate), carAge));
}

void Car::PrintInfo() const {
   cout << "Car's information:" << endl;
   cout << "   Model year: " << modelYear << endl;
   cout << "   Purchase price: " << purchasePrice << endl;
   cout << "   Current value: " << currentValue << endl;
   cout << "   Parts: ";
   for (int i=0; i < num_parts; i++){
      cout << parts[i];
      if (i != num_parts -1)
         cout << ", ";
   }
   cout << endl;
}