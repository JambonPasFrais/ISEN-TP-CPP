#include "Graphe.h"
template<typename T>
Graphe<T>::Graphe() {
	this->vecSommets.push_back("neverland");
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		for (int j = 0; j < TAILLEDUGRAPHE; j++) {
			this->arcs[i][j] = INFINI;
			this->cheminCourt[i][j] = INFINI;
			this->pointChemin[i][j] = -1;
		}
	}
}
template<typename T>
void Graphe<T>::displayGraphe() {
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
template<typename T>
void Graphe<T>::setVecSommets(vector<string>villes) {
	this->vecSommets.pop_back();
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		this->vecSommets.push_back(villes[i]);
	}
}
template<typename T>
void Graphe<T>::setDistance(int index, int index2, int value) {
	if (index2 <= TAILLEDUGRAPHE - 1 && index < index2) {
		this->arcs[index][index2] = value;
		this->cheminCourt[index][index2] = value;
	}	
}
template<typename T>
void Graphe<T>::updatePointChemin() {
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		for (int j = 0; j < TAILLEDUGRAPHE; j++) {
			if (this->arcs[i][j] != INFINI) {
				this->pointChemin[i][j] = i;
			}
		}
	}
}
template<typename T>
void Graphe<T>::fwAlgorithm() {
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
template<typename T>
void Graphe<T>::displayChemin(int sommet1, int sommet2, bool& premier) const {
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