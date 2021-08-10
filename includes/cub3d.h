/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:03:15 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 16:02:41 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.141592653589793238
# define ANGLE_VUE 60
# define BYTES_FORMAT 24
# define BMP_FILE_NAME "save.bmp"
# include "../minilibx-linux-master/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct s_verif
{
	int	x;
	int	y;
}	t_verif;

typedef struct s_tex
{
	int		taille_x;
	int		taille_y;
	int		taille_line;
	int		bpp;
	int		endian;
	void	*img_ptr;
	char	*data;
}	t_tex;

typedef struct s_reso
{
	int	x;
	int	y;
}	t_reso;

typedef struct s_decor
{
	int	c;
	int	t;
}	t_decor;

typedef struct s_ray
{
	float	avant;
	float	arriere;
	float	droite;
	float	gauche;
	float	debut_vue;
	float	op_ray;
}	t_ray;

typedef struct s_img
{
	void	*struct_img;
	char	*adr;
	int		bitp;
	int		linelength;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_img	img;
}	t_mlx;

typedef struct s_vecteur
{
	float	x;
	float	y;
	float	d;
	char	t;
}	t_vecteur;

typedef struct s_obj
{
	float	taille_obj;
	float	taille_x;
	float	taille_y;
	float	coef_x;
	float	coef_y;
	float	pos_x;
	float	pos_y;
	float	x;
	float	y;
	float	d;
	float	ray;
	float	angle;
}	t_obj;

typedef struct s_mouv
{
	int	droite;
	int	gauche;
	int	avant;
	int	arriere;
	int	cam_droite;
	int	cam_gauche;
	int	sup;
}	t_mouv;

typedef struct s_parsage
{
	float		cub_y;
	char		*lien;
	char		**map;
	t_reso		reso;
	t_decor		decor;
	t_vecteur	perso;
	t_ray		ray;
	t_mlx		mlx;
	t_mouv		mouv;
	t_tex		lst_texture[6];
	t_obj		*obj;
	t_verif		*info_map;
}	t_parsage;

typedef struct s_search_cub
{
	t_vecteur	perso;
	float		angle;
	float		ray;
	t_vecteur	d_perso;
	char		**map;
	t_vecteur	res;
	t_tex		texture;
	t_vecteur	coef;
	float		avant;
}	t_search_cub;

typedef struct s_tmp2
{
	int	x;
	int	y;
	int	etat;
}	t_tmp2;

typedef struct s_tmp
{
	int		x;
	int		y;
	t_tmp2	a1;
	t_tmp2	a2;
	t_tmp2	a3;
	t_tmp2	a4;
}	t_tmp;

typedef struct s_bmp
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_bmp;

typedef struct s_img_header
{
	int		size_img_header;
	int		width;
	int		height;
	short	nb_planes;
	short	bpp;
	int		compression;
	int		size_img;
	int		horizontal_resolution;
	int		vertical_resolution;
	int		color_array;
	int		color_img_array;
}	t_img_header;

typedef struct s_header
{
	char			signature[2];
	int				size;
	int				reserved;
	int				offset_img;
	t_img_header	img_header;
}	t_header;

int			bmp(t_parsage *pars, char *lien);
int			get_correction_byte(int image_width);
t_header	fill_bmp_header(t_reso img_res);
t_bmp		ft_mlx_pixel_get_3(t_img texture, int x, int y, t_parsage pars);
void		fill_bmp(t_header header, int fd, t_parsage pars);
int			save_bmp(t_reso img_res, t_parsage pars);
int			ft_mouv_raycasting_bmp(t_parsage *pars, t_search_cub *search);
int			ft_protocol_raycasting_bmp(t_parsage *pars);
void		ft_close_vm(t_parsage *pars);
int			ft_close_programe(t_parsage *pars, int choose);
int			ft_suite(t_parsage *pars, int ac, char **av);
float		ft_absolut_2(float x);
void		ft_trie_tab(t_obj *obj);
void		ft_calcul_ray(float y, t_obj *obj, t_vecteur perso);
void		ft_calcul_pos_x(t_parsage *pars, t_obj *obj);
void		ft_taille_obj(t_parsage *pars);
void		ft_init_ray_dist_trie(t_parsage *pars, t_vecteur perso);
int			ft_mlx_pixel_get_2(t_tex texture, int x, int y, t_parsage pars);
int			ft_verif_cub_devant(t_obj obj, t_parsage pars, int x);
int			ft_init_my_draw_pixel_2(t_parsage pars, t_obj *obj, float x);
void		ft_init_drow_obj(t_parsage pars, t_obj *obj);
void		ft_cam_rot(t_parsage *pars, int key);
void		ft_mouv_pos(t_vecteur mouv, float ray, t_vecteur *perso);
void		ft_calcul_deplacement(float multiple, float angle, t_vecteur *v);
void		ft_calcule_vecteur_mouv(t_parsage *pars, float ray);
void		ft_protocole_recup(char *line, int *x, int *rgb);
void		ft_protocole_compte_nb(char *line, int *conteur, char para);
int			ft_verif_nb_nombre(char *lien, char para);
int			ft_verif_cara_C_F(char *lien, char para);
int			ft_protocole_recup_ciel_terre(char *line, char para, int *res);
int			ft_memorise_ciel_terre(t_parsage *pars, char *lien,
				char para, int choose);
