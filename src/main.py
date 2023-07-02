import ctypes

if __name__ == '__main__':
    
    print("opening liblibrary.so")
    my_so = ctypes.cdll.LoadLibrary('../lib/libregexc.so')
    print("loaded my_so")
        
    my_so.replaceAll.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_char_p]

    print(f".so object: {my_so}")
    print("call print_value function")
    input = b"Hello, world! I am happy today. Hello, world! Hello, world! Save the World"
    pattern = b"world"
    replacement = b"there"
    my_so.replaceAll(input, pattern, replacement)
    print(input)