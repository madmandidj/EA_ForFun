// maybe can help: https://invisible-island.net/ncurses/ncurses-intro.html

#include <curses.h>
//#include <unistd.h>
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




class Coordinate
{
public:
    Coordinate(unsigned int _x, unsigned int _y, unsigned int _coordinateID)
    {
        m_x = _x;
        m_y = _y;
    }
    ~Coordinate(){}
    unsigned int GetCoordinateX()
    {
        return m_x;
    }
    void SetCoordinateX(unsigned int _newX);
    {
        m_x = _newX;
    }
    unsigned int GetCoordinateY()
    {
        return m_y;
    }
    void SetCoordinateY(unsigned int _newY)
    {
        m_y = _newY;
    }
    bool operator==(const Coordinate& _otherCoordinate)
    {
        return m_x == _otherCoordinate.m_x && m_y == _otherCoordinate.m_y;
    }
    bool operator<(const Coordinate& _otherCoordinate)
    {
        unsigned int 
    }
protected:

private:
    unsigned int m_x;
    unsigned int m_y;
    unsigned int m_coordinateID;
};


class Pixel
{
public:
    Pixel(Coordinate _coordinate);
    ~Pixel();
    unsigned char GetCharacter() const;
    void SetCharacter(unsigned char _newChar);
    bool operator==(const Pixel& _otherPixel) const;
    bool operator<(const Pixel& _otherPixel) const;
    bool operator==(const Coordinate& _otherCoordinate) const;
    bool operator==(unsigned char _otherChar) const;
    
protected:

private:
    unsigned char m_pixelChar;
    Coordinate m_coordinate;
};


class Window
{
public:
    Window(unsigned int _width, unsigned int _height, Window_ID _windowID);
    ~Window();
    unsigned int GetWindowWidth() const;
    unsigned int GetWindowHeight() const;
    Pixel& GetPixel() const;
    void RefreshWindow();
protected:

private:
    unsigned int m_width;
    unsigned int m_height;
    std::map<Pixel, Coordinate> m_pixelContainer;
    Window_ID m_windowID;
    WINDOW* m_window
};


class WindowContainer
{
public:
    WindowContainer();
    ~WindowContainer();
    void AddWindow(const Window _window);
    Window& GetWindow();
    Window& RemoveWindow();
protected:

private:
    std::map<Window, Window_ID> m_winContainer;
};

class Object_t
{
public:
    Object_t(Object_ID _objectId);
    virtual ~Object_t();
    bool Add(const Coordinate& _coordToAdd);
    bool Remove(const Coordinate& _coordToRemove);
    bool Find(const Coordinate& _coordToFind);
protected:
    std::set<Coordinate> m_cooordinateContainer;
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

}


typedef struct coordinate
{
    int x;
    int y;
}coordinate;

int main() 
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
    offsetx = (COLS - WINDOW_WIDTH) / 2;
    offsety = (LINES - WINDOW_HEIGHT) / 2;
    gameAreaWindow = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, offsety, offsetx);
    box(gameAreaWindow, 0 , 0);
    playAreaWindow = newwin(PLAY_AREA_HEIGHT, PLAY_AREA_WIDTH, offsety, offsetx);
    box(playAreaWindow, 0 , 0);
    curs_set(0);
    for (int i=0; i < PLAY_AREA_WIDTH; ++i)
    {
        // wclear(playAreaWindow);
        werase(playAreaWindow);
        box(playAreaWindow, 0 , 0);
        wrefresh(gameAreaWindow);
        mvwaddch(playAreaWindow, 2, i, '*');
        wrefresh(playAreaWindow);
        nanosleep(&delayTime, NULL);
    }
    
    
    // sleep(3);
    delwin(gameAreaWindow);
    delwin(playAreaWindow);

    endwin();

    return 0;
}
