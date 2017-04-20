#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/14 15:17:57 by ioleksiu          #+#    #+#              #
#    Updated: 2017/04/14 15:18:35 by ioleksiu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I fdf.h

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

SRC	= c_count.c \
		c_ord.c \
		color.c \
		cord_centre.c \
		div_mult_xy.c \
		draw_line.c \
		fdf.c \
		fill_head_xy.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_counts.c \
		ft_countw.c \
		ft_error.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strsplit.c \
		get_next_line.c \
		main.c \
		map_create.c \
		move_left_right.c \
		move_up_down.c \
		my_key_funct.c \
		print_xy.c \
		validation.c \
		xy_transform.c \
		zoom_in_out.c

OBJECTS	= c_count.o \
		c_ord.o \
		color.o \
		cord_centre.o \
		div_mult_xy.o \
		draw_line.o \
		fdf.o \
		fill_head_xy.o \
		ft_atoi.o \
		ft_bzero.o \
		ft_counts.o \
		ft_countw.o \
		ft_error.o \
		ft_strcat.o \
		ft_strchr.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_strncpy.o \
		ft_strnew.o \
		ft_strsplit.o \
		get_next_line.o \
		main.o \
		map_create.o \
		move_left_right.o \
		move_up_down.o \
		my_key_funct.o \
		print_xy.o \
		validation.o \
		xy_transform.o \
		zoom_in_out.o

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(FRAMEWORK)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: clean  all