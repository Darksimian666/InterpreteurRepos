#include <stdio.h>
#include <stdlib.h>
#include "Automaton.h"


int main ()
{
  Automaton *a = create_automaton();
  int e0 = add_state(a);
  int e1 = add_state(a);
  int e2 = add_state(a);
  
  set_initial(a, e1);
  set_final(a, e2);
  
  add_arc(a, e0, e1, 1);
  add_arc(a, e1, e1, 2);
  add_arc(a, e1, e2, 3);

  print_automaton(a);
  
  return 0;
}
