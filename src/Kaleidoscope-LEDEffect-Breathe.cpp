/* Kaleidoscope-LEDEffect-Breathe - A breathing effect on the LEDs, for Kaleidoscope.
 * Copyright (C) 2017-2018  Keyboard.io, Inc.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Kaleidoscope-LEDEffect-Breathe.h"
#define UPDATE_INTERVAL 50  // milliseconds between two LED updates to avoid overloading; 20 fps

namespace kaleidoscope {
void LEDBreatheEffect::update(void) {
  uint16_t now = millis();
  if ((now - last_update) < UPDATE_INTERVAL)
    return;
  last_update = now;

  cRGB color = breath_compute(hue, saturation);
  ::LEDControl.set_all_leds_to(color);
}
}

kaleidoscope::LEDBreatheEffect LEDBreatheEffect;
