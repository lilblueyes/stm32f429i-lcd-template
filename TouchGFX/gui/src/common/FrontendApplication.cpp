#include <gui/common/FrontendApplication.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap),
      splashTickCount(0),
      splashTimerActive(false)
{

}

void FrontendApplication::startSplashTimer()
{
    splashTickCount = 0;
    splashTimerActive = true;
}

void FrontendApplication::stopSplashTimer()
{
    splashTimerActive = false;
}
