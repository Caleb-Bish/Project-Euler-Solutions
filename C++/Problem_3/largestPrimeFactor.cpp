/* The prime factors of 13195 are 5,7,13 and 29.
 * What is the largest prime factor of the number 600851475143?
 *
 * STATUS: SOLVED.
 */
#include <cstdint>
#include <iostream>
#include <chrono>
#include <cmath>
#include "largestPrimeFactor.h"





// Calculate largest prime factor.
// This can be calculated using the Sieve of Eratosthenes more efficiently, may be worth returning to.
std::uint64_t largestPrimeFactor(std::uint64_t number) {
    /* As we're trying to find the PRIME factors, can do the same trick as described
     * within isPrime, where we calculate up to the sqrt of the value.
     * If we were trying to find the largest factor in general, would need to
     * calculate up to number / 2.
     * Recall that in C++ any fractional part of the quotient is dropped, hence the +1.
     */
    const std::uint64_t primeCeiling { std::sqrt(number) + 1 };

    // Check if the argument passed is itself prime.
    if ( isPrime(number) ) {
        return number;
    }

    std::uint64_t largestFound {};

    /* Since we're explicitly only looking for the largest prime factor,
     * can do a negative loop and then break out of it.
     */
    for (std::uint64_t counter{primeCeiling}; counter >= 2; counter-=2) {
        if ( number % counter == 0 && isPrime(counter)) {
                largestFound = counter;
                break;
                }
    }
    return largestFound;
}





// Check if an integral is prime.
bool isPrime (std::uint64_t potentialPrime) {

    // If the potentialPrime is divisible by 2 (or equal to 2 itself) then it cannot be prime.
    if (potentialPrime != 2 && potentialPrime % 2 == 0) {
            return false;
    }


   /* Only need to calculate up to the square root of the potentialPrime to determine if it is prime.
    * This is as if n is not a prime and as n = a*b, only 'a' OR 'b' can be > sqrt(n), as if a and b were both
    * > sqrt(n) then a*b would be greater than sqrt(n)*sqrt(n) = n, which is impossible. Hence, if a number is
    * composite then we will find at least one factor <= n, and if we don't then n is a prime.
    */
    std::int64_t potentialPrimeCeiling { std::sqrt(potentialPrime) + 1 };
    for (std::uint64_t counter {3}; counter <= potentialPrimeCeiling; counter+=2) {
        if (potentialPrime % counter == 0) {
            return false;
            }
    }
    return true;
}





int main() {
    const std::uint64_t findPrimeOf {600851475143};
    // For timing how long this program takes to find the largest prime factor.
    auto startPoint = std::chrono::high_resolution_clock::now();


    std::uint64_t largestPrime = largestPrimeFactor(findPrimeOf);


    // End the execution timer.
    auto endPoint = std::chrono::high_resolution_clock::now();
    auto executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endPoint - startPoint);


    // Output the largest prime factor and the time it took to find it.
    std::cout << "The largest prime factor of " << findPrimeOf << " is: " << largestPrime << '\n'
        << "Found in: " << executionTime.count() << " nanoseconds." << '\n';
    return 0;
}
