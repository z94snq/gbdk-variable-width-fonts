#include <gb/gb.h>
#include "vwf.h"
#include "vwf_font.h"
#include "vwf_font_bold.h"
#include "vwf_font_ru.h"

void main(void) {
    // Clear the background and show it
    fill_bkg_rect(0, 0, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT, 0x00u);
    SHOW_BKG;

    vwf_set_destination(VWF_RENDER_BKG);

    // Load fonts into slots 0, 1 and 2
    vwf_load_font(0, vwf_font, BANK(vwf_font));
    vwf_load_font(1, vwf_font_bold, BANK(vwf_font_bold));
    vwf_load_font(2, font_ru, BANK(font_ru));
    vwf_activate_font(0);

    // Drawn with the active font (slot 0)
    vwf_draw_text(1, 1, 1, "Hello, variable-width\nfont world!");

    // \x01<n> switches font mid-string; literals are split so \x doesn't absorb the next word's hex digits
    vwf_draw_text(1, 4, vwf_next_tile(), "\x01\x00" "Regular " "\x01\x01" "Bold " "\x01\x02" "Cyrillic" "\x01\x00" "\n\nZ94SNQ");
}
