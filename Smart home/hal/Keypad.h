/*
 * Keypad.h
 *
 * Created: 4/20/2023 4:33:58 AM
 *  Author: Win-0
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define Keybad_rows     4
#define Keybad_columns  4
#define Keybad_columns_port DIO_PORTD
#define Keybad_rows_port    DIO_PORTD
#define Keybad_row0         PIN_0
#define Keybad_row1         PIN_1
#define Keybad_row2         PIN_2
#define Keybad_row3         PIN_3
#define Keybad_col0         PIN_4
#define Keybad_col1         PIN_5
#define Keybad_col2         PIN_6
#define Keybad_col3         PIN_7
#define Keybad_keys   {{'7','8','9','/'},\
                       {'4','5','6','*'},\
                       {'1','2','3','-'},\
                       {'o','0','=','+'}}
#define key_Not_pressed   0xff

/*************************Funcation**************/
char Keybad_init();
char Keybad_get_value(char *ptr);
#endif /* KEYPAD_H_ */