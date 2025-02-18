#include <stdio.h>
float calculateBill(char* ward , int* days);
 
int main() {
      int days;
      char name[20],ward;
      printf("Enter Patient Name : ");
      scanf("%s",name);
      printf("Enter Ward Type(G/S/P) : ");
      scanf("%c",&ward);
      printf("Enter Number of Days : ");
      scanf("%d", &days);
      printf("Patient Name : %s ", name);
      float calculateBill(ward,days);
    return 0;
}

float calculateBill(char ward , int days){
    int charge , discount;
    if (days<= 7){
        if (ward == 'G'){
            charge = 1000*days;
        }else if (ward == 'S'){
            charge = 2000*days;
        }else if (ward == 'P'){
            charge = 5000*days;   
        }else{
            printf("Invalid input")
        }print("Total Bill Before Discount : %d", charge);
    }else if(days>7){
        if(ward == 'G'){
          discount = 1000*days*(5/100);  
        }else if (ward == 'S'){
            discount = 2000*days*(5/100);
        }else if (ward == 'P'){
            discount = 5000*days*(5/100);   
        }print("Discount : %d", discount);
    }
    print("Final Bill Amount : %d ", charge-discount);
    }
