#include <iostream>
#include <algorithm>
#include <cstring>

#if defined(_WIN32) || defined(_WIN64)
  #include <process.h>  // for _exit on Windows
#else
  #include <unistd.h>   // for _exit on POSIX
#endif

void f()
{
    std::cout << "42";
    _exit(0);
}

int main()
{
    unsigned char code[] = 
    {
        0x48, 0x31, 0xc0, // xor rax, rax
        0xc3,             // ret
    };

    void (*func)() = (void(*)())code;
    func(); 

    std::cout << "Shellcode executed!\n";

    return 0;
}