int			ft_protocole_verif_format(char *line, int *x);
int			ft_verif_format(char *lien, char para);
int			ft_verif_cara(char *str, char cara);
int			ft_verif_line(char *line, char *str);
int			ft_verif_dernier_line_info_cub(char *lien);
int			ft_verif_lien_info_cub(char *lien, t_parsage *pars);
int			ft_erreur(char *erreur, int x);
int			ft_lance_parsage(t_parsage *pars, char *lien);
void		ft_netoyage(char **map);
int			ft_rempli_perso(t_parsage *pars, t_tmp *test,
				char **map, int conteur);
void		ft_recherche_perso_2(char **map, t_tmp *test, int *y, int *conteur);
int			ft_recherche_perso(char **map, t_tmp *test, t_parsage *pars);
int			ft_bloker(int y, int x, t_parsage *pars);
int			ft_remplie_valeur(t_parsage *pars, t_tmp *test,
				int option, t_tmp2 *a);
int			ft_choose_case(t_parsage *pars, t_tmp *test);
int			ft_test(t_parsage *pars, t_tmp test, int *res);
int			ft_init_test_map(t_parsage *pars);
int			ft_free(t_parsage *pars, int x, int taille);
int			ft_verif_nb(int fd);
int			ft_copie_line(char *map, char *line);
int			ft_init_copie(t_parsage *pars, char *line, int *w, int taille);
int			ft_init_map(t_parsage *pars, int taille, int fd, int *w);
int			ft_trouve_map(int fd);
int			ft_verif_dernier_line_map(t_parsage *pars);
int			ft_recup_map(t_parsage *pars);
int			ft_compte(t_parsage *pars);
int			ft_malloc_obj(t_parsage *pars);
int			ft_init_val(t_parsage *pars);
int			ft_init_obj(t_parsage *pars);
void		ft_init_ray_avant(t_parsage *pars);
void		ft_ajust_ray(float *ray);
void		ft_init_autre_ray(t_parsage *pars);
void		ft_init_ray(t_parsage *pars);
int			ft_protocole_verif_nombre(char *line, int *conteur);
int			ft_verif_nombre(char *lien);
void		ft_protocole_memorise(char *line, t_parsage *pars);
int			ft_memorise_nb_reso(t_parsage *pars, char *lien);
int			ft_init_recup_reso(t_parsage *pars, char *lien);
int			ft_verif_nb_para_texture(char *lien, char *para);
void		ft_protocole_verif_format_1(char *line, int *x, int *verif);
int			ft_verif_format_texture(char *lien, char *para);
int			ft_init_verif_texture(char *lien);
void		ft_init_mlx(t_parsage *pars);
int			ft_init_texture(char *line, t_parsage *pars, int index);
int			ft_choose_texture(t_parsage *pars, char *line);
int			ft_memorise_texture(t_parsage *pars, char *lien);
void		ft_procedure_verif_para(int *conteur, char *line, char para);
int			ft_verif_nb_para(char *lien, char para);
int			ft_fonction_fermeture_free(int fd, char *line, int retour);
int			ft_clik(int key, t_parsage *pars);
int			ft_de_clik(int key, t_parsage *pars);
int			protocole_draw(t_parsage *pars);
int			new_image(t_parsage *pars);
void		ft_init_my_draw_pixel(t_search_cub search, t_vecteur para,
				t_vecteur pos, t_parsage pars);
void		ft_drow_cub(t_parsage pars, int x, t_search_cub search);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			ft_choose_color(t_parsage pars, t_search_cub search);
int			ft_mlx_pixel_get(t_tex texture, int x, int y);
t_vecteur	ft_recup_coef(t_vecteur res, int y, int debut, int taille);
void		ft_init_d_perso(t_vecteur perso, t_vecteur *d_perso, float ray);
float		ft_init_angle(float vue);
int			ft_mouv_raycasting(t_parsage *pars, t_search_cub *search);
int			ft_protocol_raycasting(t_parsage *pars);
void		ft_calcul_search_res(t_search_cub *search, t_vecteur *v,
				t_vecteur *h);
void		ft_calcul_ad(float angle, t_vecteur *v, float multiple);
void		ft_calcul_op(float angle, t_vecteur *h, float multiple);
void		ft_fusion_vecteur_perso(t_vecteur *v, t_vecteur *h,
				float ray, t_vecteur perso);
float		ft_calcul_x(float x);
void		ft_search_cub(t_search_cub *search);
int			ft_init_recup_ciel_terre(t_parsage *pars, char *lien);
void		ft_rempli_case_centre(t_parsage *pars, t_tmp test2,
				int *res, t_tmp2 a);

#endif
