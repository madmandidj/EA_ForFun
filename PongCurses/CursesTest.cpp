#include <ncurses.h>
#include <unistd.h>
#include <time.h>
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
    printw("PieceOfCakeSnake v. 1.0  -  Press x to quit...");
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
    Coordinate(unsigned int _x, unsigned int _y);
    ~Coordinate();
    unsigned int GetCoordinateX();
    void SetCoordinateX(unsigned int _newX);
    unsigned int GetCoordinateY();
    void SetCoordinateY(unsigned int _newY);
    bool operator==(const Coordinate& _otherCoordinate);
    bool operator<(const Coordinate& _otherCoordinate);
protected:

private:
    unsigned int m_x;
    unsigned int m_y;
};


class Pixel
{
public:
    Pixel(Coordinate _coordinate);
    ~Pixel();
    unsigned char GetCharacter() const;
    SetCharacter(unsigned char _newChar);
    operator==(const Pixel& _otherPixel) const;
    operator<(const Pixel& _otherPixel) const;
    operator==(const Coordinate& _otherCoordinate) const;
    operator==(unsigned char _otherChar) const;
    
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
    GetWindowHeight() const;
    Pixel& GetPixel() const;
protected:

private:
    unsigned int m_width;
    unsigned int m_height;
    PixelContainer m_pixelContainer;
    Window_ID m_windowID;
};

/*
class GraphicsEngine
{
public:
    GraphicsEngine();
    ~GraphicsEngine();
    AddWindow();
    RemoveWindow();
    RefreshWindow();
    
protected:

private:
    WindowContainer m_winContainer;
};

*/

