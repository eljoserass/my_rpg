/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** my rpg header file
*/


#ifndef MY_RPG_
#define MY_RPG_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "structs_rpg.h"
#include "macros_rpg.h"

//// utils ////
int print_usage(void);
int my_strcmp(const char *s1, const char *s2);
void animate_sprite(sfIntRect *rect, int offset, int max_value);
int is_in_button(button *button, sfVector2i pos);
unsigned int my_strlen(const char *str);
char *my_strcat(char *sone, char *stwo);
int my_getnbr(char const *str);
char *remove_end_separators(char *str, char *separators);
char **str_to_array(char const *str, char *separators);
char **my_str_to_word_array(char const *str, char *lim);
char **my_str_to_word_array_chardelim(char const *str, char lim);
void free_char_array(char **array);
void my_putstr(char const *str);
char *my_strcat_int(char *str, int number);
void init_audio(game_t * game);
    //// file_management ////
char *macro_to_path(char *macro, int n);
char *my_strcpy(char *dest, char const *str);
char *my_itoa(int num, int size, int base);
    //// file_manegment ////
    int read_file(int fd, char *buf, int size);
    int get_size(char *file);
    char *get_file(char *file);
    ////////////////////////
////////////////////////


/// init ///
button *init_button(sfVector2f pos, sfVector2f size);
sfRenderWindow *init_window(int width, int height, char *name);
image_t *init_image(char *path, sfIntRect rect, sfVector2f pos, int max_value);
image_t *init_image_center(char *path, sfIntRect rect, sfVector2f pos, int max_value);
game_t *init_game_struct(void);
void init_view(game_t *game, scene_t **scenes);
scene_t **init_scenes(void);
int init_resources(game_t **game, scene_t ***scenes);
button **init_buttons_menu (scene_t *scenes);
button **init_buttons_pause(scene_t *scenes);
button **init_buttons_settings (scene_t *scenes);
////////////

//// main loop ////
void do_main_loop(game_t *game, scene_t **scenes);
///////////////////

//// do rpg ////
int do_my_rpg(void);
///////////////

//// player ////
int player_in_stairs(game_t *game);
void is_player_dead(game_t *game);
////////////////

//// events ////
void get_event(game_t *game); 
////////////////

//// refresh ////
void refresh_menu(game_t *game, scene_t *scene);
void refresh_game(game_t *game, scene_t *scene);
void refresh_pause(game_t *game, scene_t *scene);
void refresh_window(game_t *game, scene_t **scene);
void refresh_button(scene_t *scene, game_t *game);
void refresh_settings(game_t *game, scene_t *scene);
/////////////////

//// tower ////
void refresh_tower(game_t *game);
void fill_tower_floor(game_t *game, int floor);
void animate_tower(game_t *game);
void change_tower_floor(game_t *game, int new_floor);
void check_tower_floor(game_t *game, enemy_t **enemies);
void check_proj_collision(game_t *game, enemy_t **enemies, projectile_t *projectile);
    //// init ////
    int init_tower(game_t *game);
    void init_enemy_sprites(game_t *game);
    void init_e_projectiles(game_t *game);
    //////////////
    //// draw ////
    void draw_tower(game_t *game);
    //////////////
///////////////

//// enemies ////
enemy_t *generate_enemy(game_t *game ,int type, sfVector2f pos);
void move_enemy(game_t *game, enemy_t *enemy, sfIntRect rect);
void animate_enemies(game_t *game, tower_clocks_t *clocks);
sfVector2f enemy_chase_dir(game_t *game, sfVector2f e_pos);
sfVector2f enemy_roam_dir(sfVector2f e_pos);
void spawn_boss(game_t *game);
void refresh_boss(game_t *game);
void enemy_health_buff(tower_t *tower);
    //// refresh ////
    void refresh_enemy(game_t *game, enemy_t *enemy, sfIntRect rect);
    void refresh_enemies(game_t *game);
    /////////////////
    //// types ////
    void enemy_goblin(enemy_t *enemy);
    void enemy_orc(enemy_t *enemy);
    void enemy_ogre(enemy_t *enemy);
    ///////////////
    //// move ////
    void roam_phase(game_t *game);
    void chase_phase(game_t *game);
    void chase(game_t *game, enemy_t *enemy, sfIntRect rect);
    void roam(game_t *game, enemy_t *enemy, sfIntRect rect);
    //////////////
    //// projectiles ////
    e_projectile_t **projectile_array(int n, int type);
    void animate_e_projectiles(game_t *game, tower_clocks_t *clocks);
    void shoot_e_projectile(game_t *game, enemy_t *enemy);
    void move_e_projectile(e_projectile_t *projectile, sfIntRect rect);
        //// refresh ////
        void refresh_e_projectiles(game_t *game);
        /////////////////
    /////////////////////
/////////////////

//// projectiles ////
projectile_t **init_projectiles(int n_proyectiles);
void shoot_projectile(game_t *game);
int count_active(game_t *game);
int count_e_active(enemy_t *enemy);
void angle_e_projectile(enemy_t *enemy, float angle, int i);
void e_projectile_dir(game_t *game, enemy_t *enemy, int i);
void shoot_projectile_2(game_t *game);
void move_projectile(projectile_t *projectile, sfIntRect rect);
    //// types ////
    void projectile_types(e_projectile_t *projectile, int type);
    ///////////////
    //// shooting ////
    void shooting_patterns(game_t *game, enemy_t *enemy);
    //// draw ////
    void draw_e_projectiles(game_t *game, int n);
    //////////////
/////////////////////

////  draw ////
    //// draw_scene ////
void draw_scenes_button_sprites(game_t *game, scene_t *scene);
void draw_scene_sprites(game_t *game, scene_t *scene);
    ////////////////////
void draw_menu(game_t *game, scene_t *scenes);
void draw_game(game_t *game, scene_t *scenes);
void draw_pause(game_t *game, scene_t *scenes);
void draw_window(game_t *game, scene_t **scenes);
void draw_settings(game_t *game, scene_t *scenes);
void draw_inventory(game_t *game);
///////////////

//// menu buttons functions ////
void close_window (game_t *game);
void change_to_game(game_t *game);
void display_help(game_t *game);
void change_to_pause(game_t *game);
void return_to_scene(game_t *game);
void change_to_settings(game_t *game);
void return_first_scene(game_t *game);
////////////////////////////////

//// camera_movements ////
void do_unzoom(sfRenderWindow *window, sfSprite *sprite);
void do_zoom(sfRenderWindow *window, sfSprite *sprite);
void do_zoom_effect(sfRenderWindow *window, sfSprite *sprite);
/////////////////////////

//// settings buttons functions ////
void back_function (game_t *game);
void fps_func(game_t *game);
void vol_func(game_t *game);
////////////////////////////////////

//// inventory ////
void add_drop_stat(game_t *game, int pos);
int add_item(game_t *game, int id);
///////////////////

#endif /* !MY_RPG_ */
