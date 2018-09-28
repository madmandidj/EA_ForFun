// maybe can help: https://invisible-island.net/ncurses/ncurses-intro.html

#include <curses.h>
#include <unistd.h>
#include <time.h>
#include <map>
#include <set>
// #define _BSD_SOURCE
// #define _XOPEN_SOURCE
// #define _POSIX_C_SOURCE 199309L 
#define TICKRATE 100
#define WINDOW_WIDTH 150 
#define WINDOW_HEIGHT 40 
#define PLAY_AREA_WIDTH 150
#define PLAY_AREA_HEIGHT 35

#define BRICK_WIDTH 1 
#define BRICK_HEIGHT 5
#define BALL_WIDTH 1
#define BALL_HEIGHT 1

	




typedef enum
{
    MASTER_WIN,
    PLAY_WIN,
    MENU_WIN
}Window_ID;


typedef enum
{
    BRICK_L,
    BRICK_R,
    BALL
}Object_ID;

typedef enum
{
    U,
    UR,
    R,
    DR,
    D,
    DL,
    L,
    UL
}ObjMoveDirection;




class Coordinate
{
public:
    Coordinate(unsigned int _x, unsigned int _y):m_x(_x), m_y(_y){}
    ~Coordinate(){}
    Coordinate(const Coordinate& _coordinate) : m_x(_coordinate.m_x), m_y(_coordinate.m_y){}
    unsigned int GetCoordinateX() const {return m_x;}
    unsigned int GetCoordinateY () const {return m_y;}
    bool operator==(const Coordinate& _otherCoordinate) const{return m_x == _otherCoordinate.m_x && m_y == _otherCoordinate.m_y;}
protected:

private:
    const unsigned int m_x;
    const unsigned int m_y;
};


class Pixel
{
public:
    Pixel(Coordinate _coordinate, unsigned int _pixelID) : m_pixelChar(' '), m_coordinate(_coordinate), m_pixelID(_pixelID){}
    ~Pixel(){}
    unsigned char GetCharacter() const {return m_pixelChar;}
    void SetCharacter(unsigned char _newChar){m_pixelChar = _newChar;}
    unsigned int GetX() const {return m_coordinate.GetCoordinateX();}
    unsigned int GetY() const {return m_coordinate.GetCoordinateY();}
    bool operator<(const Pixel& _otherPixel) const {return m_pixelID < _otherPixel.m_pixelID;}
    bool operator==(unsigned int _pixelID) const {return m_pixelID == _pixelID;}
    bool operator<(unsigned int _pixelID) const {return m_pixelID < _pixelID;}
    bool operator==(const Coordinate& _coordinate) const {return m_coordinate == _coordinate;}
    bool operator==(unsigned char _pixelChar) const {return m_pixelChar == _pixelChar;}
protected:

private:
    unsigned char m_pixelChar;
    const Coordinate m_coordinate;
    const unsigned int m_pixelID;
};


