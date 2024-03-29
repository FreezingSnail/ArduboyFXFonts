#!/bin/bash

mkdir -p examples/generated_3x5
python3 tools/textImageGeneration.py --font Fontbitmaps/Font3x5/Font_4x5.png --input examples/strings.txt --output_dir examples/generated_3x5 --greyscale --mode black

mkdir -p examples/generated_4x6
python3 tools/textImageGeneration.py --font Fontbitmaps/Font4x6/Font_5x6.png --input examples/strings.txt --output_dir examples/generated_4x6 --greyscale --mode joined

mkdir -p examples/generated_nano
python3 tools/textImageGeneration.py --font Fontbitmaps/NanoFont/NanoFont_4x3.png --input examples/strings.txt --output_dir examples/generated_nano --greyscale --mode white

mkdir -p examples/generated_TinyFont
python3 tools/textImageGeneration.py --font Fontbitmaps/TinyFont/tinyfont_5x4.png --input examples/strings.txt --output_dir examples/generated_TinyFont --greyscale --mode split

mkdir -p examples/generated_grey
python3 tools/textImageGeneration.py --font Fontbitmaps/grey/grey_6x6.png --input examples/strings.txt --output_dir examples/generated_grey --greyscale
