/*
 * MIT License
 *
 * Copyright (c) 2022 Wesley Ellis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef TOMATO_FACE_H_
#define TOMATO_FACE_H_

#include "movement.h"

typedef enum {
    tomato_ready,
    tomato_run,
    // to_pause, // TODO implement pausing
} tomato_mode;

typedef enum {
    tomato_break,
    tomato_focus,
} tomato_kind;

typedef struct {
    uint32_t target_ts;
    uint32_t now_ts;
    tomato_mode mode;
    tomato_kind kind;
    uint8_t done_count;
} tomato_state_t;

void tomato_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void tomato_face_activate(movement_settings_t *settings, void *context);
bool tomato_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void tomato_face_resign(movement_settings_t *settings, void *context);
void tomato_face_label(movement_settings_t *settings, void *context, char* label, uint8_t size);

#define tomato_face ((const watch_face_t){ \
    tomato_face_setup, \
    tomato_face_activate, \
    tomato_face_loop, \
    tomato_face_resign, \
    NULL, \
    tomato_face_label, \
})

#endif // TOMATO_FACE_H_

