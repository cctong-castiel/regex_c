#include <memory>
#include <cstring>
#include <iostream>
// #include "regex_c.h"
#include "regex_c.hpp" //comment out if use regex_c.h instead of regex_c.hpp

void replaceAll(char* str, const char* pattern, const char* replacement) {

    size_t patternLength = strlen(pattern);
    size_t replacementLength = strlen(replacement);
    size_t strLength = strlen(str);

    size_t occurrenceCount = 0;
    const char* startPos = str;
    while ((startPos = strstr(startPos, pattern)) != nullptr) {
        ++occurrenceCount;
        startPos += patternLength;
    }

    if (occurrenceCount == 0) {
        return;
    }

    size_t newLength = strLength + (replacementLength - patternLength) * occurrenceCount;

    const char* readPos = str;

    if (newLength > strLength)
    {

        // Perform the replacement
        char newStr[newLength];
        char* writePos = newStr;
        while (*readPos) {
            if (memcmp(readPos, pattern, patternLength) == 0) {
                memcpy(writePos, replacement, replacementLength);
                readPos += patternLength;
                writePos += replacementLength;
            } else {
                *writePos++ = *readPos++;
            }
        }
        *writePos = '\0'; // Add null terminator

        // Copy the modified string back to the original character array
        strcpy(str, newStr);
    } else {
        char* writePos = str;
        while (*readPos) {
            if (memcmp(readPos, pattern, patternLength) == 0) {
                memcpy(writePos, replacement, replacementLength);
                readPos += patternLength;
                writePos += replacementLength;
            } else {
                *writePos++ = *readPos++;
            }
        }
        *writePos = '\0';
    }
}

void StringReplacer::replace(char* str) {

    size_t patternLength = strlen(m_pattern);
    size_t replacementLength = strlen(m_replacement);
    size_t strLength = strlen(str);

    size_t occurrenceCount = 0;
    const char* startPos = str;
    while ((startPos = strstr(startPos, m_pattern)) != nullptr) {
        ++occurrenceCount;
        startPos += patternLength;
    }

    if (occurrenceCount == 0) {
        return;
    }

    size_t newLength = strLength + (replacementLength - patternLength) * occurrenceCount;

    const char* readPos = str;

    if (newLength > strLength)
    {

        // Perform the replacement
        char newStr[newLength];
        char* writePos = newStr;
        while (*readPos) {
            if (memcmp(readPos, m_pattern, patternLength) == 0) {
                memcpy(writePos, m_replacement, replacementLength);
                readPos += patternLength;
                writePos += replacementLength;
            } else {
                *writePos++ = *readPos++;
            }
        }
        *writePos = '\0'; // Add null terminator

        // Copy the modified string back to the original character array
        strcpy(str, newStr);
    } else {
        char* writePos = str;
        while (*readPos) {
            if (memcmp(readPos, m_pattern, patternLength) == 0) {
                memcpy(writePos, m_replacement, replacementLength);
                readPos += patternLength;
                writePos += replacementLength;
            } else {
                *writePos++ = *readPos++;
            }
        }
        *writePos = '\0';
    }
};


