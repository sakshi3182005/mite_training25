//Loan Eligibilty Checker 

#include<stdio.h>
void readDetails(float* p_salary , int *p_score , int *p_expr){
    printf("Enter Salary : ");
    scanf("%f",p_salary);

    printf("Enter Credit Score : ");
    scanf("%d",p_score);

    printf("Enter Experience : ");
    scanf("%d",p_expr);
}

int isEligible(float salary, int score , int expr){
    return(salary>=30000 && score >= 750 && expr >= 2);
}
int main(){
    float salary;
    int score;
    int expr;
    readDetails(&salary,&score,&expr);
    if(isEligible(salary,score,expr)){
        printf("Loan Approved");
    } else{
        printf("Loan Rejected");
    }
    return 0;
}
