#include "fxdata/fxdata.h"
#include <Arduboy2.h>
#include <ArduboyFX.h>

Arduboy2Base arduboy;
uint8_t page;

void setup() {
    arduboy.begin();
    FX::begin(FX_DATA_PAGE);      // Initialize FX flash chip
    FX::setCursorRange(0, 126);   // set cursor left and wrap positions
}
// demo text stored in ram.
uint8_t normalFontHeader[] = "Arduboy 6x8 Font";

static void drawArduboyFont(uint8_t page) {
    FX::setFont(arduboyFont, dcmNormal);
    FX::drawString(normalFontHeader);
    uint8_t c = 139 * page;
    for (uint8_t j = 0; j < 16; j++) {
        for (int8_t i = 0; i < 20; i++) {
            FX::drawBitmap(0 + (i * 6), 9 + (8 * j), arduboyFont, c, dbmNormal);
            c++;
            if (c == 255) {
                return;
            }
        }
    }
}

uint8_t tinyFontHeader[] = "TinyFont 4x4 Font";

static void drawTinyFont() {
    FX::setFont(tinyFont, dcmNormal);
    FX::drawString(tinyFontHeader);
    uint8_t c = 0;
    for (uint8_t j = 0; j < 16; j++) {
        for (int8_t i = 0; i < 18; i++) {
            FX::drawBitmap(0 + (i * 6), 9 + (8 * j), tinyFont, c, dbmNormal);
            c++;
        }
    }
}

void loop() {
    if (!(arduboy.nextFrame()))
        return;
    arduboy.pollButtons();
    FX::setCursor(0, 0);

    switch (page) {
    case 0:
    case 1:
        drawArduboyFont(page);
        break;
    case 2:
        drawTinyFont();
        break;
    }

    if (Arduboy2::justPressed(DOWN_BUTTON)) {
        page++;
    }

    if (Arduboy2::justPressed(UP_BUTTON)) {
        page--;
    }

    FX::display(CLEAR_BUFFER);
}