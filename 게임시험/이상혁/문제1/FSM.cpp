#include "fsm.h"
#include <iostream>
#include <windows.h>

////////////////////////////////////////////////////////////////////////////////

Fsm::Fsm()
{
    Transition(STATE_IDLE);
}

Fsm::~Fsm()
{
    if (_currentState != nullptr)
    {
        _currentState->Exit();
        delete _currentState;
        _currentState = nullptr;
    }
}

void Fsm::Transition(STATE_TYPE newState)
{
    if (_currentState != nullptr)
    {
        _currentState->Exit();
        delete _currentState;
    }

    _currentState = CreateState(newState);
    if (_currentState != nullptr) _currentState->Enter();
}

void Fsm::Update()
{
    if (_currentState != nullptr)
    {
        _currentState->Update();
    }
}

const std::set<INPUT_TYPE>& Fsm::GetInputs() const
{
    return _inputs;
}

void Fsm::SetInputs(const std::set<INPUT_TYPE>& inputs)
{
    _inputs = inputs;
}

State* Fsm::CreateState(STATE_TYPE state)
{
    //--------------------------------------------------------------------------------
    //★ 문항 1 : nullptr 대신 전달받은 StateType 에 맞게 State 클래스의 인스턴스를 생성하여 반환하시오.
    //            STATE_IDLE 을 전달 받았을 경우 IdleState 클래스의 인스턴스 생성후 반환
    //            STATE_MOVE 을 전달 받았을 경우 MoveState 클래스의 인스턴스 생성후 반환
    //            STATE_ATTACK 을 전달 받았을 경우 AttackState 클래스의 인스턴스 생성후 반환
    //--------------------------------------------------------------------------------

    State* NewState = nullptr;

    switch (state)
    {
    case STATE_IDLE:
        NewState = new IdleState(this);
        break;

    case STATE_MOVE:
        NewState = new MoveState(this);
        break;

    case STATE_ATTACK:
        NewState = new AttackState(this);
        break;
    }

    return NewState; //필요에 따라 변경 가능
}

////////////////////////////////////////////////////////////////////////////////

void IdleState::Enter()
{
    std::cout << "[ENTER] Idle" << std::endl;
}

void IdleState::Update()
{
    if (_fsm->GetInputs().empty()) return;

    if (_fsm->GetInputs().count(INPUT_ATTACK))
    {
        _fsm->Transition(STATE_ATTACK);
        return;
    }

    _fsm->Transition(STATE_MOVE);
}

void IdleState::Exit()
{
    std::cout << "[EXIT] Idle" << std::endl;
}

void MoveState::Enter()
{
    _direction = CalculateDirection();
    std::cout << "[ENTER] Move (" << _direction << ")" << std::endl;
}

void MoveState::Update()
{
    //--------------------------------------------------------------------------------
    //★ 문항 2 : 키 입력이 없을 경우 IDLE 상태로 변경하고
    //            INPUT_ATTACK 키가 입력되었을 경우 ATTACK 상태로 변경하시오.
    //            상태 변경이 되지 않을경우 아래의 콘솔 출력 부분이 실행되도록 하시오.
    //--------------------------------------------------------------------------------

    if (_fsm->GetInputs().empty())
    {
        _fsm->Transition(STATE_IDLE);
        return;
    }

    if (_fsm->GetInputs().count(INPUT_ATTACK))
    {
        _fsm->Transition(STATE_ATTACK);
        return;
    }

    //상태 변경이 되지 않을경우 실행 (변경하지 마시오.)
    _direction = CalculateDirection();
    std::cout << "[UPDATE] Move - " << _direction << std::endl;
}

void MoveState::Exit()
{
    std::cout << "[EXIT] Move" << std::endl;
}

std::string MoveState::CalculateDirection()
{
    const auto& keys = _fsm->GetInputs();

    std::string dir;
    if (keys.count(INPUT_MOVE_UP)) dir += "up ";
    if (keys.count(INPUT_MOVE_LEFT)) dir += "left ";
    if (keys.count(INPUT_MOVE_DOWN)) dir += "down ";
    if (keys.count(INPUT_MOVE_RIGHT)) dir += "right ";
    if (dir.empty()) return "stop";
    return dir;
}

void AttackState::Enter()
{
    std::cout << "[ENTER] Attack" << std::endl;
    _start = GetTickCount64();
}

void AttackState::Update()
{
    //--------------------------------------------------------------------------------
    //★ 문항 3 : 키입력 여부와 관계없이 ATTACK 상태가 시작된지 0.5초를 초과하면 IDLE 상태로 전환하시오.
    //            상태가 시작된 시간은 _start 변수에 저장되어 있음
    //            상태 변경이 되지 않을경우 아래의 콘솔 출력 부분이 실행되도록 하시오.
    //--------------------------------------------------------------------------------

    if (GetTickCount64() - _start > 0.5f)
    {
        _fsm->Transition(STATE_IDLE);
        return;
    }

    //상태 변경이 되지 않을경우 실행 (변경하지 마시오.)
    std::cout << "[UPDATE] Attack - Waiting End" << std::endl;
}

void AttackState::Exit()
{
    std::cout << "[EXIT] Attack" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////