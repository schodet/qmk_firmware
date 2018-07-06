#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

extern keymap_config_t keymap_config;

enum {
    BEPO, // Base BÉPO layer, a french ergonomic layout.
    NAV,  // Navigation / Alt Gr.
    NAVO, // Navigation only, locked.
    NUM,  // Numeric and lower.
    LOW,  // Lower.
    FUN,  // Function.
};

#define ___ KC_TRNS
#define NAV_SPC LT(NAV, KC_SPC)
#define CTL_SPC MT(MOD_LCTL, KC_SPC)
#define C LCTL
#define KC_GTAB LGUI(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BEPO] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------.
  //|  ESC  |   "   |   «   |   »   |   (   |   )   |   $   |    |   %   |   @   |   +   |   -   |   /   |   *   |   =   |
     KC_ESC ,BP_DQOT,BP_LGIL,BP_RGIL,BP_LPRN,BP_RPRN,BP_DLR ,     BP_PERC, BP_AT ,BP_PLUS,BP_MINS,BP_SLSH,BP_ASTR,BP_EQL ,
  //|-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------|
  //|   w   |   b   |   é   |   p   |   o   |   è   |       |    |       |  d^   |   v   |   d   |   l   |   j   |   z   |
      BP_W  , BP_B  ,BP_ECUT, BP_P  , BP_O  ,BP_EGRV,KC_ENT ,     KC_ENT ,BP_DCRC, BP_V  , BP_D  , BP_L  , BP_J  , BP_Z  ,
  //|-------+-------+-------+-------+-------+-------| Enter |    | Enter |-------+-------+-------+-------+-------+-------|
  //|  Tab  |   a   |   u   |   i   |   e   |   ,   |       |    |       |   c   |   t   |   s   |   r   |   n   |   m   |
     KC_TAB , BP_A  , BP_U  , BP_I  , BP_E  ,BP_COMM,/*-----|    |------*/ BP_C  , BP_T  , BP_S  , BP_R  , BP_N  , BP_M  ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|   ê   |   à   |   y   |   x   |   .   |   k   | G-Tab |    |  <--  |   '   |   q   |   g   |   h   |   f   |   ç   |
     BP_ECRC,BP_AGRV, BP_Y  , BP_X  ,BP_DOT , BP_K  ,KC_GTAB,     KC_BSPC,BP_APOS, BP_Q  , BP_G  , BP_H  , BP_F  ,BP_CCED,
  //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
  //                |  Gui  |  Alt  | Lower |SpaceCt| Shift |    | Shift |SpaceNa| Lower |  Num  |  Gui  |
                     KC_LGUI,KC_LALT,MO(LOW),CTL_SPC,KC_LSFT,     KC_RSFT,NAV_SPC,MO(LOW),MO(NUM),KC_RGUI
  //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
  ),

  [NAV] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------.
  //|       |   —   |   <   |   >   |   [   |   ]   |   –   |    |   ‰   |   ^   |   ±   |   −   |   ÷   |   ×   |   ≠   |
       ___  ,BP_MDSH,BP_LESS,BP_GRTR,BP_LBRC,BP_RBRC,BP_NDSH,     BP_PMIL,BP_CIRC,BP_PSMS,BP_MMNS,BP_OBEL,BP_TIMS,BP_DIFF,
  //|-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------|
  //|  d˘   |   |   |  d´   |   &   |   œ   |  d`   |       |    |       |  Del  | PgUp  |  Up   | PgDn  |       |       |
     BP_DBRV,BP_PIPE,BP_DACT,BP_AMPR, BP_OE ,BP_DGRV,  ___  ,       ___  ,KC_DEL ,KC_PGUP, KC_UP ,KC_PGDN, KC_NO , KC_NO ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //| CAPS  |   æ   |   ù   |  d¨   |   €   |   ’   |       |    |       |  <--  | Left  | Down  | Right | Enter |       |
     KC_CAPS, BP_AE ,BP_UGRV,BP_DTRM,BP_EURO,BP_TAPO,/*-----|    |------*/KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT , KC_NO ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|   /   |   \   |   {   |   }   |   …   |   ~   |       |    |       |  ^W   | Home  |d Greek|  End  | Insert|       |
     BP_NUSL,BP_BSLS,BP_LCBR,BP_RCBR,BP_ELPS,BP_TILD,  ___  ,       ___  ,C(BP_W),KC_HOME,BP_DGRK,KC_END ,KC_INS , KC_NO ,
  //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
  //                |       | AltGr |       |   _   |       |    |       |       |       |  Fn   |NavLock|
                       ___  ,BP_ALGR,  ___  ,BP_UNDS,  ___  ,       ___  ,  ___  ,  ___  ,MO(FUN),TO(NAVO)
  //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
  ),

  [NAVO] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------.
  //|UnLock |       |       |       |       |       |       |    |       |       |       |       |       |       |       |
    TO(BEPO),  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,
  //|-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------|
  //|       |       |       |       |       |       |       |    |       |  Del  | PgUp  |  Up   | PgDn  |       |       |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,KC_DEL ,KC_PGUP, KC_UP ,KC_PGDN, KC_NO , KC_NO ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|       |       |       |       |       |       |       |    |       |  <--  | Left  | Down  | Right | Enter |       |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,/*-----|    |------*/KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT , KC_NO ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|       |       |       |       |       |       |       |    |       |       | Home  |       |  End  | Insert|       |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  , KC_NO ,KC_HOME, KC_NO ,KC_END ,KC_INS , KC_NO ,
  //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
  //                |       |       |       |       |       |    |       |       |       |       |       |
                       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___
  //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
  ),

  [NUM] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------.
  //|       |       |       |       |       |       |       |    |       |       |   +   |   -   |   /   |   *   |   =   |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,
  //|-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------|
  //|   %   |   1   |   2   |   3   |   4   |   5   |       |    |       |   6   |   7   |   8   |   9   |   0   |       |
     BP_PERC, BP_1  , BP_2  , BP_3  , BP_4  , BP_5  ,  ___  ,       ___  , BP_6  , BP_7  , BP_8  , BP_9  , BP_0  ,  ___  ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|   $   |   "   |   «   |   »   |   (   |   )   |       |    |       |  <--  |   4   |   5   |   6   | Enter |       |
     BP_DLR ,BP_DQOT,BP_LGIL,BP_RGIL,BP_LPRN,BP_RPRN,/*-----|    |------*/KC_BSPC, BP_4  , BP_5  , BP_6  ,KC_ENT ,  ___  ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|   =   |   *   |   /   |   -   |   +   |   @   |       |    |       |       |   1   |   2   |   3   |   ,   |       |
     BP_EQL ,BP_ASTR,BP_SLSH,BP_MINS,BP_PLUS, BP_AT ,  ___  ,       ___  ,  ___  , BP_1  , BP_2  , BP_3  ,BP_COMM,  ___  ,
  //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
  //                |       |       |       |       |       |    |       |       |   0   |       |   .   |
                       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  , BP_0  ,  ___  ,BP_DOT
  //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
  ),

  [LOW] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------.
  //|       |       |       |       |       |       |       |    |       |       |       |       |       |       |       |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,
  //|-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------|
  //|  Esc  |   1   |   2   |   3   |   4   |   5   |       |    |       |   6   |   7   |   8   |   9   |   0   |   %   |
     KC_ESC , BP_1  , BP_2  , BP_3  , BP_4  , BP_5  ,  ___  ,       ___  , BP_6  , BP_7  , BP_8  , BP_9  , BP_0  ,BP_PERC,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|   $   |   "   |   «   |   »   |   (   |   )   |       |    |       |   @   |   +   |   -   |   /   |   *   |   =   |
     BP_DLR ,BP_DQOT,BP_LGIL,BP_RGIL,BP_LPRN,BP_RPRN,/*-----|    |------*/ BP_AT ,BP_PLUS,BP_MINS,BP_SLSH,BP_ASTR,BP_EQL ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|   –   |   —   |   <   |   >   |   [   |   ]   |       |    |       |   ^   |   ±   |   −   |   ÷   |   ×   |   ≠   |
     BP_NDSH,BP_MDSH,BP_LESS,BP_GRTR,BP_LBRC,BP_RBRC,  ___  ,       ___  ,BP_CIRC,BP_PSMS,BP_MMNS,BP_OBEL,BP_TIMS,BP_DIFF,
  //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
  //                |       |       |       |       |       |    |       | AltGr |       |       |       |
                       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,BP_ALGR,  ___  ,  ___  ,  ___
  //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
  ),

  [FUN] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------.
  //| Reset |  F1   |  F2   |  F3   |  F4   |  F5   |       |    |       |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |
      RESET , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,  ___  ,       ___  , KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
  //|-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------|
  //|       |       |       |       |       |       |       |    |       |       |       |       |       |       |  F12  |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,KC_F12 ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|       |       |       |       |       |       |       |    |       |       |       |       |       |       | Pause |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,/*-----|    |------*/  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,KC_PAUS,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|       |       |       |       |       |       |       |    |       |       |       |       |       |       |PrntScr|
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,KC_PSCR,
  //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
  //                |  App  |       |       |       |       |    |       |       |       |       |       |
                     KC_APP ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___
  //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
  ),

#if 0
  [] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------.
  //|       |       |       |       |       |       |       |    |       |       |       |       |       |       |       |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,
  //|-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------|
  //|       |       |       |       |       |       |       |    |       |       |       |       |       |       |       |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|       |       |       |       |       |       |       |    |       |       |       |       |       |       |       |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,/*-----|    |------*/  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,
  //|-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  //|       |       |       |       |       |       |       |    |       |       |       |       |       |       |       |
       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,  ___  ,
  //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
  //                |       |       |       |       |       |    |       |       |       |       |       |
                       ___  ,  ___  ,  ___  ,  ___  ,  ___  ,       ___  ,  ___  ,  ___  ,  ___  ,  ___
  //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
  ),
#endif
};
