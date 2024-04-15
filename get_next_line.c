/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloyaraujo <eloyaraujo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:02:57 by eloyaraujo        #+#    #+#             */
/*   Updated: 2024/04/14 19:49:40 by eloyaraujo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		index;

	index = 0;
	if (BUFFER_SIZE < 1 || fd < 0)
	{
		while (buffer[index])
			buffer[index++] = 0;
		return (0);
	}
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE))
	{
		line = ft_strjoin(line, buffer);
		if (ft_manage_buffer(buffer))
			break ;
	}
	return (line);
}
