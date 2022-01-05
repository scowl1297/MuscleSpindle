#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _AXNODE_reg();
extern void _AfferentFiber_reg();
extern void _INITIAL_reg();
extern void _IntFireMn_reg();
extern void _MOTONEURON_reg();
extern void _MOTONEURON_5HT_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," AXNODE.mod");
fprintf(stderr," AfferentFiber.mod");
fprintf(stderr," INITIAL.mod");
fprintf(stderr," IntFireMn.mod");
fprintf(stderr," MOTONEURON.mod");
fprintf(stderr," MOTONEURON_5HT.mod");
fprintf(stderr, "\n");
    }
_AXNODE_reg();
_AfferentFiber_reg();
_INITIAL_reg();
_IntFireMn_reg();
_MOTONEURON_reg();
_MOTONEURON_5HT_reg();
}
