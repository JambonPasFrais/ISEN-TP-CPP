#include "Graphe.h"

Graphe<string>::Graphe() {
	this->vecSommets.push_back("neverland");
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		for (int j = 0; j < TAILLEDUGRAPHE; j++) {
			this->arcs[i][j] = INFINI;
			this->cheminCourt[i][j] = INFINI;
			this->pointChemin[i][j] = INFINI;
		}
	}
}