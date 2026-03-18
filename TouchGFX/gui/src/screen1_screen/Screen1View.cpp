#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    application().startSplashTimer();
}

void Screen1View::tearDownScreen()
{
    application().stopSplashTimer();
    Screen1ViewBase::tearDownScreen();
}
