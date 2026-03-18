#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/Unicode.hpp>

#ifndef SIMULATOR
#include <stm32f4xx_hal.h>
#endif

Screen2View::Screen2View()
    : actionCount(0)
{
}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
    actionCount = 0;
    dynamicStatusText.setWildcard(dynamicStatusBuffer);
    updateDynamicStatus("Mode ARRET");
    applyVisualState(7, 15, 28, 18, 35, 64, 99, 186, 204, 14, 24, 43, 48, 66, 98, 10, 16, 29, 72, 82, 98, 72, 82, 98);
#ifndef SIMULATOR
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_RESET);
#endif
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::applyVisualState(uint8_t backgroundRed, uint8_t backgroundGreen, uint8_t backgroundBlue,
                                   uint8_t heroRed, uint8_t heroGreen, uint8_t heroBlue,
                                   uint8_t accentRed, uint8_t accentGreen, uint8_t accentBlue,
                                   uint8_t statusRed, uint8_t statusGreen, uint8_t statusBlue,
                                   uint8_t dividerRed, uint8_t dividerGreen, uint8_t dividerBlue,
                                   uint8_t footerRed, uint8_t footerGreen, uint8_t footerBlue,
                                   uint8_t greenLedRed, uint8_t greenLedGreen, uint8_t greenLedBlue,
                                   uint8_t redLedRed, uint8_t redLedGreen, uint8_t redLedBlue)
{
    backgroundPanel.setColor(touchgfx::Color::getColorFromRGB(backgroundRed, backgroundGreen, backgroundBlue));
    heroCard.setColor(touchgfx::Color::getColorFromRGB(heroRed, heroGreen, heroBlue));
    accentBar.setColor(touchgfx::Color::getColorFromRGB(accentRed, accentGreen, accentBlue));
    statusCard.setColor(touchgfx::Color::getColorFromRGB(statusRed, statusGreen, statusBlue));
    statusDivider.setColor(touchgfx::Color::getColorFromRGB(dividerRed, dividerGreen, dividerBlue));
    footerStrip.setColor(touchgfx::Color::getColorFromRGB(footerRed, footerGreen, footerBlue));
    greenLedIndicator.setColor(touchgfx::Color::getColorFromRGB(greenLedRed, greenLedGreen, greenLedBlue));
    redLedIndicator.setColor(touchgfx::Color::getColorFromRGB(redLedRed, redLedGreen, redLedBlue));

    backgroundPanel.invalidate();
    heroCard.invalidate();
    accentBar.invalidate();
    statusCard.invalidate();
    statusDivider.invalidate();
    footerStrip.invalidate();
    greenLedIndicator.invalidate();
    redLedIndicator.invalidate();
}

void Screen2View::updateDynamicStatus(const char* modeLabel)
{
    Unicode::snprintf(dynamicStatusBuffer, DYNAMIC_STATUS_BUFFER_SIZE, "%s %u", modeLabel, actionCount);
    dynamicStatusText.invalidate();
}

void Screen2View::function1()
{
    actionCount++;
    updateDynamicStatus("Mode ARRET");
    applyVisualState(7, 15, 28, 18, 35, 64, 99, 186, 204, 14, 24, 43, 48, 66, 98, 10, 16, 29, 72, 82, 98, 72, 82, 98);

#ifndef SIMULATOR
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_RESET);
#endif
}

void Screen2View::function2()
{
    actionCount++;
    updateDynamicStatus("Mode ALLUME");
    applyVisualState(10, 36, 52, 19, 82, 104, 124, 225, 203, 15, 52, 67, 93, 192, 208, 8, 28, 40, 86, 228, 133, 255, 107, 107);

#ifndef SIMULATOR
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_SET);
#endif
}
