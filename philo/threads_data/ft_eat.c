/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:39:57 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/20 22:20:02 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->philo_id]);
	ft_print(philo, "has taken a fork", 0);
	pthread_mutex_lock(&data->fork[(philo->philo_id + 1) % data->nbr_philos]);
	ft_print(philo, "has taken a fork", 0);
	ft_print(philo, "is eating", 0);
	ft_sleep(data->time_to_eat);
	pthread_mutex_unlock(&data->fork[philo->philo_id]);
	pthread_mutex_unlock(&data->fork[(philo->philo_id + 1) % data->nbr_philos]);
	pthread_mutex_lock(&data->meal);
	philo->nbr_of_meals++;
	philo->last_meals = current_time();
	pthread_mutex_unlock(&data->meal);
}
