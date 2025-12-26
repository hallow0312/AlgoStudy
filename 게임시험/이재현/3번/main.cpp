#include <windows.h>
#include "Omok.h"
#include <iostream>
using namespace std;

int main() {
    int size;

    // 콘솔 창 제목 설정
    SetConsoleTitleA("수험자: 이재현 수험번호: 202112296");

    cout << "오목 게임에 오신 것을 환영합니다!" << endl;
    cout << "게임판 크기를 입력하세요 (권장: 15): ";
    cin >> size;

    // 입력 검증
    if (size < 5 || size > 25) {
        cout << "잘못된 게임판 크기입니다. 기본 크기 15를 사용합니다." << endl;
        size = 15;
    }

    // 게임 객체 생성 및 게임 시작
    Omok game(size);
    game.playGame();

    cout << "게임해 주셔서 감사합니다!" << endl;
    return 0;
}