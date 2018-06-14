#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define QWERTY 0

#define KC_ KC_TRNS
#define KC_SSPC ALGR_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,GRV ,     EQL , 6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     RBRC, Q  , W  , E  , R  , T  ,ENT ,     ENT , Y  , U  , I  , O  , P  ,LBRC,
  //|----+----+----+----+----+----|    |    |    |----+----+----+----+----+----|
     TAB , A  , S  , D  , F  , G  ,/*--|    |---*/ H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|    |    |    |----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  ,DEL ,     BSPC, N  , M  ,COMM,DOT ,SLSH,BSLS,
  //`----+----+----+----+----+----+----|    |----+----+----+----+----+----+----'
               LGUI,APP ,LALT,SSPC,LSFT,     RSFT,SSPC,RCTL,RALT,RGUI
  //          `----+----+----+----+----'    `----+----+----+----+----'
  ),

};
