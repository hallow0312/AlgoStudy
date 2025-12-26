#pragma once
#include <set>
#include <string>

////////////////////////////////////////////////////////////////////////////////

//상태 정의
enum STATE_TYPE
{
    STATE_IDLE, //대기 상태
    STATE_MOVE, //이동 상태
    STATE_ATTACK, //공격 상태
};

////////////////////////////////////////////////////////////////////////////////

//입력 정의
enum INPUT_TYPE
{
    INPUT_MOVE_UP, //위로 이동
    INPUT_MOVE_LEFT, //왼쪽으로 이동
    INPUT_MOVE_DOWN, //아래로 이동
    INPUT_MOVE_RIGHT, //오른쪽으로 이동
    INPUT_ATTACK, //공격
};

////////////////////////////////////////////////////////////////////////////////

class State;

//유한상태기계 클래스
class Fsm
{
public:
    Fsm();
    ~Fsm();

    void Transition(STATE_TYPE newState); //상태 전환 함수
    void Update(); //갱신 함수

    const std::set<INPUT_TYPE>& GetInputs() const;
    void SetInputs(const std::set<INPUT_TYPE>& inputs);

private:
    State* _currentState;
    std::set<INPUT_TYPE> _inputs;

    State* CreateState(STATE_TYPE state); //상태 생성 함수
};

////////////////////////////////////////////////////////////////////////////////

//부모 상태클래스
class State
{
public:
    State(Fsm* fsm) : _fsm(fsm) {}
    virtual ~State() {}
    virtual void Enter() = 0; //상태 진입 함수(상태가 시작될 때 호출)
    virtual void Update() = 0; //상태 갱신 함수(상태를 갱신할 때 호출)
    virtual void Exit() = 0; //상태 종료 함수(상태가 종료될 때 호출)
    virtual STATE_TYPE Type() const = 0;

protected:
    Fsm* _fsm;
};

//대기 상태클래스
class IdleState : public State
{
public:
    IdleState(Fsm* fsm) : State(fsm) {}
    void Enter() override;
    void Update() override;
    void Exit() override;
    STATE_TYPE Type() const override { return STATE_IDLE; }
};

//이동 상태클래스
class MoveState : public State
{
public:
    MoveState(Fsm* fsm) : State(fsm) {}
    void Enter() override;
    void Update() override;
    void Exit() override;
    STATE_TYPE Type() const override { return STATE_MOVE; }

private:
    std::string _direction;
    std::string CalculateDirection();
};

//공격 상태클래스
class AttackState : public State
{
public:
    AttackState(Fsm* fsm) : State(fsm) {}
    void Enter() override;
    void Update() override;
    void Exit() override;
    STATE_TYPE Type() const override { return STATE_ATTACK; }

private:
    unsigned long long _start;
};

////////////////////////////////////////////////////////////////////////////////