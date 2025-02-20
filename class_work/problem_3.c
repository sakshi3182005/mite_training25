#include <stdio.h>

// Define structures for Fiction and Non-fiction books
struct Fiction_t { //383
    char title[250];
    char author[125];
    float price;
};
typedef struct Fiction_t Fiction;

struct NonFiction_t { //758
    char title[250];
    char author[125];
    float price;
};
typedef struct NonFiction_t NonFiction;

// Define a union to hold either Fiction or Non-fiction book details
union Book {
    Fiction fiction;
    NonFiction nonFiction;
};
typedef union Book BookType;

// Define a structure to keep track of the type of book and the book details
struct Book_t {
    int type; // 1 for Fiction, 2 for Non-fiction
    BookType booktype;
};
typedef struct Book_t Book;

Book books[1000];
int bookCount = 0;

void addBooks();
void displayBooks();

int main() {
    addBooks();
    displayBooks();
    return 0;
}

void addBooks() {
    printf("Enter number of books: ");
    scanf("%d", &bookCount);

    for (int i = 0; i < bookCount; i++) {
        printf("Type of book (1-Fiction, 2-Non Fiction): ");
        scanf("%d", &books[i].type);

        switch (books[i].type) {
            case 1: {
                printf("Enter Fiction Details (Title, Author, Price): ");
                scanf("%s %s %f", books[i].booktype.fiction.title,
                      books[i].booktype.fiction.author,
                      &books[i].booktype.fiction.price);
            } break;
            case 2: {
                printf("Enter Non-fiction Details (Title, Author, Price): ");
                scanf("%s %s %f", books[i].booktype.nonFiction.title,
                      books[i].booktype.nonFiction.author,
                      &books[i].booktype.nonFiction.price);
            } break;
            default:
                printf("Invalid book type! Try again.\n");
                i--; // Decrement counter to retry this entry
        }
    }
}

void displayBooks() {
    for (int i = 0; i < bookCount; i++) {
        switch (books[i].type) {
            case 1: {
                printf("Fiction Book: %s, Author: %s, Price: $%.2f\n",
                       books[i].booktype.fiction.title,
                       books[i].booktype.fiction.author,
                       books[i].booktype.fiction.price);
            } break;
            case 2: {
                printf("Non-fiction Book: %s, Author: %s, Price: $%.2f\n",
                       books[i].booktype.nonFiction.title,
                       books[i].booktype.nonFiction.author,
                       books[i].booktype.nonFiction.price);
            } break;
            default:
                printf("Unknown book type!\n");
        }
    }
}
