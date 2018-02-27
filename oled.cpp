#include "Adafruit_SSD1306.h"

namespace OLED {
    /**
         * Initialize the OLED display
         * 
         */

    //% blockId=oled_init block="initialize" color=190 weight=100 icon="\uf1ec"
    void init()
    {

        // Reset Display
        uBit.io.P0.setDigitalValue(1);
        uBit.sleep(10);
        uBit.io.P0.setDigitalValue(0);
        uBit.sleep(10);
        uBit.io.P0.setDigitalValue(1);
        uBit.sleep(100);

        // Init sequence
        ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
        ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
        ssd1306_command(0x80);                                  // the suggested ratio 0x80

        ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
        ssd1306_command(SSD1306_LCDHEIGHT - 1);

        ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
        ssd1306_command(0x0);                                   // no offset
        ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
        ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
        ssd1306_command(0x14);

        ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
        ssd1306_command(0x00);                                  // 0x0 act like ks0108
        ssd1306_command(SSD1306_SEGREMAP | 0x1);
        ssd1306_command(SSD1306_COMSCANDEC);

        ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
        ssd1306_command(0x12);
        ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
        ssd1306_command(0xCF);

        ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
        ssd1306_command(0xF1);
        ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
        ssd1306_command(0x40);
        ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
        ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6

        ssd1306_command(SSD1306_DEACTIVATE_SCROLL);

        ssd1306_command(SSD1306_DISPLAYON);//--turn on oled panel
    }
}