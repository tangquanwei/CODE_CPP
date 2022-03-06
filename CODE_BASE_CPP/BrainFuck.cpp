#include "BrainFuck.h"

int8_t* p = new int8_t[1 << 31 - 1]; 
int main(int argc, char const* argv[]) {
	memset(p, 0, 1 << 31 - 1);
    C C C C C C C C C G A C C C C C C C C C B D H  
    A C C C E A C C C C C C C C C C G A C C C C C C C C C C B D H 
    A D D D E A C C C C C C C C C C G A C C C C C C C C C C C B D H 
    A E A C C C C C C C C C C G A C C C C C C C C C C B D H  
    A C C C E A C C C C C C G A C C C C C C B D H 
    A D D D D E A C C C C C C C C C G A C C C C C C C C C B D H 
    A E A C C C C C C C C C C C C G A C C C C C C C C C C B D H
    A D D D E A C C C C C C C C C C G A C C C C C C C C C C B D H
    A D D D E A C C C C C C C C C C G A C C C C C C C C C C C B D H
    A E A C C C C C C C C C C C C G A C C C C C C C C C C B D H 
    A D E A C C C C C C C C C C G A C C C C C C C C C C B D H 
    A C E A C C C C C C C C C C G A C C C C C C C C C C B D H 
    A C C C C C E 
	return 0; 
}
