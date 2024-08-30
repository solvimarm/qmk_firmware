// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
//#include "keymap_icelandic.h"
//#include "oneshot.h"
//#include "swapper.h"

#include "oneshot.h"
#include "swapper.h"
#include "keymap_icelandic.h"


// define window management
#define WM_1 LGUI(KC_1)
#define WM_2 LGUI(KC_2)
#define WM_3 LGUI(KC_3)
#define WM_4 LGUI(KC_4)
#define WM_5 LGUI(KC_5)
#define WM_6 LGUI(KC_6)

#define TB_UP C(KC_TAB)
#define TB_DN RCS(KC_TAB)

#define W_NXT G(IS_K)
#define W_PRV G(IS_J)

#define LSENT SFT_T(KC_ENT)

// layers
#define DEF MO(_DEF)
#define NAV MO(_NAV)
#define SYM MO(_SYM)
#define NUM MO(_NUM)

#define VOL_U KC_VOLU
#define VOL_D KC_VOLD


enum layers {
    _DEF,
    _NAV,
    _NUM,
    _SYM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (alt-tab)
    SW_TAB,  // Switch to next browser tab    (ctrl-tab)
};



/*
#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEF] = LAYOUT(
    IS_Q,    IS_W,    IS_E,    IS_R,    IS_T,            IS_Y,    IS_U,  IS_I,    IS_O,   IS_P,
    IS_A,    IS_S,    IS_D,    IS_F,    IS_G,            IS_H,    IS_J,  IS_K,    IS_L,   IS_ETH,
    IS_Z,    IS_X,    IS_C,    IS_V,    IS_B,            IS_N,    IS_M,  IS_COMM, IS_DOT, IS_THRN,
                                NAV,  KC_SPC,            KC_LSFT, SYM
  ),

  [_SYM] = LAYOUT(
/*
    IS_1,    IS_2,    IS_3,    IS_4,    IS_5,            IS_6,    IS_7,    IS_8,    IS_9,    IS_0,
    QK_GESC, IS_HOME, IS_PGDN, IS_PGUP, IS_END,          IS_LEFT, IS_DOWN, IS_UP,   IS_RGHT, IS_QUOT,
    IS_TRNS, IS_TRNS, IS_TRNS, IS_BTN1, IS_BTN2,         IS_MS_L, IS_MS_D, IS_MS_U, IS_MS_R, IS_ENT,
                                    IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS
*/
        IS_LABK ,IS_QUOT ,IS_DQUO  ,IS_PERC ,IS_LPRN ,           IS_RPRN ,IS_ASTR ,IS_UNDS ,IS_AE   ,IS_ODIA  ,
        IS_TILD ,IS_AT   ,IS_HASH  ,IS_DLR ,IS_LBRC ,            IS_RBRC ,KC_ENTER ,OS_CTRL ,OS_CMD  ,IS_ACUT ,
        IS_CIRC ,IS_PIPE ,IS_BSLS  ,IS_SLSH ,IS_LCBR ,           IS_RCBR ,IS_PLUS ,IS_EQL ,IS_MINS  ,IS_QUES  ,
                                    NUM     ,KC_DEL ,            KC_LSFT ,_______
  ),
    [_NAV] = LAYOUT(
        KC_ESC  ,KC_NO   ,TB_UP   ,TB_DN   ,IS_EXLM   ,           KC_NO   ,W_PRV    ,W_NXT    ,VOL_D   ,VOL_U   ,
        KC_TAB  ,OS_CMD  ,OS_CTRL ,OS_SHFT ,IS_AMPR   ,           KC_LEFT  ,KC_DOWN ,KC_UP   ,KC_RIGHT,_______,
        WM_1    ,WM_2    ,WM_3    ,WM_4    ,WM_5    ,           KC_NO   ,KC_NO     ,KC_NO   ,KC_NO   ,_______,
                                   _______ ,KC_SPC  ,           KC_BSPC  ,NUM
    ),
    [_NUM] = LAYOUT(
        KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,             KC_6   , KC_7,    KC_8,    KC_9,    KC_0,
        _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,
                                   _______, _______,             _______, _______
    ),
/*
  [2] = LAYOUT(
    IS_F1,   IS_F2,   IS_F3,   IS_F4,   IS_F5,           IS_F6,   IS_F7,   IS_F8,   IS_F9,   IS_F10,
    IS_TAB,  IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS,         IS_MINS, IS_EQL,  IS_LBRC, IS_RBRC, IS_PIPE,
    IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS,         IS_UNDS, IS_PLUS, IS_TRNS, IS_TRNS, QK_BOOT,
                                    IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS
  ),

  [3] = LAYOUT(
    IS_TRNS,  IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS,         IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS,
    IS_TRNS,  IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS,         IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS,
    IS_TRNS,  IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS,         IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS,
                                    IS_TRNS, IS_TRNS, IS_TRNS, IS_TRNS
  ),
  */
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case SYM:
    case NAV:
        return true;
    default:
        return false;
    }
};
bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case SYM:
    case NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
};

bool sw_win_active = false;
bool sw_tab_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;


void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code(mod);
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                *state = os_up_queued;
                break;
            case os_down_used:
                // If we did use the mod while trigger was held, unregister it.
                *state = os_up_unqueued;
                unregister_code(mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
            }
        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    break;
                case os_up_queued:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t reverse_key,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active
        && keycode != reverse_key
        && keycode != KC_LEFT
        && keycode != KC_RIGHT
    ) {
        unregister_code(cmdish);
        *active = false;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT,
        keycode, record
    );
    update_swapper(
        &sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LGUI, OS_CMD,
        keycode, record
    );

    return true;
};


