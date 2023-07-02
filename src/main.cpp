#include <iostream>
#include <string>
#include <stdio.h>
#include "regex_c.hpp"
// #include "regex_c.h"


int main ( void )
{
    char originalInput[] = "Hello, world! I am happy today. Hello, world! Hello, world! Save the World";
    const char pattern[] = "world";
    const char replacement[] = "there";

    char input[sizeof(originalInput)];
    strcpy(input, originalInput);

    replaceAll(input, pattern, replacement);

    std::cout << input << std::endl;

    return 0;
}