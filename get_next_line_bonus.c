/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:06:35 by romlambe          #+#    #+#             */
/*   Updated: 2023/10/23 16:37:25 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//creer une ft pour clear
//comprendre comment fonctionne le multi fd
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stack[1024];
	int			valread;

	if (fd == -1)
		return (NULL);
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(stack[fd]), stack[fd] = NULL, NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	valread = 1;
	while (valread > 0)
	{
		valread = read(fd, buffer, BUFFER_SIZE);
		buffer[valread] = '\0';
		stack[fd] = ft_strjoin(stack[fd], buffer);
		if (ft_strchr(stack[fd]))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (to_write(&stack[fd]));
}
