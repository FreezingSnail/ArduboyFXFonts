#pragma once

/**** FX data header generated by fxdata-build.py tool version 1.15 ****/

using uint24_t = __uint24;

// Initialize FX hardware using  FX::begin(FX_DATA_PAGE); in the setup() function.

constexpr uint16_t FX_DATA_PAGE  = 0xfff8;
constexpr uint24_t FX_DATA_BYTES = 2040;

constexpr uint24_t tinyFont = 0x000000;
constexpr uint16_t tinyFontWidth  = 4;
constexpr uint16_t tinyFontHeight = 4;
constexpr uint8_t  tinyFontFrames = 124;

constexpr uint24_t arduboyFont = 0x0001F4;
constexpr uint16_t arduboyFontWidth  = 6;
constexpr uint16_t arduboyFontHeight = 8;
constexpr uint16_t  arduboyFontFrames = 256;

