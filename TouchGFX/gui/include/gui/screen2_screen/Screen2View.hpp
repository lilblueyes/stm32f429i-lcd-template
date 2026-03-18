#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <stdint.h>
#include <touchgfx/Unicode.hpp>
#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void function1();
    virtual void function2();

protected:
    static const uint16_t DYNAMIC_STATUS_BUFFER_SIZE = 32;

    void applyVisualState(uint8_t backgroundRed, uint8_t backgroundGreen, uint8_t backgroundBlue,
                          uint8_t heroRed, uint8_t heroGreen, uint8_t heroBlue,
                          uint8_t accentRed, uint8_t accentGreen, uint8_t accentBlue,
                          uint8_t statusRed, uint8_t statusGreen, uint8_t statusBlue,
                          uint8_t dividerRed, uint8_t dividerGreen, uint8_t dividerBlue,
                          uint8_t footerRed, uint8_t footerGreen, uint8_t footerBlue,
                          uint8_t greenLedRed, uint8_t greenLedGreen, uint8_t greenLedBlue,
                          uint8_t redLedRed, uint8_t redLedGreen, uint8_t redLedBlue);
    void updateDynamicStatus(const char* modeLabel);

    touchgfx::Unicode::UnicodeChar dynamicStatusBuffer[DYNAMIC_STATUS_BUFFER_SIZE];
    uint16_t actionCount;
};

#endif // SCREEN2VIEW_HPP
