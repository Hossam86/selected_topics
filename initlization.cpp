#include <stdio.h>
void my_int_func(int x)
{
    printf("%d\n", x);
}

int main(int argc, char const *argv[])
{
    void (*foo)(int);

    // to initlize, you must give it the address of function 
    foo = &my_int_func;

    //call my_int_func (note that you do not need to write (*foo)(2) )
    foo(2);
    return 0;
}
