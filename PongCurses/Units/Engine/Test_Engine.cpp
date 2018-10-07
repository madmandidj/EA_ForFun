#include <unistd.h>
#include "Engine.hpp"
#include "../Window/Window.hpp"
#include "../Object_t/Object_t.hpp"
static unsigned int PLAYWIN_WIDTH = 140;
static unsigned int PLAYWIN_HEIGHT = 35;
// static unsigned int NUM_OF_BALL_ANGLES = 12;
// static unsigned int MAX_CONSECUTIVE_STEPS = 6;
static unsigned int CUR_RD_PATTERN = 6;
static unsigned int CUR_LD_PATTERN = 6;
static unsigned int CUR_RU_PATTERN = 5;
static unsigned int CUR_LU_PATTERN = 5;

typedef enum
{
    Angle_15 = 0,
    Angle_30,
    Angle_45,
    Angle_60,
    Angle_75,
    Angle_85,
    Angle_95,
    Angle_105,
    Angle_120,
    Angle_135,
    Angle_150,
    Angle_165
}BallAngle;

class BallMovementPattern
{
public:
    BallMovementPattern(unsigned int _colSteps, unsigned int _rowSteps, Object_t::ObjMoveDirection _colDirection, Object_t::ObjMoveDirection _rowDirection) :
        m_numOfColumnSteps(_colSteps), m_numOfRowSteps(_rowSteps), m_colDirection(_colDirection), m_rowDirection(_rowDirection){}
    ~BallMovementPattern(){}
    BallMovementPattern(const BallMovementPattern& _otherPattern)
    {
        *this = _otherPattern;
    }
    BallMovementPattern& operator=(const BallMovementPattern& _otherPattern)
    {
        m_numOfColumnSteps = _otherPattern.m_numOfColumnSteps;
        m_numOfRowSteps = _otherPattern.m_numOfRowSteps;
        m_colDirection = _otherPattern.m_colDirection;
        m_rowDirection = _otherPattern.m_rowDirection;
        return *this;
    }
    unsigned int GetColSteps() const {return m_numOfColumnSteps;}
    unsigned int GetRowSteps() const {return m_numOfRowSteps;}
    Object_t::ObjMoveDirection GetColDirection() const {return m_colDirection;}
    Object_t::ObjMoveDirection GetRowDirection() const {return m_rowDirection;}
protected:

private:
    unsigned int m_numOfColumnSteps;
    unsigned int m_numOfRowSteps;
    Object_t::ObjMoveDirection m_colDirection;
    Object_t::ObjMoveDirection m_rowDirection;
};

Window::SharedObjectPtr CreateBall(Engine::WindowSharedPtr& _winPtrRef);
Window::SharedObjectPtr CreateBrickL(Engine::WindowSharedPtr& _winPtrRef);
Window::SharedObjectPtr CreateBrickR(Engine::WindowSharedPtr& _winPtrRef);



