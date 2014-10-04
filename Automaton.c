#include <stdio.h>
#include <stdlib.h>
#include "Automaton.h"


Automaton* create_automaton()
{
    Automaton* a;
    
    a=realloc(NULL,sizeof (Automaton));
    
    a->initial_state=-1;
    a->num_states=0;
    a->states=NULL;
    
    
    return a;
    
}

void print_automaton(Automaton *a)
{
	if (a->initial_state != -1){

		for (int k = 0; k < a->states[a->initial_state].num_arcs; k++)
			printf("%d  %d  %d \n", a->initial_state, a->states[a->initial_state].arcs[k].destination, a->states[a->initial_state].arcs[k].symbol);

	
		for (int i = 0; i < a->num_states; i++){
	
			if(i != a->initial_state){
				for (int j = 0; j < a->states[i].num_arcs; j++){
					printf("%d  %d  %d \n", i, a->states[i].arcs[j].destination, a->states[i].arcs[j].symbol);	
				
			}
			
			if(a->states[i].is_final == TRUE)
				for (int j = 0; j < a->states[i].num_arcs; j++)
					printf("%d  %d  %d \n", i, a->states[i].arcs[j].destination, a->states[i].arcs[j].symbol);
				
				
				
				
			}

		}
		
	}
	
}
     
void destroy_automaton(Automaton* a)
{
    
	free(&(a->states->arcs));
	free(&(a->states));
	free(a);
    
}    

Automaton* copy_automaton(Automaton* a)
{
	Automaton *b;
	b=create_automaton();
	b->num_states=a->num_states;
	b->initial_state=a->initial_state;
	
	
	for(int i=0;i<b->num_states;i++)
	{	
		b->states[i].is_final=a->states[i].is_final;
		b->states[i].num_arcs=a->states[i].num_arcs;
		
		for(int j=0;j<b->num_states;j++)
		{
			b->states[i].arcs[j].symbol=a->states[i].arcs[j].symbol;
			b->states[i].arcs[j].destination=a->states[i].arcs[j].destination;
			
			
		}
	
		
	}
	return b;
}
void set_final(Automaton *a, int state)
{
	a->states[state].is_final=TRUE;

}
void set_initial(Automaton *a, int state)
{
	a->initial_state=state;
}
int add_state (Automaton* a)
{
	
	a->num_states=a->num_states+1;
	a->states=realloc(a->states, sizeof(State)*a->num_states);
	
	a->states[a->num_states-1].num_arcs=0;
	a->states[a->num_states-1].is_final=FALSE;
	a->states[a->num_states-1].arcs=NULL;
	
	return a->num_states-1;
	
}

bool has_state(Automaton *a, int state)
{
	return (state>=0 || (state< a->num_states));

}

bool has_arc(Automaton *a, int from, int to, int symbol)
{
	if(a->states[from].num_arcs==0)
		return 0;
	for(int i=0;i<a->states[from].num_arcs; i++)
	{	if(a->states[from].arcs[i].symbol==to)
			return 1;
	}		
	return 0;

}



void add_arc(Automaton *a, int from, int to, int symbol)
{
	
	if((has_state(a,from)==1) && (has_state(a,to)==1))
	{	
		if (has_arc(a,from,to,symbol)==0)
		{
			a->states[from].num_arcs=a->states[from].num_arcs+1;
			a->states[from].arcs=realloc(a->states[from].arcs,sizeof (Arc)*a->states[from].num_arcs);
			
			
			a->states[from].arcs[a->states[from].num_arcs-1].symbol=symbol;
			a->states[from].arcs[a->states[from].num_arcs-1].destination=to;
		}
	}
}





	






