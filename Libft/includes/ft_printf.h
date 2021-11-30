/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:39:37 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/19 16:26:30 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define EXIT_SUCCESS 0
# define NO_SPECIFIER_ERR -2
# define COLOR_ERR -3
# define EXIT_ERROR -1
# define TRUE 1
# define FALSE 0
# define LEFT 1
# define RIGHT 2
# define SIGNED 2
# define UNSIGNED 3
# define H_CONV 1
# define HH_CONV 2
# define J_CONV 3
# define Z_CONV 4
# define L_CONV 5
# define LL_CONV 6

typedef struct		s_printf
{
	const char		*format;
	int				i;
	int				hastag;
	int				plus;
	int				zero;
	int				white_space;
	int				pourcent;
	int				moins;
	int				width;
	int				precision;
	int				conv;
	char			*color;
	va_list			ap;
	char			sign;
	int				printed;
}					t_printf;

int					ft_printf(const char *format, ...);
int					check_specifiers(t_printf *pf);

/*
**ft_printf_identifiers.c
*/

void				get_flags(t_printf *pf);
void				get_width(t_printf *pf);
void				get_precision(t_printf *pf);
void				get_modificateur(t_printf *pf);
void				get_modificateur_suite(t_printf *pf);

/*
**get_specifiers.c
*/

int					get_specifiers(t_printf *pf);
int					get_specifiers_suite(t_printf *pf);

/*
**ft_print_color.c
*/

int					get_color(t_printf *pf);

/*
**utils.c
*/

void				ft_pputnchar(t_printf *pf, char c, int n);
void				ft_pputstr(t_printf *pf, char *s);
void				ft_pputnstr(t_printf *pf, char *save, int len);
void				my_putstr(char *s);

/*
**utils_printf.c
*/

int					ft_atoi_i(const char *str, t_printf *pf);
int					ft_preci_save_zero(t_printf *pf, long long save);
void				ft_pputstrmaj(t_printf *pf, char *c_save);

/*
**ft_print_resultat.c
*/

void				ft_print(t_printf *pf, char *c_save, char *prefix);
void				ft_print_right(t_printf *pf, char *c_save, char *prefix);
int					ft_print_nospecifier(t_printf *pf);
/*
**ft_modificateurs
*/

long long			solve_modificateurs_unsigned(t_printf *pf);
long long			solve_modificateurs(t_printf *pf, int sign);

/*
**utils_itoa.c
*/

char				*ft_llong_itoa(unsigned long long nb, char *base);

/*
**ft_printf_conversion
*/

int					ft_printf_s(t_printf *pf);
int					ft_printf_smaj(t_printf *pf);
int					ft_printf_d(t_printf *pf);
int					ft_printf_ld(t_printf *pf);
int					ft_printf_c(t_printf *pf);
void				ft_pputwchar(unsigned int chr);
int					ft_printf_cmaj(t_printf *pf);
int					ft_printf_solve_x(t_printf *pf, char *base, char *prefix);
int					ft_printf_xmin(t_printf *pf);
int					ft_printf_xmaj(t_printf *pf);
int					ft_printf_p(t_printf *pf);
int					ft_printf_u(t_printf *pf);
int					ft_printf_umaj(t_printf *pf);
int					ft_printf_solve_o(t_printf *pf, char *base, char *prefix);
int					ft_printf_omaj(t_printf *pf);
int					ft_printf_o(t_printf *pf);
int					ft_printf_pourcent(t_printf *pf);

#endif