int main()
{
    Engine engine;
    engine.CreateWindow(PLAYWIN_WIDTH, PLAYWIN_HEIGHT, Window::PLAY_WIN, 0, 0); 
    Engine::WindowSharedPtr playWin = engine.GetWindow(Window::PLAY_WIN);
    BallMovementPattern ballMovePatternArr_R[12] = 
    {
        BallMovementPattern(1, 6, Object_t::R, Object_t::U),
        BallMovementPattern(2, 5, Object_t::R, Object_t::U),
        BallMovementPattern(3, 4, Object_t::R, Object_t::U),
        BallMovementPattern(4, 3, Object_t::R, Object_t::U),
        BallMovementPattern(5, 2, Object_t::R, Object_t::U),
        BallMovementPattern(6, 1, Object_t::R, Object_t::U),
        BallMovementPattern(6, 1, Object_t::R, Object_t::D),
        BallMovementPattern(5, 2, Object_t::R, Object_t::D),
        BallMovementPattern(4, 3, Object_t::R, Object_t::D),
        BallMovementPattern(3, 4, Object_t::R, Object_t::D),
        BallMovementPattern(2, 5, Object_t::R, Object_t::D),
        BallMovementPattern(1, 6, Object_t::R, Object_t::D)
    };
    BallMovementPattern ballMovePatternArr_L[12] = 
    {
        BallMovementPattern(1, 6, Object_t::L, Object_t::U),
        BallMovementPattern(2, 5, Object_t::L, Object_t::U),
        BallMovementPattern(3, 4, Object_t::L, Object_t::U),
        BallMovementPattern(4, 3, Object_t::L, Object_t::U),
        BallMovementPattern(5, 2, Object_t::L, Object_t::U),
        BallMovementPattern(6, 1, Object_t::L, Object_t::U),
        BallMovementPattern(6, 1, Object_t::L, Object_t::D),
        BallMovementPattern(5, 2, Object_t::L, Object_t::D),
        BallMovementPattern(4, 3, Object_t::L, Object_t::D),
        BallMovementPattern(3, 4, Object_t::L, Object_t::D),
        BallMovementPattern(2, 5, Object_t::L, Object_t::D),
        BallMovementPattern(1, 6, Object_t::L, Object_t::D)
    };
    Window::SharedObjectPtr ballPtr = CreateBall(playWin);
    Window::SharedObjectPtr brickLPtr = CreateBrickL(playWin);
    Window::SharedObjectPtr brickRPtr = CreateBrickR(playWin);

    engine.RefreshScreen();
    usleep(100000);
    Object_t::ObjMoveDirection curHorizDirection = Object_t::R;
    Object_t::ObjMoveDirection curVertDirection = Object_t::D;
    for (int index = 0; index < 450; ++index)
    {       
        switch (curHorizDirection)
        {
        case Object_t::R:
            switch (curVertDirection)
            {
            case Object_t::U:
                if (Object_t::R != ballPtr->Move(ballMovePatternArr_R[CUR_RU_PATTERN].GetColSteps(), ballMovePatternArr_R[CUR_RU_PATTERN].GetColDirection(), playWin->GetWidth(), playWin->GetHeight()))
                {
                    while (Object_t::R == ballPtr->Move(1, ballMovePatternArr_R[CUR_RU_PATTERN].GetColDirection(), playWin->GetWidth(), playWin->GetHeight()))
                    {}
                    curHorizDirection = Object_t::L;
                    // continue;
                }
                if (Object_t::U != ballPtr->Move(ballMovePatternArr_R[CUR_RU_PATTERN].GetRowSteps(), ballMovePatternArr_R[CUR_RU_PATTERN].GetRowDirection(), playWin->GetWidth(), playWin->GetHeight()))
                {
                    while(Object_t::U == ballPtr->Move(1, ballMovePatternArr_R[CUR_RU_PATTERN].GetRowDirection(), playWin->GetWidth(), playWin->GetHeight()))
                    {}
                    curVertDirection = Object_t::D;
                    // continue;
                }
            break;
            case Object_t::D:
                if (Object_t::R != ballPtr->Move(ballMovePatternArr_R[CUR_RD_PATTERN].GetColSteps(), ballMovePatternArr_R[CUR_RD_PATTERN].GetColDirection(), playWin->GetWidth(), playWin->GetHeight()))
                {
                    while(Object_t::R == ballPtr->Move(1, ballMovePatternArr_R[CUR_RD_PATTERN].GetColDirection(), playWin->GetWidth(), playWin->GetHeight()))
                    {}
                    curHorizDirection = Object_t::L;
                    // continue;
                }
                if (Object_t::D != ballPtr->Move(ballMovePatternArr_R[CUR_RD_PATTERN].GetRowSteps(), ballMovePatternArr_R[CUR_RD_PATTERN].GetRowDirection(), playWin->GetWidth(), playWin->GetHeight()))
                {
                    while(Object_t::D == ballPtr->Move(1, ballMovePatternArr_R[CUR_RD_PATTERN].GetRowDirection(), playWin->GetWidth(), playWin->GetHeight()))
                    {}
                    curVertDirection = Object_t::U;
                    // continue;
                }
            break;
            default:
            break;
            }
        break;
        case Object_t::L:
            switch (curVertDirection)
            {
            case Object_t::U:
                if (Object_t::L != ballPtr->Move(ballMovePatternArr_L[CUR_LU_PATTERN].GetColSteps(), ballMovePatternArr_L[CUR_LU_PATTERN].GetColDirection(), playWin->GetWidth(), playWin->GetHeight()))
                {
                    while(Object_t::L == ballPtr->Move(1, ballMovePatternArr_L[CUR_LU_PATTERN].GetColDirection(), playWin->GetWidth(), playWin->GetHeight()))
                    {}
                    curHorizDirection = Object_t::R;
                    // continue;
                }
                if (Object_t::U != ballPtr->Move(ballMovePatternArr_L[CUR_LU_PATTERN].GetRowSteps(), ballMovePatternArr_L[CUR_LU_PATTERN].GetRowDirection(), playWin->GetWidth(), playWin->GetHeight()))
                {
                    while(Object_t::U == ballPtr->Move(1, ballMovePatternArr_L[CUR_LU_PATTERN].GetRowDirection(), playWin->GetWidth(), playWin->GetHeight()))
                    {}
                    curVertDirection = Object_t::D;
                    // continue;
                }
            break;
            case Object_t::D:
                if (Object_t::L != ballPtr->Move(ballMovePatternArr_L[CUR_LD_PATTERN].GetColSteps(), ballMovePatternArr_L[CUR_LD_PATTERN].GetColDirection(), playWin->GetWidth(), playWin->GetHeight()))
                {
                    while(Object_t::L == ballPtr->Move(1, ballMovePatternArr_L[CUR_LD_PATTERN].GetColDirection(), playWin->GetWidth(), playWin->GetHeight()))
                    {}
                    curHorizDirection = Object_t::R;
                    // continue;
                }
                if (Object_t::D != ballPtr->Move(ballMovePatternArr_L[CUR_LD_PATTERN].GetRowSteps(), ballMovePatternArr_L[CUR_LD_PATTERN].GetRowDirection(), playWin->GetWidth(), playWin->GetHeight()))
                {
                    while(Object_t::D == ballPtr->Move(1, ballMovePatternArr_L[CUR_LD_PATTERN].GetRowDirection(), playWin->GetWidth(), playWin->GetHeight()))
                    {}
                    curVertDirection = Object_t::U;
                    // continue;
                }
            break;
            default:
            break;
            }
        break;
        default:
        break;
        }
        engine.RefreshScreen();
        usleep(50000);
    }
    sleep(1);
    engine.DeleteScreen();
    std::cout << std::endl << "Engine PASSED TESTS" << std::endl << std::endl;
    return 0;
}




