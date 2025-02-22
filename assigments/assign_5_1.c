#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 100

typedef struct {
    char urls[MAX_HISTORY][256];
    int top;
    int forward_top;
    char forward_urls[MAX_HISTORY][256];
} BrowserHistory;

void initHistory(BrowserHistory *history) {
    history->top = -1;
    history->forward_top = -1;
}

int isHistoryEmpty(BrowserHistory *history) {
    return history->top == -1;
}

int isForwardEmpty(BrowserHistory *history) {
    return history->forward_top == -1;
}

void push(BrowserHistory *history, const char *url) {
    if (history->top < MAX_HISTORY - 1) {
        strcpy(history->urls[++history->top], url);
        history->forward_top = -1; // Clear forward history on new page visit
    } else {
        printf("History is full!\n");
    }
}

char *pop(BrowserHistory *history) {
    if (!isHistoryEmpty(history)) {
        return history->urls[history->top--];
    }
    return NULL;
}

void pushForward(BrowserHistory *history, const char *url) {
    if (history->forward_top < MAX_HISTORY - 1) {
        strcpy(history->forward_urls[++history->forward_top], url);
    } else {
        printf("Forward History is full!\n");
    }
}

char *popForward(BrowserHistory *history) {
    if (!isForwardEmpty(history)) {
        return history->forward_urls[history->forward_top--];
    }
    return NULL;
}

void goBack(BrowserHistory *history) {
    if (history->top > 0) { // Prevent going back from the first page
        pushForward(history, history->urls[history->top]); //push current page to forward stack
        history->top--;
        printf("Current Page: %s\n", history->urls[history->top]);
    } else {
        printf("Cannot go back further.\n");
    }
}

void goForward(BrowserHistory *history) {
    if (!isForwardEmpty(history)) {
        push(history, history->forward_urls[history->forward_top]);
        history->forward_top--;

        printf("Current Page: %s\n", history->urls[history->top]);
    } else {
        printf("Cannot go forward.\n");
    }
}

int main() {
    BrowserHistory history;
    initHistory(&history);

    push(&history, "google.com");
    push(&history, "github.com");
    push(&history, "stackoverflow.com");

    printf("Action: Go Back\n");
    goBack(&history);

    printf("Action: Go Forward\n");
    goForward(&history);

    printf("Action: Go Back\n");
    goBack(&history);

    printf("Action: Go Back\n");
    goBack(&history);

    printf("Action: Go Back\n");
    goBack(&history);

    printf("Action: Go Forward\n");
    goForward(&history);

    printf("Action: Go Forward\n");
    goForward(&history);

    printf("Action: Go Forward\n");
    goForward(&history);

    return 0;
}
