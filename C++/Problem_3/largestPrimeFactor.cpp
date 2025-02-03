/* The prime factors of 13195 are 5,7,13 and 29.
 * What is the largest prime factor of the number 600851475143?
 *
 * STATUS: IN PROGRESS.
 */
#include <cstdint>
#include <iostream>
#define FIND_PRIME 600851475143


// we find a factor of FIND_PRIME
// then we calculate if that is a prime number


bool primeFound(int potentialPrime) {
    std::int32_t potentialPrimeCeiling { (potentialPrime / 2) };

    for (std::int32_t counter = 2; counter < potentialPrimeCeiling; counter++) {
        if ( potentialPrimeCeiling % counter == 0 ) {
            // Non-prime found.
            return false;
        }
    }

    // A prime number has been found.
    return true;
}



int main() {

    // Logically, no prime factor can be greater than half of the value you are trying to find the prime factors of.
    // Recall that in C++ any fractional part of the quotient is dropped, hence the +1.
    std::int64_t primeCeiling { (FIND_PRIME / 2) + 1 };

    // Performing a negative loop allows us to find the largest factor first, don't need to calculate every prime factor.
    do {
        // Check if the current highest potential value is a factor of FIND_PRIME.
        if (primeCeiling % FIND_PRIME == 0) {
            // If current highest potential value is itself a prime number, end the search.
            if (primeFound(primeCeiling)) {
                break;
            }
        }
        // Else, decrease the highest potential value by one and continue the search.
        primeCeiling--;
    } while (primeCeiling >= 2);

    // Output the largest prime factor of FIND_PRIME.
    std::cout << "The largest prime factor of " << FIND_PRIME << " is: " << primeCeiling << '\n';

    return 0;
}
