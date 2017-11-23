/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:03:34 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/25 16:03:36 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef KEYS_H
# define KEYS_H

/*
** Max value of keys supported
*/

# define MAX_KC 280
# define MAX_MOUSE 6

/* 
** Macros for manipulating the value of keys in a t_key.
** These are here so that the implementation of the backend can be changed
** without changing any code
*/

# define SET_KEY(store, key) (store[key] = 1)
# define CLR_KEY(store, key) (store[key] = 0)
# define TOG_KEY(store, key) (store[key] = (store[key]) ? (0) : (1))
# define GET_KEY(store, key) (!!store[key])

/*
** Convenience defines for key codes
*/

/*
** LETTERS
*/

# define KEY_A 0
# define KEY_B 11
# define KEY_C 8
# define KEY_D 2
# define KEY_E 14
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_I 34
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_M 46
# define KEY_N 45
# define KEY_O 31
# define KEY_P 35
# define KEY_Q 12
# define KEY_R 15
# define KEY_S 1
# define KEY_T 17
# define KEY_U 32
# define KEY_V 9
# define KEY_W 13
# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6

/*
** NUMBERS
*/

# define KEY_ZERO 29
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_FIVE 23
# define KEY_SIX 22
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_NINE 25

/*
** PUNCTUATION
*/

# define KEY_ACCENT 50
# define KEY_DASH 27
# define KEY_EQUAL 24
# define KEY_FSLASH 44
# define KEY_BSLASH 42
# define KEY_LBRCK 33
# define KEY_RBRCK 30
# define KEY_SEMIC 41
# define KEY_APOST 39
# define KEY_COMMA 43
# define KEY_PERIOD 47

/*
** WHITESPACE
*/

# define KEY_TAB 48
# define KEY_SPC 49
# define KEY_RET 36

/*
** MODIFIER
*/

# define KEY_LSHIFT 257
# define KEY_RSHIFT 258
# define KEY_CAPSLOCK 272
# define KEY_LCTRL 256
# define KEY_RCTRL 269
# define KEY_LOPT 261
# define KEY_ROPT 262
# define KEY_LCMD 259
# define KEY_RCMD 260
# define KEY_FN 279

/*
** SPECIAL
*/

# define KEY_ESC 53
# define KEY_BSPC 51
# define KEY_HOME 115
# define KEY_END 119
# define KEY_PGUP 116
# define KEY_PGDN 121
# define KEY_DEL 117

/*
** ARROW
*/

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/*
** NUMPAD
*/

# define KEY_NUM_ZERO 82
# define KEY_NUM_ONE 83
# define KEY_NUM_TWO 84
# define KEY_NUM_THREE 85
# define KEY_NUM_FOUR 86
# define KEY_NUM_FIVE 87
# define KEY_NUM_SIX 88
# define KEY_NUM_SEVEN 89
# define KEY_NUM_EIGHT 91
# define KEY_NUM_NINE 92
# define KEY_NUM_PERIOD 65
# define KEY_NUM_RET 76
# define KEY_NUM_PLUS 69
# define KEY_NUM_MINUS 78
# define KEY_NUM_ASTER 67
# define KEY_NUM_FSLASH 75
# define KEY_NUM_CLR 71
# define KEY_NUM_EQUAL 81

/*
** FUNCTION
*/

# define KEY_FN_ONE 122
# define KEY_FN_TWO 120
# define KEY_FN_THREE 99
# define KEY_FN_FOUR 118
# define KEY_FN_FIZE 96
# define KEY_FN_SIX 97
# define KEY_FN_SEVEN 98
# define KEY_FN_EIGHT 100
# define KEY_FN_NINE 101
# define KEY_FN_TEN 109
# define KEY_FN_ELEVEN 110
# define KEY_FN_TWELVE 111
# define KEY_FN_THIRTEEN 105
# define KEY_FN_FOURTEEN 107
# define KEY_FN_FIFTEEN 113
# define KEY_FN_SIXTEEN 106
# define KEY_FN_SEVENTEEN 64
# define KEY_FN_EIGHTEEN 79
# define KEY_FN_NINETEEN 80

/*
** MOUSE
*/
# define KEY_MOUSE_LEFT 1
# define KEY_MOUSE_RGHT 2
# define KEY_MOUSE_MIDDLE 3
# define KEY_MOUSE_SCROLL_UP 4
# define KEY_MOUSE_SCROLL_DN 5

#endif