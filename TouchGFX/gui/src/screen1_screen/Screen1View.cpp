#include <gui/screen1_screen/Screen1View.hpp>

#ifndef SIMULATOR
#include <stm32f4xx_hal.h>
#endif

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::function1()
{
#ifndef SIMULATOR
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_Delay(100);
#else
    // Code de simulation (facultatif, peut être vide)
#endif
}

void Screen1View::function2()
{
#ifndef SIMULATOR
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_SET);
    HAL_Delay(100);
#else
    // Code de simulation (facultatif, peut être vide)
#endif
}
