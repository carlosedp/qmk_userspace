#undef DEBOUNCE
#define DEBOUNCE 10

// Set shorter TAPPING TERM for faster key response avoiding accidental holds
// For example prevent a quick hold from being registered as a tap
#undef TAPPING_TERM
#define TAPPING_TERM 140

// Define RGB matrix indices for wireless connection mode indicators
#undef HS_RGB_BLINK_INDEX_BT1
#undef HS_RGB_BLINK_INDEX_BT2
#undef HS_RGB_BLINK_INDEX_BT3
#undef HS_RGB_BLINK_INDEX_2G4
#undef HS_RGB_BLINK_INDEX_USB
#define HS_RGB_BLINK_INDEX_BT1 50
#define HS_RGB_BLINK_INDEX_BT2 49
#define HS_RGB_BLINK_INDEX_BT3 48
#define HS_RGB_BLINK_INDEX_2G4 47
#define HS_RGB_BLINK_INDEX_USB 46

// Set TYPING HEATMAP as default RGB matrix effect
#undef RGB_MATRIX_DEFAULT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP
