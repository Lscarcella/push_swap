/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:34:19 by lscarcel          #+#    #+#             */
/*   Updated: 2024/03/22 14:33:39 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove_line(char *stash)
{
	char	*new_stash;
	int		i;
	int		a;
	int		len;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	len = ft_strlen(stash);
	new_stash = malloc((len - i + 1) * sizeof(char));
	if (!new_stash)
		return (0);
	i++;
	a = 0;
	while (stash[i])
		new_stash[a++] = stash[i++];
	new_stash[a] = '\0';
	free(stash);
	return (new_stash);
}

char	*ft_get_line(char *stash)
{
	int		i;
	int		a;
	char	*line;

	i = 0;
	if (!stash[i])
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	a = 0;
	while (stash[a] && stash[a] != '\n')
	{
		line[a] = stash[a];
		a++;
	}
	if (stash[a] == '\n')
	{
		line[a] = stash[a];
		a++;
	}
	line [a] = '\0';
	return (line);
}

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free_buffers_gnl(buf, stash);
			return (0);
		}
		buf[bytes_read] = '\0';
		if (!stash)
		{
			stash = malloc(sizeof(char) * 1);
			stash[0] = '\0';
		}
		stash = ft_strjoin_gnl(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (0);
	line = ft_get_line(stash);
	stash = ft_remove_line(stash);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include "libft.h"

// int main()
// {
//     int fd;
//     char *line;
//     char *file_path = "../maps/valid_1.ber";

//     fd = open(file_path, O_RDONLY);
//     if (fd == -1) {
//         perror("Erreur lors de l'ouverture du fichier");
//         return 1;
//     }
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("Ligne lue : %s\n", line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }
