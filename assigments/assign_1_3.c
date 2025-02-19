//Payment Gateway

#include <stdio.h>
#include <string.h>

int main() {
    int paymentMethod;
    char cardNumber[17];
    char upiID[50];
    int bankChoice;

    printf("Select Payment Method (1-3):\n");
    printf("1. Credit/Debit Card\n");
    printf("2. UPI\n");
    printf("3. Net Banking\n");
    scanf("%d", &paymentMethod);

    switch (paymentMethod) {
        case 1:
            printf("Enter a 16-digit card number: ");
            scanf("%s", cardNumber);
            if (strlen(cardNumber) == 16) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;
        case 2:
            printf("Enter your UPI ID: ");
            scanf("%s", upiID);
            printf("Payment Successful!\n");
            break;
        case 3:
            printf("Select a bank:\n");
            printf("1. SBI\n");
            printf("2. HDFC\n");
            scanf("%d", &bankChoice);
            if (bankChoice == 1 || bankChoice == 2) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;
        default:
            printf("Invalid payment method. Please try again.\n");
    }

    return 0;
}
