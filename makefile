# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 15:14:49 by mbonnet           #+#    #+#              #
#    Updated: 2021/05/04 16:06:42 by mbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

SRCS			= 	main/ft_main.c\
				bmp/bmp_utils.c\
				bmp/bmp.c\
				bmp/raycasting_bmp.c\
				close/ft_close_programe.c\
				mouv/calcul_obj_2.c\
				mouv/calcul_obj.c\
				mouv/draw_obj.c\
				mouv/init_mouv.c\
				parsage/ft_ciel_terre/check_ciel_terre_2.c\
				parsage/ft_ciel_terre/check_ciel_terre.c\
				parsage/ft_derniere_line/ft_verif_dernier_line.c\
				parsage/ft_lancement/ft_lancement_parsage.c\
				parsage/ft_map/ft_verif_map/ft_netoyage_map_init_perso.c\
				parsage/ft_map/ft_verif_map/ft_verif_map.c\
				parsage/ft_map/ft_verif_map/ft_verif_map_2.c\
				parsage/ft_map/ft_copie_map_2.c\
				parsage/ft_map/ft_copie_map.c\
				parsage/ft_obj/ft_init_obj.c\
				parsage/ft_ray/ft_init_ray.c\
				parsage/ft_reso/check_reso.c\
				parsage/ft_texture/check_texture.c\
				parsage/ft_texture/ft_memorise_texture.c\
				parsage/ft_utile/ft_fonction_support.c\
				raycasting/ft_click/ft_de_click.c\
				raycasting/ft_lancement/ft_lancement_raycasting.c\
				raycasting/ft_raycasting/creat_and_init_image.c\
				raycasting/ft_raycasting/init_texture.c\
				raycasting/ft_raycasting/raycasting.c\
				raycasting/ft_raycasting/search_cub_utile.c\
				raycasting/ft_raycasting/search_cub.c\

OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

HEAD			=	-I includes -I libft/includes -I ${MLX_DIR}

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g 

LIBFT_DIR		=	libft

MLX_DIR			=	minilibx-linux-master

LDFLAGS			=	-L ${LIBFT_DIR} -L ${MLX_DIR}

MLX				= -lm -lft -lmlx -lXext -lX11 

LIBS			=	${MLX}

.c.o			:
					@${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C ${LIBFT_DIR}
					make -C ${MLX_DIR}
					${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME} ${LIBS}

all				:	${NAME}


clean			:
					make clean -C ${LIBFT_DIR}
					make clean -C ${MLX_DIR}
					rm -rf ${OBJS}

fclean			:	clean
					make fclean -C ${LIBFT_DIR}
					rm -rf ${NAME}
					rm -rf save.bmp

re				:	fclean all

.PHONY			:	all clean fclean re