class Window
{
public:
    Window(Window_ID _windowID) : m_width(0), m_height(0), m_offsetX(0), m_offsetY(0), m_windowID(_windowID), m_window(0){}
    Window(unsigned int _width, unsigned int _height, unsigned int _offsetX, unsigned int _offsetY, Window_ID _windowID) :
        m_width(_width), m_height(_height), m_offsetX(_offsetX), m_offsetY(_offsetY), m_windowID(_windowID)
    {
        m_window = newwin(static_cast<int>(_height), static_cast<int>(_width), static_cast<int>(_offsetY), static_cast<int>(_offsetX));
        unsigned int curPixelID = 0;
        for (unsigned int curY = 0; curY < m_height; ++curY)
        {
            for (unsigned int curX = 0; curX < m_width; ++curX)
            {
                Coordinate curCoord(curX, curY);
                Pixel* const curPixel = new Pixel(curCoord, curPixelID);
                m_pixelContainer.insert(std::pair<unsigned int, Pixel* const>(curPixelID, curPixel));
                ++curPixelID;
            }
        }
        // }
    }
    ~Window()
    {
        if (this->m_window)
        {
            std::map<unsigned int, Pixel* const>::iterator begin = m_pixelContainer.begin();
            std::map<unsigned int, Pixel* const>::iterator end = m_pixelContainer.end();
            while(begin != end)
            {
                delete begin->second;
                m_pixelContainer.erase(begin);
                begin = m_pixelContainer.begin();
            }
            delwin(this->m_window);
        }
    }
    bool operator<(const Window& _otherWindow) const 
    {
        return m_windowID < _otherWindow.m_windowID;
    }
    bool operator==(const Window& _otherWindow) const 
    {
        return m_windowID == _otherWindow.m_windowID;
    }
    Window_ID GetWindowID() const {return m_windowID;}
    unsigned int GetWindowWidth() const {return m_width;}
    unsigned int GetWindowHeight() const {return m_height;}
    unsigned char GetPixelChar(unsigned int _pixelID)  
    {
        //TODO: throw exception of coordinate is invalid or if character is invalid
        Coordinate curCoord(0, 0);
        Pixel curPixel(curCoord, _pixelID);
        std::map<unsigned int, Pixel* const>::iterator it = m_pixelContainer.find(_pixelID);
        return it->second->GetCharacter();
    }
    void SetPixelChar(unsigned int _pixelID, unsigned char _newChar) 
    {
        //TODO: throw exception of coordinate is invalid or if character is invalid
        Coordinate curCoord(0, 0);
        Pixel curPixel(curCoord, _pixelID);
        std::map<unsigned int, Pixel* const>::iterator it = m_pixelContainer.find(_pixelID);
        // (static_cast<Pixel>(it->first).SetCharacter(_newChar);
        it->second->SetCharacter(_newChar);
    }
    void RefreshWindow()
    {
        werase(m_window);
        box(m_window, 0 , 0);
        wrefresh(m_window);
    }
protected:

private:
    const unsigned int m_width;
    const unsigned int m_height;
    const unsigned int m_offsetX;
    const unsigned int m_offsetY;
    const Window_ID m_windowID;
    std::map<unsigned int, Pixel* const> m_pixelContainer;
    WINDOW* m_window;
};


class WindowContainer
{
public:
    WindowContainer(){}
    ~WindowContainer(){}
    void AddWindow(Window& _window)
    {
        m_winContainer.insert(std::pair<Window_ID, Window&>(_window.GetWindowID(), _window));
    }
    Window& GetWindow(Window_ID _windowID)
    {
        Window tempWindow(_windowID);
        std::map<Window_ID, Window&>::iterator it = m_winContainer.find(_windowID);
        if (it ==m_winContainer.end())
        {
            int test = 1;
        }
        return (it->second);
    }
    // Window& RemoveWindow(Window_ID _windowID)
    // {

    // }
protected:

private:
    std::map<Window_ID, Window&> m_winContainer;
};

class Object_t
{
public:
    Object_t(Object_ID _objectId) : m_objectID(_objectId){}
    virtual ~Object_t(){}
    bool AddPixel(unsigned int _pixelID)
    {
        m_pixelIDContainer.insert(_pixelID);
    }
    bool RemovePixel(unsigned int _pixelID)
    {
        std::set<unsigned int>::iterator it = m_pixelIDContainer.find(_pixelID);
        if (it != m_pixelIDContainer.end())
        {
            m_pixelIDContainer.erase(_pixelID);
            return true;
        }
        return false;
    }
    bool Find(unsigned int _pixelID)
    {
        std::set<unsigned int>::iterator it = m_pixelIDContainer.find(_pixelID);
        if (it != m_pixelIDContainer.end())
        {
            return true;
        }
        return false;
    }
    // void MoveObject(ObjMoveDirection _objMoveDirection)
    // {
    //     std::set<unsigned int>::iterator begin = m_pixelIDContainer.begin();
    //     std::set<unsigned int>::iterator end = m_pixelIDContainer.end();
    //     while (begin != end)
    //     {
    //         curID = *begin;
    //         switch (_objMoveDirection)
    //         {
    //         case U:
    //             *begin = curID -
    //             break;
    //         case UR:
    //             break;
    //         case R:
    //             break;
    //         case DR:
    //             break;
    //         case D:
    //             break;
    //         case DL:
    //             break;
    //         case L:
    //             break;
    //         case UL:
    //             break;
    //         default:
    //             break;
    //         }
    //     }
    }
