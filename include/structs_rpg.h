/*
** EPITECH PROJECT, 2021
** structs
** File description:
** structs for myrpg
*/

#ifndef STRUCT_RPG
#define STRUCT_RPG

typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    int offset;
    int max_value;
} image_t;

//// PROJECTILES ////
typedef struct projectile_s {
    int type;
    sfVector2f pos;
    sfVector2f direction;
    int damage;
    int speed;
    int travelling;
} projectile_t;

typedef struct e_projectile_s {
    int type;
    sfVector2f pos;
    sfVector2f dir;
    int dmg;
    int spd;
    int travelling;
    sfClock *clock;
    sfTime time;
    float seconds;
} e_projectile_t;
/////////////////////

//// ENEMIES ////
typedef struct enemy_s {
    int type;
    int health;
    int spd;
    sfVector2f pos;
    sfVector2f dir;
    e_projectile_t **projectiles;
    sfClock *clock;
    sfTime time;
    float seconds;
} enemy_t;

/////////////////

//// TOWER ////
typedef struct tower_clocks_s {
    sfClock *e_clock;
    sfTime e_time;
    float e_seconds;
    sfClock *p_clock;
    sfTime p_time;
    float p_seconds;
} tower_clocks_t;

typedef struct tower_s {
    int floor;
    image_t *background;
    image_t **e_sprites;
    image_t **p_sprites;
    enemy_t **enemies;
    tower_clocks_t *clocks;
} tower_t;
///////////////

typedef struct drop_dictionary_s {
    image_t *sprite;
    int defense;
    int health;
    int speed;
    int attack;
} drop_dictionary_t;

typedef struct object_s {
    int defense;
    int health;
    int speed;
    int attack;
    int is_empty;
    sfVector2f pos;
    int type;
} object_t;

typedef struct player_s {
    sfVector2f pos;
    int health;
    int attack;
    int defense;
    int speed;
    int move;
    projectile_t **projectiles;
    image_t *proj_sprite;
    object_t **inventory;
} player_t;

typedef struct render_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i pos_click;
    sfVector2i pos_mouse;
    sfClock *clock_refresh;
    sfTime time_refresh;
    sfView *view;
    float seconds;
    int fps;
} render_t;

typedef struct fps_s {
    char *fps_msg;
    sfText *text;
    sfFont *font;
} fps_t;

typedef struct vol_s {
    char *vol_msg;
    sfText *text;
    sfFont *font;
} vol_t;

typedef struct msg_pause_t{
    char *msg;
    sfText *text;
    sfFont *font;
} msg_pause_s;

typedef struct audio_s {
    sfSound * ost;
    sfSoundBuffer *ost_buffer;
    int volume;
} audio_t;

typedef struct stats_s {
    sfText *text;
    sfFont *font;
    char *lvl;
    char *health_bar;
    char *bullets;
    char *attack_txt;
    char *defend_txt;
    char *speed_txt;
} stats_t;

typedef struct game_s {
    render_t *render_info;
    player_t *player;
    tower_t *tower;
    msg_pause_s *msg_settings;
    msg_pause_s *msg_exit;
    msg_pause_s *msg_return;
    msg_pause_s *msg_menu;
    int is_click;
    int key_pressed;
    int current;
    int before_pause;
    int before_settings;
    int max_floor;
    int shoot_type;
    fps_t *fps;
    vol_t *vol;
    image_t **image;
    audio_t *audio_storms;
    stats_t *stats;
    audio_t *audio;
    drop_dictionary_t **drops;
} game_t;

typedef struct button {
    sfVector2f pos;
    sfVector2f size;
    void (*fn)(game_t *game);
    image_t *unpressed;
    image_t *hover;
    int is_clicked;
} button;

typedef struct scene_s {
    button **buttons;
    image_t **sprites;
} scene_t;


#endif /* !STRUCT_RPG */