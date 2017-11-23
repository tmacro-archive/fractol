/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 22:36:44 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/20 22:42:05 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/*
 * ** char *string = ""
 * **	"asdfhgzxcv"		This string has the matching symbol or letter
 * **	"bqweryt123"		for the index of the keycode for the key.
 * **	"465=97-80]"		if you press KEY_BRACE_R or ]
 * **	"ou[ip lj\"k"		You could use string[30] or string[KEY_BRACE_R]
 * **	";\\,/nm.  ` "		to access the matching symbol or letter.
 * **	"	. * +   "
 * **	"/ -  =012345"		If you find anything missing please let me know.
 * **	"67 89";
 * */

// # define SET_KEY(key) (key |= 1)
// # define CLR_KEY(key) (key &= ~1)
// # define TOG_KEY(key) (key ^= 1)
// # define GET_KEY(key) (key & 1)

# define SET_KEY(key) (key = 1)
# define CLR_KEY(key) (key = 0)
# define TOG_KEY(key) (key = (key) ? (0) : (1))
# define GET_KEY(key) (!!key)

# define MAX_KC 265

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_EQUAL 24
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_DASH 27
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_RET 36
# define KEY_L 37
# define KEY_J 38
# define KEY_APO 39
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_BSL 42
# define KEY_COMMA 43
# define KEY_FSL 44
# define KEY_N 45
# define KEY_M 46
# define KEY_PERIOD 47
# define KEY_TAB 48

# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_SPC 12

typedef int				t_key[MAX_KC];
typedef void			(*t_keyhandler)(int, t_key);
typedef t_keyhandler	t_keyhandlers[MAX_KC];

#endif
