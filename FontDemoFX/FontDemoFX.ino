#include "fxdata/fxdata.h"
#include <Arduboy2.h>
#include <ArduboyFX.h>

Arduboy2Base arduboy;
uint8_t page;

#define FONTEND 123

void setup() {
    arduboy.begin();
    FX::begin(FX_DATA_PAGE);      // Initialize FX flash chip
    FX::setCursorRange(0, 128);   // set cursor left and wrap positions
}
// demo text stored in ram.
uint8_t normalFontHeader[] = "Arduboy 6x8 Font";

static void drawArduboyFont(uint8_t page) {
    FX::setFont(arduboyFont, dcmNormal);
    FX::drawString(normalFontHeader);
    uint8_t c = 139 * page;
    for (uint8_t j = 0; j < 16; j++) {
        for (int8_t i = 0; i < 21; i++) {
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
    for (uint8_t j = 0; j < 7; j++) {
        for (int8_t i = 0; i < 21; i++) {
            FX::drawBitmap(0 + (i * 6), 9 + (8 * j), tinyFont, c, dbmNormal);
            c++;
            if (c == FONTEND) {
                return;
            }
        }
    }
}

uint8_t f4x6Header[] = "Filmote's 4x6 Font";

static void draw4x6Font() {
    FX::setFont(f4x6, dcmNormal);
    FX::drawString(f4x6Header);
    uint8_t c = 0;
    for (uint8_t j = 0; j < 7; j++) {
        for (int8_t i = 0; i < 21; i++) {
            FX::drawBitmap(0 + (i * 6), 9 + (8 * j), f4x6, c, dbmNormal);
            c++;
            if (c == FONTEND) {
                return;
            }
        }
    }
}

uint8_t f3x5Header[] = "Filmote's 3x5 Font";

static void draw3x5Font() {
    FX::setFont(f3x5, dcmNormal);
    FX::drawString(f3x5Header);
    uint8_t c = 0;
    for (uint8_t j = 0; j < 7; j++) {
        for (int8_t i = 0; i < 21; i++) {
            FX::drawBitmap(0 + (i * 6), 9 + (8 * j), f3x5, c, dbmNormal);
            c++;
            if (c == FONTEND) {
                return;
            }
        }
    }
}

uint8_t nanoHeader[] = "Zephs's 3xs Font";

static void drawNanoFont() {
    FX::setFont(nano, dcmNormal);
    FX::drawString(nanoHeader);
    uint8_t c = 0;
    for (uint8_t j = 0; j < 7; j++) {
        for (int8_t i = 0; i < 21; i++) {
            FX::drawBitmap(0 + (i * 6), 9 + (8 * j), nano, c, dbmNormal);
            c++;
            if (c == FONTEND) {
                return;
            }
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
    case 3:
        draw4x6Font();
        break;
    case 4:
        draw3x5Font();
        break;
    case 5:
        drawNanoFont();
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