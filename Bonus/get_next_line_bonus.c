/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:59:06 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 21:57:20 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*set_node(int fd, t_list *head_node, t_list **current_node);
static t_list	*create_or_remove_node(int flag, int fd, \
										t_list *head_node, t_list *node);
static char		*read_line(int fd, char *buffer, char *storage);
static char		*separate_by_newline(char *line);

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_list	*head_node;
	t_list			*current_node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	head_node = set_node(fd, head_node, &current_node);
	if (!head_node || !current_node)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, current_node->storage);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		head_node = create_or_remove_node(REMOVE, fd, head_node, current_node);
		return (NULL);
	}
	current_node->storage = separate_by_newline(line);
	if (!current_node->storage)
		head_node = create_or_remove_node(REMOVE, fd, head_node, current_node);
	return (line);
}

static t_list	*create_or_remove_node(int flag, int fd, \
										t_list *head_node, t_list *node)
{
	t_list	*temp_node;

	if (flag == CREATE)
	{
		temp_node = malloc(sizeof(t_list));
		if (!temp_node)
			return (NULL);
		temp_node->fd = fd;
		temp_node->storage = NULL;
		temp_node->next = NULL;
		return (temp_node);
	}
	temp_node = head_node;
	while (temp_node->next != node && head_node != node)
		temp_node = temp_node->next;
	if (head_node != node)
	{
		temp_node->next = node->next;
		temp_node = head_node;
	}
	else
		temp_node = head_node->next;
	free(node->storage);
	free(node);
	return (temp_node);
}

static t_list	*set_node(int fd, t_list *head_node, t_list **current_node)
{
	t_list	*temp_node;

	if (!head_node)
	{
		*current_node = \
			create_or_remove_node(CREATE, fd, head_node, *current_node);
		return (*current_node);
	}
	temp_node = head_node;
	while (temp_node)
	{
		if (temp_node->fd == fd)
			break ;
		if (temp_node->next == NULL)
			temp_node->next = \
				create_or_remove_node(CREATE, fd, head_node, *current_node);
		temp_node = temp_node->next;
	}
	*current_node = temp_node;
	return (head_node);
}

static char	*read_line(int fd, char *buffer, char *storage)
{
	int		read_byte;
	char	*temp;

	while (ft_strchr(storage, '\n') == NULL)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (NULL);
		if (read_byte == 0)
			break ;
		buffer[read_byte] = 0;
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (!storage)
			return (NULL);
	}
	return (storage);
}

static char	*separate_by_newline(char *line)
{
	int		idx;
	char	*storage;

	idx = 0;
	while (line[idx] != '\n' && line[idx])
		idx++;
	if (line[idx] == '\0')
		return (NULL);
	storage = ft_substr(line, idx + 1, ft_strlen(line) - idx - 1);
	if (!storage)
		return (NULL);
	if (storage[0] == '\0')
	{
		free(storage);
		storage = NULL;
	}
	line[idx + 1] = '\0';
	return (storage);
}
