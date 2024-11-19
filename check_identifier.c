/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:24:59 by aahlaqqa          #+#    #+#             */
/*   Updated: 2024/11/19 17:52:44 by aahlaqqa         ###   ########.fr       */
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

void check_floor_rgb(char *str, t_data *data)
{
   int i;
   int j;
   char res[4];
   int rgb[3];
   int x;

   i = 0;
   x = 0;
   while (x < 3)
   {
      j = 0;
      while (str[i] && str[i] != '\0' && str[i] != ',')
      {
         if (j <= 3)
         {
            res[j] = str[i];
            j++;
         }
         i++;
      }
      res[j] = '\0';
      rgb[x] = ft_atoi(res);
      data->floor[x] = rgb[x];
      x++;
      if (str[i] == ',')
         i++;
   }
}

void check_cell_rgb(char *str, t_data *data)
{
   int i;
   int j;
   char res[4];
   int rgb[3];
   int y;

   i = 0;
   y = 0;
   while (y < 3)
   {
      j = 0;
      while (str[i] && str[i] != '\0' && str[i] != ',')
      {
         if (j <= 3)
         {
            res[j] = str[i];
            j++;
         }
         i++;
      }
      res[j] = '\0';
      rgb[y] = ft_atoi(res);
      data->cell[y] = rgb[y];
      y++;
      if (str[i] == ',')
         i++;
   }
}

void check_rgb_fllor_range(t_data *data)
{
   int i;

   i = 0;
   while (i < 3)
   {
      if (data->floor[i] < 0 || data->floor[i] > 255)
      {
         printf("Error\n RGB range is incorrect !");
         exit(1);
      }
      i++;
   }
}

void check_rgb_cell_range(t_data *data)
{
   int j;

   j = 0;
   while (j < 3)
   {
      if (data->cell[j] < 0 || data->cell[j] > 255)
      {
         printf("Error\n RGB range is incorrect !");
         exit(1);
      }
      j++;
   }
}

void check_texture(char *str, t_data *data)
{
   int i;
   char *extention;

   if (!str)
      return;
   i = 0;
   extention = ft_strrchr(str, '.');
   if (!extention)
      return;
   if (ft_strcmp(extention, ".xpm") == 0)
   {
      data->texture = str;
   }
   else
   {
      printf("Error\n incorrect texture !");
      exit(1);
   }
   i++;
}