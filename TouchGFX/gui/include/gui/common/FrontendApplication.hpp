#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }

    void startSplashTimer();
    void stopSplashTimer();

    virtual void handleTickEvent()
    {
        if (splashTimerActive)
        {
            splashTickCount++;
            if (splashTickCount >= SPLASH_DURATION_TICKS)
            {
                splashTimerActive = false;
                gotoScreen2ScreenBlockTransition();
            }
        }

        model.tick();
        FrontendApplicationBase::handleTickEvent();
    }
private:
    static const uint16_t SPLASH_DURATION_TICKS = 300;

    uint16_t splashTickCount;
    bool splashTimerActive;
};

#endif // FRONTENDAPPLICATION_HPP
