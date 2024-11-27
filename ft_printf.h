/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:12:59 by egache            #+#    #+#             */
/*   Updated: 2024/11/27 23:13:09 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include	"stdarg.h"
# include	"unistd.h"
# include	"stdlib.h"
# include	"limits.h"
# include	"stdint.h"

int	ft_printf(const char *str, ...);

#endif
