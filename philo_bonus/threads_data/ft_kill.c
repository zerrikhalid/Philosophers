/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:44:59 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/22 22:22:40 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_kill(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->nbr_philos)
	{
		kill(philos[i].pid, 9);
	}
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("meal");
	sem_close(philos->data->forks);
	sem_close(philos->data->print);
	sem_close(philos->data->meal);
}
