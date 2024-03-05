#include <stdio.h>
/*
*   Copyright 2024 AnatoliyL
*   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer
*   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*   4. All products derived from this software must retain permittion to redistribute, use in source and binary forms, with or without modification.
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
int main()
{
    unsigned long long n; // Creating a variable
    unsigned long long min = 2147483647; // Creating a variable that contains minimum iteration
    unsigned long long max = 0; // Creating a variable that contains maximum iteration
    scanf("%lld", &n); // Taking input
    long long counter = 0; // Creating a counter
    if (n == 1)
        return (n);
    else if (n == 0)
        return (-1);
    else if (n < 0)
        return (-2147483648);
    while (n != 1) // Collatz conjecture
    {
        if (n < min) // If number is less than minimum
            min = n; // Update the minimum
        if (n > max) // If number is greater than maximum
            max = n; // Update the maximum
        counter++; // Incrementing the counter
        if (n % 2 == 0) // If number is even
            n = n / 2;  // divide it by 2
        else // If number is odd
            n = 3.00 * n + 1.00; // multiply it by 3 and add 1
        printf("%lld\n", n); // Print the number
    }
    printf("Max: %lld\n", max); // Print the maximum
    printf("Min: %lld\n", min); // Print the minimum
    printf("%lld steps\n", counter); // Print the number of steps
    return (n); // Return the number
}