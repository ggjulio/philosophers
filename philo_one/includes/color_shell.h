/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:27:38 by juligonz          #+#    #+#             */
/*   Updated: 2020/10/06 16:35:48 by juligonz         ###   ########.fr       */
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
# define _RED      	"\e[91m"
# define _GREEN   	"\e[92m"
# define _YELLOW  	"\e[93m"
# define _BLUE    	"\e[94m"
# define _MAGENTA 	"\e[35m"
# define _CYAN    	"\e[96m"
# define _WHITE   	"\e[97m"

# define _DARK_GREY	"\e[97m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IRED     	"\e[101m"
# define _IGREEN   	"\e[102m"
# define _IYELLOW  	"\e[103m"
# define _IBLUE    	"\e[104m"
# define _IMAGENTA 	"\e[45m"
# define _ICYAN    	"\e[106m"
# define _IWHITE   	"\e[107m"

#endif
