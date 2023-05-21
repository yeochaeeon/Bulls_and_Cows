#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // 현재 시간을 기반으로 시드(seed) 설정

    int randomValue = rand() % 900 + 100;  // 100부터 999까지의 범위에서 랜덤 값 생성

    printf("세 자리 랜덤 값: %d\n", randomValue);

    return 0;
}
