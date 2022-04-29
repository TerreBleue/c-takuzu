#include <stdlib.h>
#include <time.h>

#include "menu.h"


int main(void) {
    srand((unsigned int) time(NULL));

    return menu();
}
