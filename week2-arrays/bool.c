#include <stdio.h>
#include <stdbool.h> // Include header for bool type

bool is_valid_triangle(float x, float y, float z);

bool is_valid_triangle(float x, float y, float z) {
    // Check for positive sides
    if (x <= 0 || y <= 0 || z <= 0) {
        return false;
    }

    // Check triangle inequality (simplified)
    if (x >= y + z || y >= x + z || z >= x + y) {
        return false;
    }

    // Triangle is valid
    return true;
}

int main() {
    float side1, side2, side3;

    printf("Enter three side lengths: ");
    scanf("%f %f %f", &side1, &side2, &side3);

    if (is_valid_triangle(side1, side2, side3)) {
        printf("The sides form a valid triangle.\n");
    } else {
        printf("The sides do not form a valid triangle.\n");
    }

    return 0;
}
