#include <iostream>
#include <string>
#include <stdio.h>
#include "regex_c.hpp"
// #include "regex_c.h"


int main ( void )
{
    // char originalInput[] = "Hello, world! I am happy today. Hello, world! Hello, world! Save the World";
    // const char pattern[] = "world";
    // const char replacement[] = "there";

    char originalInput[] = "今年COLLAR連同成員單曲總共推出12首歌";
    const char pattern[] = "成員單曲";
    const char replacement[] = "there";

    char input[sizeof(originalInput)];
    strcpy(input, originalInput);

    // using replaceAll function
    replaceAll(input, pattern, replacement);

    std::cout << "input: " << input << std::endl;

    // using StringReplacer
    char input2[sizeof(originalInput)];
    strcpy(input2, originalInput);

    StringReplacer stringReplacer = StringReplacer(pattern, replacement);
    stringReplacer.replace(input2);

    std::cout << "input2: " << input2 << std::endl;
    return 0;
}