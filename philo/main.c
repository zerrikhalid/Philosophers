/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:42:42 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/22 21:48:33 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		usleep(50);
	while (1)
	{
		ft_eat(philo);
		ft_print(philo, "is sleeping", 0);
		ft_sleep(philo->data->time_to_sleep);
		ft_print(philo, "is thinking", 0);
		usleep(50);
	}
	return (NULL);
}

int	start_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		philos[i].last_meals = current_time();
	i = -1;
	while (++i < data->nbr_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, \
			(void *)(philos + i)))
			return (1);
	}
	return (0);
}

t_philo	*create_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
	if (!philos)
		return (0);
	while (++i < data->nbr_philos)
	{
		philos[i].philo_id = i;
		philos[i].data = data;
	}
	return (philos);
}

int	main(int ac, char **av)
{
	int		res;
	t_data	*data;
	t_philo	*philos;
	int		i;

	if (ac < 5 || ac > 6)
		return (error(1));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	res = check_arguments(av, data);
	if (!res || res == -1)
		return (error(0));
	philos = create_philos(data);
	if (!philos)
		return (1);
	data->start_time = current_time();
	if (start_philos(philos, data))
		return (1);
	i = -1;
	while (++i < data->nbr_philos)
		pthread_detach(philos[i].thread);
	check_death(philos);
}
