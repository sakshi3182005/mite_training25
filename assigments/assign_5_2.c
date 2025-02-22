#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 100

typedef struct {
    char items[MAX_STOCK][256];
    int top;
} Warehouse;

void initWarehouse(Warehouse *warehouse) {
    warehouse->top = -1;
}

int isWarehouseEmpty(Warehouse *warehouse) {
    return warehouse->top == -1;
}

int isWarehouseFull(Warehouse *warehouse){
    return warehouse->top == MAX_STOCK -1;
}

void addItem(Warehouse *warehouse, const char *item) {
    if(isWarehouseFull(warehouse)){
        printf("Warehouse is full. Cannot add %s\n", item);
        return;
    }
    strcpy(warehouse->items[++warehouse->top], item);
    printf("Stock Added: %s\n", item);
}

char *dispatchItem(Warehouse *warehouse) {
    if (!isWarehouseEmpty(warehouse)) {
        return warehouse->items[warehouse->top--];
    }
    return NULL;
}

void showStock(Warehouse *warehouse) {
    if (isWarehouseEmpty(warehouse)) {
        printf("Remaining Stock: Empty\n");
        return;
    }

    printf("Remaining Stock: ");
    for (int i = 0; i <= warehouse->top; i++) {
        printf("%s", warehouse->items[i]);
        if (i < warehouse->top) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse);

    addItem(&warehouse, "Item A");
    addItem(&warehouse, "Item B");
    addItem(&warehouse, "Item C");

    char *dispatchedItem = dispatchItem(&warehouse);
    if (dispatchedItem != NULL) {
        printf("Dispatching Item: %s\n", dispatchedItem);
    }

    showStock(&warehouse);

    addItem(&warehouse, "Item D");
    showStock(&warehouse);

    dispatchedItem = dispatchItem(&warehouse);
    if (dispatchedItem != NULL) {
        printf("Dispatching Item: %s\n", dispatchedItem);
    }
    showStock(&warehouse);

    while (!isWarehouseEmpty(&warehouse)){
        dispatchedItem = dispatchItem(&warehouse);
        if (dispatchedItem != NULL) {
            printf("Dispatching Item: %s\n", dispatchedItem);
        }
    }
    showStock(&warehouse);

    return 0;
}
