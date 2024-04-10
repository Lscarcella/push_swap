/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_store_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:20 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/10 14:24:07 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	check_and_store_arg(t_element **top_of_stack, t_element **bot_of_stack, int argc, char **argv)
{
	only_int_in_stack(argv);
	store_arg(top_of_stack, bot_of_stack, argv);
	if (is_stack_already_sorted(top_of_stack, argc))
		exit(EXIT_SUCCESS);
	if (check_for_duplicates(top_of_stack))
		exit(EXIT_SUCCESS);
}

void	only_int_in_stack(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '-' || argv[j][i] == '+')
				i++;
			if (argv[j][i] < '0' || argv[j][i] > '9' )
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

void	store_arg(t_element **top_of_stack, t_element **bot_of_stack, char **argv)
{
	int			j;
	t_element	*node;

	j = 1;
	while (argv[j])
	{
		node = (t_element *)malloc(sizeof(t_element));
		if (!node)
			exit(EXIT_FAILURE);
		node->value = ft_atol(argv[j]);
		if (!*top_of_stack)
		{
			*top_of_stack = node;
			*bot_of_stack = node;
		}
		else
		{
			(*bot_of_stack)->next = node;
			node->prev = (*bot_of_stack);
			(*bot_of_stack) = node;
		}
		j++;
	}
	(*bot_of_stack)->next = *top_of_stack;
	(*top_of_stack)->prev = *bot_of_stack;
}

int	is_stack_already_sorted(t_element **top_of_stack, int argc)
{
    t_element	*ptr; 
	int			i;

	i = 1;
	ptr = *top_of_stack;

    while (i < argc - 1)
	{
        if (ptr->value > ptr->next->value)
            return (FALSE);
        ptr = ptr->next;
		i++;
	}
	return (TRUE);
}

int	check_for_duplicates(t_element **top_of_stack)
{
	t_element	*ptr1;
	t_element	*ptr2;

	ptr1 = *top_of_stack;
	ptr2 = *top_of_stack;
	while (ptr1 != (*top_of_stack)->prev)
	{
		while (ptr2 != (*top_of_stack)->prev)
		{
			ptr2 = ptr2->next;
			if (ptr2->value == ptr1->value)
				return (TRUE);
		}
		ptr1 = ptr1->next;
		ptr2 = ptr1;
	}
	return (FALSE);
}
