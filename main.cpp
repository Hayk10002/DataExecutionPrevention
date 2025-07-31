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
    std::byte f_buffer[256];
    std::memcpy((void*)f_buffer, (void*)&f, sizeof(f_buffer));

    auto f_in_stack = (void(*)())(f_buffer);

    f_in_stack();
}