Window::SharedObjectPtr CreateBall(Engine::WindowSharedPtr& _winPtrRef)
{
    Window::SharedObjectPtr ballPtr = _winPtrRef->CreateObject(Object_t::BALL);
    ballPtr->CreatePixel(PLAYWIN_WIDTH/2, PLAYWIN_HEIGHT/2, '*');
    return ballPtr;
}

Window::SharedObjectPtr CreateBrickL(Engine::WindowSharedPtr& _winPtrRef)
{
    Window::SharedObjectPtr brickLPtr = _winPtrRef->CreateObject(Object_t::BRICK_L);
    brickLPtr->CreatePixel(2,2,' ');
    brickLPtr->CreatePixel(3,2,'=');
    brickLPtr->CreatePixel(4,2,' ');
    brickLPtr->CreatePixel(2,3,'|');
    brickLPtr->CreatePixel(3,3,' ');
    brickLPtr->CreatePixel(4,3,'|');
    brickLPtr->CreatePixel(2,4,'|');
    brickLPtr->CreatePixel(3,4,' ');
    brickLPtr->CreatePixel(4,4,'|');
    brickLPtr->CreatePixel(2,5,'|');
    brickLPtr->CreatePixel(3,5,' ');
    brickLPtr->CreatePixel(4,5,'|');
    brickLPtr->CreatePixel(2,6,'|');
    brickLPtr->CreatePixel(3,6,' ');
    brickLPtr->CreatePixel(4,6,'|');
    brickLPtr->CreatePixel(2,7,' ');
    brickLPtr->CreatePixel(3,7,'=');
    brickLPtr->CreatePixel(4,7,' ');
    return brickLPtr;
}

Window::SharedObjectPtr CreateBrickR(Engine::WindowSharedPtr& _winPtrRef)
{
    Window::SharedObjectPtr brickRPtr = _winPtrRef->CreateObject(Object_t::BRICK_R);
    brickRPtr->CreatePixel(135,2,' ');
    brickRPtr->CreatePixel(136,2,'=');
    brickRPtr->CreatePixel(137,2,' ');
    brickRPtr->CreatePixel(135,3,'|');
    brickRPtr->CreatePixel(136,3,' ');
    brickRPtr->CreatePixel(137,3,'|');
    brickRPtr->CreatePixel(135,4,'|');
    brickRPtr->CreatePixel(136,4,' ');
    brickRPtr->CreatePixel(137,4,'|');
    brickRPtr->CreatePixel(135,5,'|');
    brickRPtr->CreatePixel(136,5,' ');
    brickRPtr->CreatePixel(137,5,'|');
    brickRPtr->CreatePixel(135,6,'|');
    brickRPtr->CreatePixel(136,6,' ');
    brickRPtr->CreatePixel(137,6,'|');
    brickRPtr->CreatePixel(135,7,' ');
    brickRPtr->CreatePixel(136,7,'=');
    brickRPtr->CreatePixel(137,7,' ');
    return brickRPtr;
}





