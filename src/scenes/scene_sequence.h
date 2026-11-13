#pragma once

#include <stdint.h>

// Non-blocking command sequences. Scene start/end sequences and actions queue their commands here
// instead of using delay(); an LVGL timer sends them one after another, so the GUI stays responsive.
// Sequences queued while another one is running are appended and run afterwards, in order.

// send the command, then wait delayAfterMs before the next queued step
void sequence_add(uint16_t command, uint32_t delayAfterMs = 0);
// for Bluetooth keyboard commands: runs only after all regular steps (also those queued later), so the
// slow connection does not delay the IR commands. The connection is established without blocking;
// if it fails, the remaining Bluetooth steps are dropped.
void sequence_addBle(uint16_t command, uint32_t delayAfterMs = 0);
// additional wait after the previously queued step
void sequence_wait(uint32_t ms);
bool sequence_isRunning();
