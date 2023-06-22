/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:39:57 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/22 22:21:53 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->forks);
	ft_print(philo, "has taken a fork", 0);
	sem_wait(data->forks);
	ft_print(philo, "has taken a fork", 0);
	ft_print(philo, "is eating", 0);
	ft_sleep(data->time_to_eat);
	sem_post(data->forks);
	sem_post(data->forks);
	sem_wait(data->meal);
	philo->nbr_of_meals++;
	philo->last_meals = current_time();
	sem_post(data->meal);
}
