/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:27:38 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/10 00:01:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_SHELL_H
# define COLOR_SHELL_H

/*
** qhttps://misc.flogisoft.com/bash/tip_colors_and_formatting
*/

# define _BOLD      "\e[1m"
# define _DIM       "\e[2m"
# define _UNDERLINE "\e[4m"
# define _BLINK     "\e[5m"
# define _REVERSE   "\e[7m"
# define _HIDDEN    "\e[8m"

/*
** RESET list
*/
# define _R          "\e[0m"
# define _RBOLD      "\e[21m"
# define _RDIM       "\e[22m"
# define _RUNDERLINE "\e[24m"
# define _RBLINK     "\e[25m"
# define _RREVERSE   "\e[27m"
# define _RHIDDEN    "\e[28m"

/*
** Colors
*/
# define _COLOR_DEFAULT	"\e[39m"
# define _BLACK			"\e[30m"
# define _RED			"\e[31m"
# define _GREEN			"\e[32m"
# define _YELLOW		"\e[33m"
# define _BLUE			"\e[34m"
# define _MAGENTA		"\e[35m"
# define _CYAN			"\e[36m"
# define _LIGHT_GREY	"\e[37m"
# define _DARK_GREY		"\e[90m"
# define _LIGHT_RED    	"\e[91m"
# define _LIGHT_GREEN  	"\e[92m"
# define _LIGHT_YELLOW 	"\e[93m"
# define _LIGHT_BLUE   	"\e[94m"
# define _LIGHT_MAGENTA	"\e[35m"
# define _LIGHT_CYAN   	"\e[96m"
# define _WHITE		 	"\e[97m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IBLACK			"\e[40m"
# define _IRED				"\e[41m"
# define _IGREEN			"\e[42m"
# define _IYELLOW			"\e[43m"
# define _IBLUE				"\e[44m"
# define _IMAGENTA			"\e[45m"
# define _ICYAN				"\e[46m"
# define _ILIGHT_GREY		"\e[47m"
# define _IDARK_GREY		"\e[100m"

# define _ILIGHT_RED		"\e[101m"
# define _ILIGHT_GREEN   	"\e[102m"
# define _ILIGHT_YELLOW  	"\e[103m"
# define _ILIGHT_BLUE    	"\e[104m"
# define _ILIGHT_MAGENTA	"\e[45m"
# define _ILIGHT_CYAN    	"\e[106m"
# define _ILIGHT_WHITE   	"\e[107m"

#endif
