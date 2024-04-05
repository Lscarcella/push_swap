/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_store_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lozkuro <lozkuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:20 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/05 16:00:30 by lozkuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

// void	init_struct(t_element **element)
// {
// 	ft_memset(&element, 0, sizeof(element));
// }
void	check_and_store_arg(t_element **top_of_stack, t_element **bot_of_stack, char **argv)
{
	check_arg(argv);
	store_arg(top_of_stack, bot_of_stack, argv);
	if (is_stack_sorted(top_of_stack))
	{
    exit(EXIT_SUCCESS);
	}

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

void	store_arg(t_element **top_of_stack, t_element **bot_of_stack, char **argv)
{
	int j;
	t_element *node;

	j = 1;
	*top_of_stack = NULL;
	*bot_of_stack = NULL;
	while(argv[j])
	{
	node = (t_element *)malloc(sizeof(t_element));
	if(!node)
		exit(EXIT_FAILURE);
	node->value = ft_atol(argv[j]);
	if(!*bot_of_stack)
	{
		*bot_of_stack = node;
		*top_of_stack = node;
	}
	else
	{
		(*top_of_stack)->next = node;
		node->prev = (*top_of_stack);
					(*top_of_stack) = node;
	}
	j++;
}
last_node(top_of_stack, bot_of_stack);
}

void	last_node(t_element **top_of_stack, t_element **bot_of_stack)
{
	(*top_of_stack)->next = *bot_of_stack;
	(*bot_of_stack)->prev = *top_of_stack;
}


int is_stack_sorted(t_element **top_of_stack)
{
    t_element *ptr; 
	
	ptr = *top_of_stack;

    while (ptr && ptr->prev)
	{
        if (ptr->value > ptr->prev->value)
            return (FALSE);
        ptr = ptr->prev;
    }
    return (TRUE);
}