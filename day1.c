#include <stdio.h>
#include <string.h>

int main() {
    char name[30];
    int days ,id ;
    float salary;
    
    printf("Enter employee name : ");
    scanf("%s",name);
    
    printf("Enter the employee ID : ");
    scanf("%d",&id);
    
    printf("Enter the salary : ");
    scanf("%f",&salary);
    
    printf("Enter the number of days worked : ");
    scanf("%d",&days);
    
    //process payroll
    float bonus = 0.0f;
    float gross_salary = 0.0f;
    char category[50] = "Good";

    //Calculate bonus
    if(days>25){
        bonus = (salary/100.0f)*5.0f;
    }else if(days<10){
        bonus = (-1.0f*((salary/100.0f)*50.0f));
    }

    //final salary
    gross_salary = (salary+bonus);

    //categorise employee
    if (days>25){
        strcpy(category,"Excellent");
    } else if(days<15){
        strcpy(category,"Need Improvement");
    }

    //display payroll details
    printf("ID : %d\n", id);
    printf("Name : %s\n", name);
    printf("Salary : %.2f\n", salary);
    if(bonus>0){
        printf("Bonus: %.2f\n",bonus);
    }
    printf("Final Salary : %.2f\n", gross_salary);
    printf("Employee performance category : %s",category);
    return 0;
}


