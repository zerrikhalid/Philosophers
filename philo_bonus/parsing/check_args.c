/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:42:13 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/22 22:15:48 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *av)
{
	int	res;
	int	nb;

	res = 0;
	while (*av >= '0' && *av <= '9')
	{
		nb = *av - 48;
		if (res > (INT_MAX / 10) || (res == (INT_MAX / 10) && nb > 7))
			return (-1);
		res = (res * 10) + nb;
		av++;
	}
	return (res);
}

void	init(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/meal");
	data->forks = sem_open("/forks", O_CREAT, 0600, data->nbr_philos);
	data->print = sem_open("/print", O_CREAT, 0600, 1);
	data->meal = sem_open("/meal", O_CREAT, 0600, 1);
}

int	check_arguments(char **av, t_data *data)
{
	int	i;
	int	res;

	i = 0;
	data->nbr_t_philo_m_eat = -1;
	while (av[++i])
	{
		res = ft_atoi(av[i]);
		if (!res || res == -1)
			return (res);
		if (i == 1)
			data->nbr_philos = res;
		if (i == 2)
			data->time_to_die = res;
		if (i == 3)
			data->time_to_eat = res;
		if (i == 4)
			data->time_to_sleep = res;
		if (i == 5)
			data->nbr_t_philo_m_eat = res;
	}
	init(data);
	return (2);
}
