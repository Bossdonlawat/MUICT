#include <stdio.h>

#define N 4

int gcd(int num1, int num2) {
    // Parameter to store the GCD
    int result;

    ////////////////////////////////////////////////////////////////////////
    //                        Start of your code                          //
    ////////////////////////////////////////////////////////////////////////
    
    /*
        TODO: Write an algorithm to compute the GCD of `num1` and `num2`.
              Then store the GCD in the provided parameter, `result`.
    */
    if (num2 != 0)
       return gcd(num2, num1%num2);
    else 
       result = num1;

    ////////////////////////////////////////////////////////////////////////
    //                         End of your code                           //
    ////////////////////////////////////////////////////////////////////////

    // Return the GCD
    return result;
}

int main() {
    int num[N];     // Input numbers
    int result;     // GCD of the input numbers

    printf("Enter %d numbers: ", N);
    for (int i=0 ; i<N ; i++) {
        scanf("%d", &num[i]);
    }

    ////////////////////////////////////////////////////////////////////////
    //                        Start of your code                          //
    ////////////////////////////////////////////////////////////////////////
    
    /*
        TODO: Fill in your code here to use the self-defined function:

            int gcd(int num1, int num2);

        to compute the GCD among 4 numbers.

        Hint: the following code is an example of how to compute the gcd
              of the 3 numbers.

        result = gcd(num[0], num[1]);
        result = gcd(result, num[2]);
    */

   result = gcd(num[0], gcd(num[1], gcd(num[2], num[3])));

    ////////////////////////////////////////////////////////////////////////
    //                         End of your code                           //
    ////////////////////////////////////////////////////////////////////////

    printf("GCD of ");
    for (int i=0 ; i<N ; i++) {
        printf("%d ", num[i]);
    }
    printf("is %d\n", result);

    return 0;
}