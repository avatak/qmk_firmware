#pragma once


#ifdef AUDIO_ENABLE

#endif

#ifndef TAPPING_TERM
#   define TAPPING_TERM 150
#endif
#ifndef TAPPING_TOGGLE
#   define TAPPING_TOGGLE 2
#endif


// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
