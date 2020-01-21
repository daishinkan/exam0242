/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekindomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:48:33 by ekindomb          #+#    #+#             */
/*   Updated: 2020/01/21 11:53:54 by ekindomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	filler(char c, int num, int *done);
void	put_str_lim(const char *str, int lim, int *done);
int		is_from_str(char c, const char *str);
int		ft_atoi(const char *str, int *i);
char	*ft_itoa(long long int num, long long int base, int padding);
int		num_char_count(long long int num, long long int base);
int		ft_strlen(const char *str);
int		ft_printf(const char *format, ...);

#endif
