#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <touchgfx/Callback.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }

    void startSplashTimer();
    void stopSplashTimer();
    void gotoScreen2ScreenWipeTransitionEast();

    virtual void handleTickEvent()
    {
        if (splashTimerActive)
        {
            splashTickCount++;
            if (splashTickCount >= SPLASH_DURATION_TICKS)
            {
                splashTimerActive = false;
                gotoScreen2ScreenWipeTransitionEast();
            }
        }

        model.tick();
        FrontendApplicationBase::handleTickEvent();
    }
private:
    static const uint16_t SPLASH_DURATION_TICKS = 180;
    void gotoScreen2ScreenWipeTransitionEastImpl();

    uint16_t splashTickCount;
    bool splashTimerActive;
    touchgfx::Callback<FrontendApplication> wipeTransitionCallback;
};

#endif // FRONTENDAPPLICATION_HPP
