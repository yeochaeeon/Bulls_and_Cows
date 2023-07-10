#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber() {
    srand(time(NULL));
    int randomNumber;

    do {
        randomNumber = rand() % 900 + 100;
    } while (!isDistinct(randomNumber));

    return randomNumber;
}

int isDistinct(int number) {
    int digits[3];
    digits[0] = number / 100;     // 백의 자리 숫자
    digits[1] = (number % 100) / 10;    // 십의 자리 숫자
    digits[2] = number % 10;     // 일의 자리 숫자

    if (digits[0] != digits[1] && digits[0] != digits[2] && digits[1] != digits[2]) {
        return 1;   // 서로 다른 숫자일 경우 1 반환
    } else {
        return 0;   // 중복된 숫자일 경우 0 반환
    }
}

int main() {
    int targetNumber = generateRandomNumber();
    int guess, strike, ball;
    int guessCount = 0;

    printf("숫자야구 게임을 시작합니다!\n");

    do {
        strike = 0;
        ball = 0;

        printf("세 자리 숫자를 입력하세요: ");
        scanf("%d", &guess);

        if (guess < 100 || guess > 999) {
            printf("잘못된 입력입니다. 세 자리 숫자를 입력해주세요.\n");
            continue;
        }

        int targetDigits[3];
        int guessDigits[3];

        targetDigits[0] = targetNumber / 100;
        targetDigits[1] = (targetNumber % 100) / 10;
        targetDigits[2] = targetNumber % 10;

        guessDigits[0] = guess / 100;
        guessDigits[1] = (guess % 100) / 10;
        guessDigits[2] = guess % 10;

        for (int i = 0; i < 3; i++) {
            if (guessDigits[i] == targetDigits[i]) {
                strike++;
            } else if (guessDigits[i] == targetDigits[(i + 1) % 3] || guessDigits[i] == targetDigits[(i + 2) % 3]) {
                ball++;
            }
        }

        printf("%d 스트라이크, %d 볼\n", strike, ball);
        guessCount++;
    } while (strike < 3);

    printf("축하합니다! 정답을 맞췄습니다. 시도한 횟수: %d\n", guessCount);

    return 0;
}
