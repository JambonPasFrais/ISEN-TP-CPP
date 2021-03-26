#include "Graphe.h"
Graphe<string>::Graphe() {
	this->vecSommets.push_back("neverland");
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		for (int j = 0; j < TAILLEDUGRAPHE; j++) {
			this->arcs[i][j] = INFINI;
			this->cheminCourt[i][j] = INFINI;
			this->pointChemin[i][j] = -1;
		}
	}
}
void Graphe<string>::displayGraphe() {
	//Display names
	for (string i : this->vecSommets) {
		cout << i << ' ';
	}
	cout << endl;
	//Distance associated
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		for (int j = 0; j < TAILLEDUGRAPHE; j++) {
			cout << this->arcs[i][j] << ' ';
		}
		cout << endl;
	}
	//Display points
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		for (int j = 0; j < TAILLEDUGRAPHE; j++) {
			cout << this->pointChemin[i][j] << ' ';
		}
		cout << endl;
	}
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
		this->cheminCourt[index][index2] = value;
	}	
}
void Graphe<string>::updatePointChemin() {
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		for (int j = 0; j < TAILLEDUGRAPHE; j++) {
			if (this->arcs[i][j] != INFINI) {
				this->pointChemin[i][j] = i;
			}
		}
	}
}
void Graphe<string>::fwAlgorithm() {
	for (int sommetIntermédiaire = 1; sommetIntermédiaire < TAILLEDUGRAPHE; sommetIntermédiaire++) {
		for (int index = 1; index < TAILLEDUGRAPHE; index++) {
			for (int destination = 1; destination < TAILLEDUGRAPHE; destination++) {
				if (this->cheminCourt[index][sommetIntermédiaire] + this->cheminCourt[sommetIntermédiaire][destination] < this->cheminCourt[index][destination]) {
					this->cheminCourt[index][destination] = this->cheminCourt[index][sommetIntermédiaire] + this->cheminCourt[sommetIntermédiaire][destination];
					this->pointChemin[index][destination] = sommetIntermédiaire;
				}
			}
		}
	}
}
void Graphe<string>::displayChemin(int sommet1, int sommet2, bool& premier) const {
	int suivant = pointChemin[sommet1][sommet2];
	if (suivant == -1 || sommet1 == sommet2 || suivant == sommet1 || suivant == sommet2)
		return;
	displayChemin(sommet1, suivant, premier);
	if (premier) {
		cout << " \t\t par ";
		premier = false;
	}
	else {
		cout << " et ";
	}
	cout << vecSommets[suivant];
	displayChemin(suivant, sommet2, premier);
}

void Graphe<string>::completedDisplayChemin() {

}