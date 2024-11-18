/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:24:59 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/18 00:12:56 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_for_identifier(char *str, int i)
{
   if (ft_strcmp(str, "NO") == 0 || ft_strcmp(str, "SO") == 0 || ft_strcmp(str, "WE") == 0 || ft_strcmp(str, "EA") == 0)
   {
      i++;
   }
   return (i);
}

int check_for_colors(char *str, int i)
{
   if (ft_strcmp(str, "F") == 0 || ft_strcmp(str, "C") == 0)
   {
      i++;
   }
   return (i);
}

int check_length_color(char *str, int i)
{
   int j;

   j = 0;
   while (str[j] != '\0')
   {
      if (str[j] == ',')
         i++;
      j++;
   }
   return (i);
}

void check_rgb(char *str)
{
   int i;
   char *res;
   int rgb;

   i = 0;
   res = malloc(50);
   if (!res)
      return;
   while (str[i] != ',')
   {
      res[i] = str[i];
      i++;
   }
   res[i] = '\0';
   rgb = ft_atoi(res);
   exit(1);
}