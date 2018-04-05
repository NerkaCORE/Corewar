/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:47:13 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/08 21:15:34 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft.h"
# include "../include/libft/get_next_line.h"

/*
** int flag:
** # = FLAG_DI
** 0 = FLAG_ZE
** - = FLAG_NEG
** + = FLAG_POS
** j = FLAG_J
** h = FLAG_H
** l = FLAG_L
** z = FLAG_Z
** hh = FLAG_HH
** ll = FLAG_LL
** L = FLAG_GL
** space = FLAG_SP
** precision = FLAG_PR
** couleur = FLAG_COLOR
*/

# define FLAG_DI	0x00000001
# define FLAG_ZE	0x00000002
# define FLAG_NEG	0x00000004
# define FLAG_POS	0x00000008
# define FLAG_J		0x00000010
# define FLAG_H		0x00000020
# define FLAG_L		0x00000040
# define FLAG_Z		0x00000080
# define FLAG_HH	0x00000100
# define FLAG_LL	0x00000200
# define FLAG_SP	0x00000400
# define FLAG_PR	0x00000800
# define FLAG_GL	0x00001000
# define FLAG_COLOR	0x00002000

/*
** COLOR:
** CL_0 = white
** CL_1 = black
** CL_2 = red
** CL_3 = green
** CL_4 = yellow
** CL_5 = blue
** CL_6 = purple
** CL_7 = cyan
** CL_8 = grey
*/

# define CL_0 "\x1b[0m"
# define CL_1 "\x1b[30m"
# define CL_2 "\x1b[31m"
# define CL_3 "\x1b[32m"
# define CL_4 "\x1b[33m"
# define CL_5 "\x1b[34m"
# define CL_6 "\x1b[35m"
# define CL_7 "\x1b[36m"
# define CL_8 "\x1b[37m"

# define MAX -9223372036854775807

typedef struct	s_var
{
	char			*form;
	char			*tmp;
	char			*str;
	char			*ptr;
	char			spe;
	unsigned int	flag;
	int				pwc;
	int				neg;
	int				preci;
	int				width;
	int				arg;
	int				naze;
	int				free;
	int				free1;
	int				ind;
	int				*index;
	int				i;
	va_list			ap;
}				t_var;

typedef struct	s_ld
{
	int			i;
	int			preci;
	int			neg;
	int			nbdiv;
	int			nbmult;
	char		*ret;
	long double	save;
	long double	nb;
}				t_ld;

char			*ft_strjoin_free(char *s1, char *s2, int d);
int				ft_printf(const char *format, ...);
void			init_var(t_var *var);
int				ft_pars_str(t_var *var);
int				ft_pars_mod(t_var *var);
void			ft_pars_nb(t_var *var);
int				ft_verif_flag(t_var *var);
void			ft_verif_flag2(t_var *var);
void			ft_pars_nbp(t_var *var);
void			ft_put_end(t_var *var);
void			ft_init_tab(int (**tab_ft)(t_var *));
int				ft_check_flag(t_var *var);
int				ft_check_modif(t_var *var);
int				ft_spe_mod(t_var *var);
int				ft_spe_nb(t_var *var);
int				ft_spe_char(t_var *var);
int				ft_spe_str(t_var *var);
int				ft_spe_unb(t_var *var);
int				ft_spe_oct(t_var *var);
int				ft_spe_hex(t_var *var);
int				ft_spe_hexup(t_var *var);
int				ft_spe_mem(t_var *var);
int				ft_spe_l(t_var *var);
int				ft_spe_wchar(t_var *var);
int				ft_spe_wcstr(t_var *var);
int				ft_spe_intn(t_var *var);
int				ft_spe_ubin(t_var *var);
int				ft_spe_bin(t_var *var);
int				ft_spe_ld(t_var *var);
int				ft_spe_eld(t_var *var);
int				ft_spe_gld(t_var *var);
char			*ft_add_char(char *str, char c, t_var *var);
int				cc(t_var *var, char c);
char			*ft_space(char *str, t_var *var);
int				ft_verif_flag(t_var *var);
char			*wctost(wchar_t wc, t_var *var);
char			*ft_zero(t_var *var, int x);
char			*ft_itoamax(intmax_t n);
char			*ft_preci_nb(char *str, t_var *var);
char			*ft_preci_str(char *str, t_var *var);
intmax_t		ft_get_int(t_var *var);
intmax_t		ft_get_uint(t_var *var);
char			*to_ubase(uintmax_t n, int b);
char			*to_ubaseup(uintmax_t n, int b);
char			*ft_getbit(uintmax_t n);
char			*ft_strrevchr(char *s, int c);
char			*ft_exp(t_var *var, char *str, int p);
char			*ft_ld(t_var *var);
char			*ldtoa(t_var *var, long double ld, int preci);
void			norm_sp(t_var *var);
int				norm_wch(t_var *var, wchar_t wc, char *tmp);
char			*norm_wcst(t_var *var, wchar_t *wc, char *tmp);
char			*norm_ld(char *tmp);
char			*norm_exp(t_var *var, char *str, int j);
int				norm_gl(t_var *var, char **tmp);
int				ft_color(t_var *var);
void			ft_end_color(t_var *var);
void			free_var(t_var *var);
#endif
