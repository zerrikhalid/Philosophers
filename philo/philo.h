/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:45:50 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/20 22:39:02 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_data
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_t_philo_m_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	meal;
	unsigned long	start_time;
}t_data;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread;
	t_data			*data;
	int				nbr_of_meals;
	unsigned long	last_meals;
}t_philo;

int				error(int key);
int				check_arguments(char **av, t_data *data);
unsigned long	current_time(void);
void			ft_print(t_philo *ph, char *msg, int flag);
void			ft_sleep(unsigned long time);
void			ft_eat(t_philo *philo);
void			check_death(t_philo *philos);
int				check_meals(t_philo *philos);
void			check_death(t_philo *philos);

#endif