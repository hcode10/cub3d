/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debug2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:30:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/22 10:30:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	dbg_val(char *tag, char *val)
{
	if (!DEBUG)
		return ;
	fprintf(stderr, "\033[33m[DBG] %s = [%s]\033[0m\n", tag, val);
}

void	dbg_fail(char *where, char *why)
{
	if (!DEBUG)
		return ;
	fprintf(stderr, "\033[31m[DBG] FAIL @ %s : %s\033[0m\n", where, why);
}
