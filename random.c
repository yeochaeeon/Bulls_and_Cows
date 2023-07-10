#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int randomValue = rand() % 1000;

    printf( "randomnumber: %d\n", randomValue );

    return 0;
}
