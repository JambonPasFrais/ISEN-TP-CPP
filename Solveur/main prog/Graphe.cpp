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
void Graphe<string>::displayGraphe() {
	for (string i : this->vecSommets) {
		cout << i << ' ';
	}
	cout << endl;
}

void Graphe<string>::setVecSommets(vector<string>villes) {
	this->vecSommets.pop_back();
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		this->vecSommets.push_back(villes[i]);
	}
}

void Graphe<string>::setDistance(int index, int index2, int value) {
	if (index2 <= TAILLEDUGRAPHE - 1 && index < index2) {
		this->arcs[index][index2] = value;
	}	
}