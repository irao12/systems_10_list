#include <stdio.h>
#include "pokemon.h"
#include <stdlib.h>

int main(){

   printf("Printing empty party:\n");
   struct pokemon* party = NULL;
   print_list(party);

   printf("\nAdding Bulbasaur, Charmander, Squirtle, Pidgey, and Rattata.\n");
   printf("Printing party:\n");
   party = insert_front(party, "Bulbasaur", 5, 30);
   party = insert_front(party, "Charmander", 5, 30);
   party = insert_front(party, "Squirtle", 5, 30);
   party = insert_front(party, "Rattata", 4, 25);
   party = insert_front(party, "Pidgey", 4, 25);
   print_list(party);

   printf("\nRemoving Squirtle:\n");
   party = remove_node(party, "Squirtle", 5, 30);
   print_list(party);
   printf("\nRemoving Pidgey:\n");
   party = remove_node(party, "Pidgey", 4, 25);
   print_list(party);
   printf("\nRemoving Mewtwo:\n");
   party = remove_node(party, "Mewtwo", 100, 200);
   print_list(party);

   printf("\nFreeing party:\n");
   party = free_list(party);

   printf("\nPrinting list:\n");
   print_list(party);
  return 0;
}
