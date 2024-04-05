/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_store_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:20 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/04 10:40:48 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	init_struct(t_element **element)
{
	ft_memset(&element, 0, sizeof(element));
}
void	check_and_store_arg(t_element **snake, t_element **tail, char **argv)
{
	check_arg(argv);
	store_arg(snake, tail, argv);
}
void check_arg(char **argv)
{
	int i;
	int j;

	j = 1;
	while(argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if(argv[j][i] == '-' || argv[j][i] == '+')
				i++;
			if(argv[j][i] < '0' || argv[j][i] > '9' )
			{
				printf(COLOR_RED"Error\n"TEXT_RESET);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

void	store_arg(t_element **head, t_element **tail, char **argv)
{
	int j;
	t_element *node;

	j = 1;
	*head = NULL;
	while(argv[j])
	{
		node = (t_element *)malloc(sizeof(t_element));
		if(!node)
			exit(EXIT_FAILURE);
		node->value = ft_atol(argv[j]);
		if(!*head)
			create_head_and_tail(head, node, tail);
		else
		{
			(*tail)->next = node;
			node->prev = (*tail);
			(*tail) = node;
		}
		j++;
	}
	last_node(tail, head);
	}

	void	create_head_and_tail(t_element **head, t_element *node, t_element **tail)
	{
		*head = node;
		*tail = node;

   	 	(*head)->next = NULL;
   		(*tail)->next = NULL;
	}

	void	last_node(t_element **tail, t_element **head)
	{
		(*tail)->next = *head;
		(*head)->prev = (*tail);
	}