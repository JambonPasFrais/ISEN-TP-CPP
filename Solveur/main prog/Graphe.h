#pragma once
#include <iostream>
#include <vector>

const int TAILLEDUGRAPHE = 6;
const int INFINI = 999;

using namespace std;

template <typename T>
class Graphe
{
private:
	vector <T> vecSommets;
	int arcs[TAILLEDUGRAPHE][TAILLEDUGRAPHE];
	int cheminCourt[TAILLEDUGRAPHE][TAILLEDUGRAPHE];//cheminCourt est une matrice de la même taille que arcs , c’est elle qui va sauvegarder la distance totale du Plus Court Chemin pour chaque couple de sommets.Ses valeurs de départ sont égales à celles de arcs .
	int pointChemin[TAILLEDUGRAPHE][TAILLEDUGRAPHE];

public:
	Graphe();
	//Graphe<T>(vector<string> nomsDesVilles, int dist[TAILLEDUGRAPHE][TAILLEDUGRAPHE], int pointsIntermediraires[TAILLEDUGRAPHE][TAILLEDUGRAPHE]);
	void displayGraphe();
	void setVecSommets(vector<string>);
	void setDistance(int, int, int);
	void updatePointChemin();
	void fwAlgorithm();
	void displayChemin(int, int, bool&) const;
};



/*Graphe<string>::Graphe(vector<string>nomsDesVilles, int dist[TAILLEDUGRAPHE][TAILLEDUGRAPHE], int pointsIntermediraires[TAILLEDUGRAPHE][TAILLEDUGRAPHE]) {
	for (string ville : nomsDesVilles) {
		this->vecSommets.push_back(ville);
	}
	for (int i = 0; i < TAILLEDUGRAPHE; i++) {
		for (int j = 0; j < TAILLEDUGRAPHE; j++) {
			this->arcs[i][j] = dist[i][j];
			this->cheminCourt[i][j] = this->arcs[i][j];
			this->pointChemin[i][j] = pointsIntermediraires[i][j];
		}
	}
}*/
