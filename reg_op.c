#include <stdio.h>
#include <stdlib.h>
#include "Automaton.h"


Automaton *elem (int symbol)
{
	
	




}

Automaton* Union (Automaton *a1 ,Automaton *a2)
{
	Automaton* c=create_automaton();
	
	c=copy_automaton(a1);
	for(int i=0;i<a2->num_states;i++)
	{
		c->states[i+c->num_states]=a2->states[i];
		
		for(int j=0;j<a2->states[i].num_arcs;j++)
		{
			c->states[i+c->num_states].arcs[j+c->num_states]=a2->states[i].arcs[j];
		}
		
	
	}
	
	
	set_initial(c,add_state(c));
	printf("d");;;;;;
	add_arc(c,c->initial_state,a1->initial_state,EPSILON);
	add_arc(c,c->initial_state,a2->initial_state,EPSILON);

}

Automaton *conc (){printf("caca";)}
