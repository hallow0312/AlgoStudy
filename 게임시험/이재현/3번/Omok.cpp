#include "Omok.h"
#include <iostream>
#include <iomanip>
using namespace std;

Omok::Omok(int size) : boardSize(size), currentPlayer('X') {
    // 게임판을 빈 공간('.')으로 초기화
    board = vector<vector<char>>(boardSize, vector<char>(boardSize, '.'));
}

void Omok::displayBoard() const {
    cout << "\n  ";
    // 열 번호 출력
    for (int i = 0; i < boardSize; i++) {
        cout << setw(2) << i;
    }
    cout << endl;

    // 행별로 게임판 출력
    for (int i = 0; i < boardSize; i++) {
        cout << setw(2) << i;  // 행 번호
        for (int j = 0; j < boardSize; j++) {
            cout << " " << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool Omok::makeMove(int row, int col) {
    // 범위 검사 및 빈 자리 확인
    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize ||
        board[row][col]!='.') 
    {
        return false;
    }

    // 현재 플레이어의 돌을 놓음
    board[row][col] = currentPlayer;
    return true;
}

bool Omok::checkWin(int row, int col) const {
    // 4가지 방향: 가로(1,0), 세로(0,1), 대각선(1,1), 역대각선(1,-1)
    int directions[4][2] = { {1,0}, {0,1}, {1,1}, {1,-1} };

    for (int dir = 0; dir < 4; dir++) {
        int count = 1;  // 현재 놓은 돌 포함
        int dx = directions[dir][0];
        int dy = directions[dir][1];

        // 한 방향으로 확인
        for (int i = 1; i < 5; i++) {
            int newRow = row + dx * i;
            int newCol = col + dy * i;

            if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize &&
                board[newRow][newCol] == currentPlayer) {
                count++;
            }
            else {
                break;
            }
        }

        // 반대 방향으로 확인
        for (int i = 1; i < 5; i++) {
            int newRow = row - dx * i;
            int newCol = col - dy * i;

            if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize &&
                board[newRow][newCol] == currentPlayer) {
                count++;
            }
            else {
                break;
            }
        }

        // 5개 이상 연속이면 승리
        if (count >= 5) {
            return true;
        }
    }
    return false;
}

void Omok::switchPlayer() {
    // 흑돌(X)과 백돌(O) 교체
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

char Omok::getCurrentPlayer() const {
    return currentPlayer;
}

bool Omok::isBoardFull() const {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == '.') {
                return false;  // 빈 자리가 있으면 가득 차지 않음
            }
        }
    }
    return true;  // 모든 자리가 차있음
}

void Omok::playGame() {
    int row, col;
    int moveCount = 0;

    cout << "===============================================" << endl;
    cout << "               오목 게임" << endl;
    cout << "===============================================" << endl;
    cout << "흑돌(X)이 먼저 시작합니다." << endl;
    cout << "5개의 돌을 연속으로 놓으면 승리!" << endl;
    cout << "게임 종료는 -1 -1을 입력하세요." << endl;
    cout << "===============================================" << endl;

    while (true) {
        displayBoard();

        // 현재 플레이어 정보 출력
        string playerName = (currentPlayer == 'X') ? "흑돌" : "백돌";
        cout << "플레이어 " << playerName << "(" << currentPlayer << ") 차례입니다. (수: " << moveCount / 2 + 1 << ")" << endl;
        cout << "행과 열을 입력하세요 (0-" << boardSize - 1 << ") 또는 종료(-1 -1): ";

        cin >> row >> col;

        // 게임 종료 조건
        if (row == -1 && col == -1) {
            cout << "\n게임이 종료되었습니다. 안녕히 가세요!" << endl;
            break;
        }

        // 잘못된 입력 처리
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "숫자를 입력해 주세요!" << endl << endl;
            continue;
        }

        // 돌 놓기 시도
        if (!makeMove(row, col)) {
            cout << "잘못된 위치입니다! 다시 시도해 주세요." << endl;
            cout << "   (범위: 0-" << boardSize - 1 << ", 빈 자리여야 함)" << endl << endl;
            continue;
        }

        moveCount++;

        // 승리 조건 확인
        if (checkWin(row, col)) {
            displayBoard();
            cout << "=======================================" << endl;
            cout << "플레이어 " << playerName << "(" << currentPlayer << ") 승리!" << endl;
            cout << "=======================================" << endl;
            cout << "게임이 " << moveCount << "수만에 끝났습니다!" << endl;
            break;
        }

        // 무승부 확인
        if (isBoardFull()) {
            displayBoard();
            cout << "무승부! 게임판이 가득 찼습니다." << endl;
            break;
        }

        // 플레이어 교체
        switchPlayer();
    }
}