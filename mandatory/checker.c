/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:07:36 by otzarwal          #+#    #+#             */
/*   Updated: 2025/02/12 20:58:36 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int    check_isdigit(char *s)
{
    if(*s == '-' || *s == '+')
        s++;
    while(*s && (*s >= '0' && *s <= '9'))
        s++;
    if (*s && !(*s >= '0' && *s <= '9'))
        return (0);
    return (1);
}

int duplicate(t_stack *a, int num)
{
    while(a)
    {
        if (a->data == num)
            return (0);
        a = a->next;
    }
    return (1);
}

int     check_duplicate(t_stack **a, char **arg)
{
    int i;
    long num;
    int ck;
    t_stack *node;
    num = 0;
    i = 0;
    ck = 1;
    while(arg[i])
    {
        num = ft_atoi(arg[i]);
        // printf("num = %d\n", num);
        if (num < -2147483648 || num > 2147483647)
            return (0);
        if (!duplicate(*a, num))
            return (0);
        node = ft_lstnew(num);
        ft_lstadd_back(a, node);
        i++;
    }
    return (1);
}
void    join_argv(char **av, char **all_arg)
{
    while(*av)
    {
        *all_arg = ft_strjoin_2(*all_arg, *av);
        if (*(av + 1))
            *all_arg = ft_strjoin_2(*all_arg, " ");
        av++;
    }
}

int    check_is_only_digit(char **arg)
{
    int i;

    i = 0;
    while(arg[i])
    {
        if (!check_isdigit(arg[i]))
            return (0);
        i++;
    }
    return (1);
}

void ft_sort(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    tmp = *a;
    
    while (tmp)
    {

        if(tmp->index <= 1)
        {
            pb(&tmp, b);
            printf("pb\n");
        }
        else
            tmp = tmp->next;
    }
    
}