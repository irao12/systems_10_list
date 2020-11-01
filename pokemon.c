#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

struct pokemon *new_pokemon(char * n, int l, int h){

  struct pokemon *np;

  np = malloc(sizeof(struct pokemon));
  strncpy(np->name, n, sizeof(np->name)-1);
  np -> level = l;
  np -> hp = h;

  return np;
}

void change_pokemon (struct pokemon* pokepal, char* new_name, int new_level, int new_hp){
    strncpy(pokepal->name, new_name, sizeof(pokepal->name)-1);
    pokepal -> level = new_level;
    pokepal -> hp = new_hp;
}

struct pokemon* release_pokemon(struct pokemon* pokepal){
    printf("Freeing: %s\n", pokepal->name);
    free(pokepal);
    return NULL;
}

void print_pokemon(struct pokemon *pokepal){
  printf("Level %d %s\nHP: %d\n",
    pokepal->level,pokepal->name,pokepal->hp);
}

void print_list(struct pokemon * pokepal){
  if(!pokepal)printf("Empty Party\n");
  while (pokepal){
      print_pokemon(pokepal);
        pokepal = pokepal->next;
  }
}

struct pokemon * insert_front(struct pokemon * first, char n[128],
                              int l, int h){
  struct pokemon * new_first;
  new_first = new_pokemon(n,l,h);
  new_first -> next = first;
  return new_first;
}


struct pokemon * remove_node(struct pokemon * front, char n[128], int l, int h){
    if (!strcmp(front->name,n) && front->level==l && front->hp==h){
      return front->next;
    }
    struct pokemon * current = front -> next;
    struct pokemon * previous = front;
    while (current){
      if ((!strcmp(current->name,n) && current->level==l && current->hp==h)){
        previous->next = current->next;
        break;
      }
      previous = current;
      current = previous ->next;
    }
    return front;
}

struct pokemon * free_list(struct pokemon * pokepal){
  struct pokemon * current = pokepal;
  struct pokemon * next_pokepal;
  while (current){
      next_pokepal = current -> next;
      pokepal = release_pokemon(current);
      current = next_pokepal;
  }
  return pokepal;
}
