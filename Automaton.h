#define FALSE 0
#define TRUE 1
#define UNDEFINED -1
#define EPSILON 0

typedef int bool;

typedef struct {
    int symbol;
    int destination;
} Arc;

typedef struct {
    int num_arcs;
    bool is_final;
    Arc* arcs;
} State;

typedef struct {
    int num_states;
    int initial_state;
    State* states;
} Automaton;

Automaton* create_automaton();
void destroy_automaton(Automaton* a);

int add_state(Automaton* a);
void add_arc(Automaton* a, int from, int to, int symbol);

bool has_state(Automaton* a, int state);
bool has_arc(Automaton* a, int from, int to, int symbol);

Automaton* copy_automaton(Automaton* a);

void set_initial(Automaton *a, int state);
void set_final(Automaton *a, int state);
void print_automaton(Automaton* a);
