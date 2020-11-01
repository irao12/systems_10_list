#ifndef POKEMON_H
#define POKEMON_H

struct pokemon {
  char name [128];
  int level;
  int hp;
  struct pokemon * next;
};

struct pokemon * new_pokemon(char* n, int l, int h);

void change_pokemon (struct pokemon* pokepal, char* new_name, int new_level, int new_hp);

struct pokemon* release_pokemon (struct pokemon* pokepal);

void print_pokemon(struct pokemon *pokepal);

void print_list(struct pokemon * pokepal);

struct pokemon * insert_front(struct pokemon * first, char n[128],
                              int l, int h);

struct pokemon * free_list(struct pokemon * pokepal);

struct pokemon * remove_node(struct pokemon * front, char n[128], int l, int h);
#endif
