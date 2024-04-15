/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_store_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lozkuro <lozkuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:20 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/15 14:41:00 by lozkuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	check_and_store_arg(t_element **stack_a, int argc, char **argv)
{
	t_element	*temp;

	temp = NULL;
	only_int_in_stack(argv);
	store_arg(stack_a, temp, argv);
	if (is_stack_already_sorted(stack_a, argc))
		exit(EXIT_SUCCESS);
	if (check_for_duplicates(stack_a))
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

void	store_arg(t_element **stack_a, t_element *temp, char **argv)
{
	int			j;
	t_element	*node;

	j = 1;
	while (argv[j++])
	{
		node = (t_element *)malloc(sizeof(t_element));
		if (!node)
			exit(EXIT_FAILURE);
		node->value = ft_atol(argv[j]);
		if (!*stack_a)
		{
			*stack_a = node;
			temp = node;
		}
		else
		{
			temp->next = node;
			node->prev = temp;
			(*stack_a) = node;
		}
	}
	temp->next = *stack_a;
	(*stack_a)->prev = temp;
}

int	is_stack_already_sorted(t_element **stack_a, int argc)
{
    t_element	*ptr; 
	int			i;

	i = 1;
	ptr = *stack_a;

    while (i < argc - 1)
	{
        if (ptr->value > ptr->next->value)
            return (FALSE);
        ptr = ptr->next;
		i++;
	}
	return (TRUE);
}

int	check_for_duplicates(t_element **stack_a)
{
	t_element	*ptr1;
	t_element	*ptr2;

	ptr1 = *stack_a;
	ptr2 = *stack_a;
	while (ptr1 != (*stack_a)->prev)
	{
		while (ptr2 != (*stack_a)->prev)
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