protected:
    std::set<unsigned int> m_pixelIDContainer;
    Object_ID m_objectID;
private:
};

class PongCursesEngine
{
public:
    PongCursesEngine();
    ~PongCursesEngine();
    void StartGame()
    {
        WINDOW* gameAreaWindow;
        WINDOW* playAreaWindow;
        int offsetx, offsety;
        struct timespec delayTime;
        delayTime.tv_sec = 0;
        delayTime.tv_nsec = 10000000;

        initscr();
        noecho();
        cbreak();
        timeout(TICKRATE);
        keypad(stdscr, TRUE);
        printw("PongCurses Test ! ! : - ) ");
        refresh();
    }
    void StopGame();
    void Quit();
protected:

private:
    WindowContainer m_windowContainer;
    std::map<Object_t*, Object_ID> m_objectContainer;
};


int main()
{
    initscr();
    noecho();
    cbreak();
    timeout(TICKRATE);
    // keypad(stdscr, TRUE);
    printw("PongCurses Test ! ! : - ) ");
    refresh();
    // unsigned int offsetx = (COLS - WINDOW_WIDTH) / 2;
    // unsigned int offsety = (LINES - WINDOW_HEIGHT) / 2;
    unsigned int offsetx = 0;
    unsigned int offsety = 1;
    Window firstWin(WINDOW_WIDTH, WINDOW_HEIGHT, offsetx, offsety, PLAY_WIN);
    WindowContainer winContainer;
    winContainer.AddWindow(firstWin);
    // Window dummy(PLAY_WIN);
    Window& firstWinPtr = winContainer.GetWindow(PLAY_WIN);
    // Window* playWinRef((winContainer.GetWindow(PLAY_WIN)));
    Object_t ball(BALL);
    Coordinate initBallCoord(10,10);
    Pixel pixel(initBallCoord, 0);

    curs_set(0);
    firstWinPtr.RefreshWindow();
    sleep(2);
    
    firstWinPtr->SetPixelChar(0, "*");
    
    firstWinPtr.RefreshWindow();
    sleep(2);
    endwin();
    return 0;
}


// typedef struct coordinate
// {
//     int x;
//     int y;
// }coordinate;

// int main() 
// {
//     WINDOW* gameAreaWindow;
//     WINDOW* playAreaWindow;
//     int offsetx, offsety;
//     struct timespec delayTime;
//     delayTime.tv_sec = 0;
//     delayTime.tv_nsec = 10000000;

//     initscr();
//     noecho();
//     cbreak();
//     timeout(TICKRATE);
//     keypad(stdscr, TRUE);
//     printw("PongCurses Test ! ! : - ) ");
//     refresh();
//     offsetx = (COLS - WINDOW_WIDTH) / 2;
//     offsety = (LINES - WINDOW_HEIGHT) / 2;
//     gameAreaWindow = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, offsety, offsetx);
//     box(gameAreaWindow, 0 , 0);
//     playAreaWindow = newwin(PLAY_AREA_HEIGHT, PLAY_AREA_WIDTH, offsety, offsetx);
//     box(playAreaWindow, 0 , 0);
//     curs_set(0);
//     for (int i=0; i < PLAY_AREA_WIDTH; ++i)
//     {
//         // wclear(playAreaWindow);
//         werase(playAreaWindow);
//         box(playAreaWindow, 0 , 0);
//         wrefresh(gameAreaWindow);
//         mvwaddch(playAreaWindow, 2, i, '*');
//         wrefresh(playAreaWindow);
//         nanosleep(&delayTime, NULL);
//     }
    
    
//     // sleep(3);
//     delwin(gameAreaWindow);
//     delwin(playAreaWindow);

//     endwin();

//     return 0;
// }
