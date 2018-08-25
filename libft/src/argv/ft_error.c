/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:37:49 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/07 18:37:49 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"

int	ft_error(char *error_name)
{
	ft_putendl_fd(error_name, 2);
	exit(EXIT_FAILURE);
}
