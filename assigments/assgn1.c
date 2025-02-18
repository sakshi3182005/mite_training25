//Loan Eligibilty Checker 

#include<stdio.h>
void readDetails(float* p_salary , int *p_score , int *p_exp){
    printf("Enter Salary : ");
    scanf("%f",p_salary);

    printf("Enter Credit Score : ");
    scanf("%d",p_score);

    printf("Enter Experience : ");
    scanf("%d",p_exp);
}

int isEligible(float salary, int score , int exp){
    return(salary>=30000 && score >= 750 && exp >= 2);
}
int main(){
    float salary;
    int score;
    int exp;
    readDetails(&salary,&score,&exp);
    if(isEligible(salary,score,exp)){
        printf("Loan Approved");
    } else{
        printf("Loan Rejected");
    }
    return 0;
}
