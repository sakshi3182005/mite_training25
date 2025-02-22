#include <stdio.h>

int searchLinear(float* salaries, int size, float searchSalary);
int searchBinary(float* salaries, int size, float searchSalary);

int main() {
    float salaries[] = {10.0f, 12.0f, 13.0f, 15.0f, 20.0f};
    int salariesCount = 5;
    float searchSalary = 15.0f;

    int index = searchBinary(salaries, salariesCount, searchSalary);

    printf("%.2f found at index %d\n", searchSalary, index);

    return 0;
}

int searchLinear(float* salaries, int size, float searchSalary) {
    for (int i = 0; i < size; i++) {
        if (salaries[i] == searchSalary) {
            return i;
        }
    }
    return -1;
}

int searchBinary(float* salaries, int size, float searchSalary) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (salaries[mid] == searchSalary) {
            return mid;
        } else if (searchSalary < salaries[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
