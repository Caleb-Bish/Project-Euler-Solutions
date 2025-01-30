/* If we list all the natural numbers below 10 that are mutltiples of 3 or 5
 * we get 3,5,6, and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * STATUS: COMPLETE.
 */
#include <iostream>





// Function to return true or false if an integer argument is a multiple of the second integer argument.
bool isMultiple(int potentialMult, int multTester) {
    // list initialise as false.
    bool isMult { false };
    // If the argument to the function is a multiple of the second argument, the value of 'dividingResult' will be initialised to zero.
    int dividingResult {potentialMult % multTester};

    if (dividingResult == 0) {
            isMult = true;
    }

    return isMult;
}





int main() {
    // List initialise an integer variable to store the running sum of multiples.
    int runningTotal{};
    
    // As finding the sum of all multiples below 1,000 can hardcode a for loop.
    for (int counter {0}; counter < 1000; counter++) {
        // Check if loop counter is a multiple of three or five 
        if (isMultiple(counter, 3) == true || isMultiple(counter, 5) == true) {
            runningTotal+=counter;
       }
    }

    // Print the sum of all multiples.
    std::cout << "The sum of all multiples of 3 or 5 under 1,000 is: " << runningTotal << '\n';
    
    return 0;
}




