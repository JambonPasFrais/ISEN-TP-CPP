#include "graphe.h"

graphe::graphe() {
	vector<int>tempVec;
	//On initialise toutes les cases à 0
	for (int j = 0; j < nombreDeVilles; j++) {
		tempVec.push_back(0);
	}
	for (int i = 0; i < nombreDeVilles; i++) {
		this->grapheEtCapacites.push_back(tempVec);
	}

	//On initialise quelques cases de manières spécifiques
	this->grapheEtCapacites[0][1] = 50;
	this->grapheEtCapacites[0][2] = 70;
	this->grapheEtCapacites[0][3] = 40;
	this->grapheEtCapacites[1][4] = 60;
	this->grapheEtCapacites[2][4] = 40;
	this->grapheEtCapacites[2][5] = 50;
	this->grapheEtCapacites[4][6] = 80;
	this->grapheEtCapacites[5][6] = 70;
}

bool parcoursLargeur(vector<vector<int>> grapheEtCapacites, int s, int t, int cheminAmeliorant[nombreDeVilles]) {
	if (s > t) {
		return false;
	}

	bool sommetVisite[nombreDeVilles];
	queue<int>file;

	for (int i = 0; i < nombreDeVilles; i++) {
		sommetVisite[i] = false;//Initialisation à false
	}

	//Le sommet de départ est push
	file.push(s);
	sommetVisite[s] = true;//Le sommet a été visité
	cheminAmeliorant[s] = -1;

	int u;
	while (!file.empty()) {
		u = file.front();
		file.pop();
		for (int v = 0; v < nombreDeVilles; v++) {
			if (sommetVisite[v] == false && grapheEtCapacites[u][v] != 0) {
				file.push(v);
				cheminAmeliorant[v] = u;
				sommetVisite[v] = true;
			}
		}
	}

	return sommetVisite[t];
}

//Partie 2 étape 3
int fordFulkerson(vector<vector<int>>grapheEtCapacites, int s, int t) {
	int u = 0, v = 0;
	vector<vector<int>> grapheResiduel;
	vector<int>tempVec;
	int cheminAmeliorant[nombreDeVilles];
	int max_flow = 0;//Valeur de retour
	int ameliorationFlot = 0;

	//Initialisation
	for (int i = 0; i < nombreDeVilles; i++) {
		for (auto value : grapheEtCapacites[i]) {
			tempVec.push_back(value);
		}
		grapheResiduel.push_back(tempVec);
		tempVec.erase(tempVec.begin(), tempVec.end());
	}

	while (parcoursLargeur(grapheResiduel, s, t, cheminAmeliorant))
	{
		ameliorationFlot = INFINI;
		for (v = t; v != s; v = cheminAmeliorant[v]) {
			u = cheminAmeliorant[v];
			ameliorationFlot = min(ameliorationFlot, grapheResiduel[u][v]);
			//cout << ameliorationFlot << endl;
		}
		for (v = t; v != s; v = cheminAmeliorant[v]) {
			u = cheminAmeliorant[v];
			grapheResiduel[u][v] -= ameliorationFlot;
			grapheResiduel[v][u] += ameliorationFlot;
		}
		max_flow += ameliorationFlot;
	}

	return max_flow;
}