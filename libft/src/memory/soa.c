/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:50:51 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"

size_t	soa(void *data, char type)
{
	type = 1;
	if (type)
		return (sizeof((char *)data));
	return (1);
}
