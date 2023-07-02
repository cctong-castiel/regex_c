import ctypes
import time
import re

if __name__ == '__main__':
    
    print("opening liblibrary.so")
    my_so = ctypes.cdll.LoadLibrary('../lib/libregexc.so')
    
    print("loaded my_so")    
    my_so.replaceAll.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_char_p]

    print(f".so object: {my_so}\n")
    input = b"Hello, world! I am happy today. Hello, world! Hello, world! Save the World"
    pattern = b"world"
    replacement = b"there"
    
    print("call replaceAll function for 10000 times")
    start = time.time()
    for i in range(10000):
        input = b"Hello, world! I am happy today. Hello, world! Hello, world! Save the World"
        my_so.replaceAll(input, pattern, replacement)
    print(input)
    print(f"time used for c++ replaceAll function: {time.time() - start}\n")
    
    print("call python regex replace function for 10000 times")
    input = "Hello, world! I am happy today. Hello, world! Hello, world! Save the World"
    pattern = "world"
    replacement = "there"
    
    start = time.time()
    for i in range(10000):
        input = "Hello, world! I am happy today. Hello, world! Hello, world! Save the World"
        input = re.sub(pattern, replacement, input)
    print(input)
    print(f"time used for python replace function: {time.time() - start}\n")