#include "fsm.h"
#include <iostream>
#include <tchar.h>
#include <windows.h>

bool IsKeyPressed(int vk)
{
    return (GetAsyncKeyState(vk) & 0x8000) != 0;
}

int main()
{
    system("cls");
    SetConsoleTitle(_T("문제"));

    //★ [필수] 수험생의 수험번호와 이름을 여기에 기입하여 출력될 수 있도록 함
    //   [주의] 수험번호와 이름이 출력되지 않을 경우 오답처리!
    printf(">> 수험번호 : \n");
    printf(">> 이    름 : \n\n");

    std::cout << "Controls:\n"
        << "- Hold W/A/S/D to move\n"
        << "- Press SPACE to attack\n"
        << "- Press ESC to quit\n";

    Fsm fsm;
    while (!IsKeyPressed(VK_ESCAPE))
    {
        std::set<INPUT_TYPE> keys;
        if (IsKeyPressed('W') || IsKeyPressed(VK_UP)) keys.insert(INPUT_MOVE_UP);
        if (IsKeyPressed('A') || IsKeyPressed(VK_LEFT)) keys.insert(INPUT_MOVE_LEFT);
        if (IsKeyPressed('S') || IsKeyPressed(VK_DOWN)) keys.insert(INPUT_MOVE_DOWN);
        if (IsKeyPressed('D') || IsKeyPressed(VK_RIGHT)) keys.insert(INPUT_MOVE_RIGHT);
        if (IsKeyPressed(VK_SPACE)) keys.insert(INPUT_ATTACK);
        fsm.SetInputs(keys);

        fsm.Update();
        Sleep(100);
    }

    return 0;
}
