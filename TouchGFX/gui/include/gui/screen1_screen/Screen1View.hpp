#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <stdint.h>
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void function1();
    virtual void function2();
protected:
    void applyVisualState(uint8_t backgroundRed, uint8_t backgroundGreen, uint8_t backgroundBlue,
                          uint8_t heroRed, uint8_t heroGreen, uint8_t heroBlue,
                          uint8_t accentRed, uint8_t accentGreen, uint8_t accentBlue,
                          uint8_t statusRed, uint8_t statusGreen, uint8_t statusBlue,
                          uint8_t dividerRed, uint8_t dividerGreen, uint8_t dividerBlue,
                          uint8_t footerRed, uint8_t footerGreen, uint8_t footerBlue,
                          uint8_t greenLedRed, uint8_t greenLedGreen, uint8_t greenLedBlue,
                          uint8_t redLedRed, uint8_t redLedGreen, uint8_t redLedBlue);
};

#endif // SCREEN1VIEW_HPP
