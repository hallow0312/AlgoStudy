#ifndef OMOK_H
#define OMOK_H

#include <vector>
#include <string>
using namespace std;

class Omok {
private:
    vector<vector<char>> board;  // 게임판
    int boardSize;              // 게임판 크기
    char currentPlayer;         // 현재 플레이어 ('X' 또는 'O')

public:
    // 생성자: 게임판 크기를 받아 초기화
    Omok(int size = 15);

    // 게임판 출력
    void displayBoard() const;

    // 돌 놓기 (성공시 true, 실패시 false 반환)
    bool makeMove(int row, int col);

    // 승리 조건 확인
    bool checkWin(int row, int col) const;

    // 플레이어 교체
    void switchPlayer();

    // 현재 플레이어 반환
    char getCurrentPlayer() const;

    // 게임판이 가득 찼는지 확인
    bool isBoardFull() const;

    // 게임 시작
    void playGame();
};

#endif