#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/transitions/WipeTransition.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap),
      splashTickCount(0),
      splashTimerActive(false),
      wipeTransitionCallback()
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

void FrontendApplication::gotoScreen2ScreenWipeTransitionEast()
{
    wipeTransitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotoScreen2ScreenWipeTransitionEastImpl);
    pendingScreenTransitionCallback = &wipeTransitionCallback;
}

void FrontendApplication::gotoScreen2ScreenWipeTransitionEastImpl()
{
    touchgfx::makeTransition<Screen2View, Screen2Presenter, touchgfx::WipeTransition<touchgfx::EAST>, Model>(
        &currentScreen,
        &currentPresenter,
        frontendHeap,
        &currentTransition,
        &model);
}
