#include <stdio.h>
#include <math.h> 

int main() 
{ 
    int size = 10; 
    for (int row = 0; row < size; row++) 
    {
        for (int col = 0; col <= 4*size; col++) 
        {
            float dist1 = sqrt(pow(row - size, 2) + pow(col - size, 2)); 
            float dist2 = sqrt(pow(row - size, 2) + pow(col - 3*size, 2)); 
            if (dist1 < size + 0.5 || dist2 < size + 0.5) 
                printf("*"); 
            else 
                printf(" "); 
        }
        printf("\n"); 
    }
    for (int row = 1; row < 2*size; row++) 
    {
        for (int col = 0; col < row; col++) 
            printf(" "); 
        for (int col = 0; col < 4*size + 1 - 2*row ; col++)
            printf("*"); 
            printf("\n");
    }
}

// 1. @LINE 6: row is undefined
// 2. @LINE 17: missing ""
// 3. @LINE 23: invalid for arg format
// 4. @LINE 23-25: for loop will run only line 24 (?)
// 5. @LINE 25: missing ;
// 6. @LINE 27: missing } for `for` loop