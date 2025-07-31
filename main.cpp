#include <iostream>
#include <algorithm>
#include <memory>

int f()
{
    return 42;
}

int main()
{
    std::byte f_buffer[32];
    std::copy((std::byte*)(&f), (std::byte*)(&f) + sizeof(f_buffer), f_buffer);

    int (*f_in_stack)() = reinterpret_cast<int(*)()>(f_buffer);

    std::cout << f_in_stack() << std::endl;
    return 0;
}