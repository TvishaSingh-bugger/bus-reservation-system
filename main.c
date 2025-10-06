#include <stdio.h>
#include "auth.h"
#include "menu.h"

int main()
{
    authenticate();
    showMenu();
    freeAuth();
    return 0;
}