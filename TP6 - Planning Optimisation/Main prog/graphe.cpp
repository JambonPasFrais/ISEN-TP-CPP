#include "graphe.h"

graphe::graphe() {
	//On initialise toutes les cases à l'infini
	for (int i = 0; i < nombreDeVilles; i++) {
		for (int j = 0; j < nombreDeVilles; j++) {
			this->grapheEtCapacites[i].push_back(0);
		}
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

bool parcoursLargeur(vector<vector<int>> grapheEtCapacites, int s, int t, array<int, nombreDeVilles>cheminAmeliorant) {
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
			if (sommetVisite[v] == false && grapheEtCapacites[v][u] != 0) {
				file.push(v);
				cheminAmeliorant[v] = u;
				sommetVisite[v] = true;
			}
		}
	}

	return sommetVisite[t];
}

//Partie 2 étape 3
int fordFulkerson(vector<vector<int>>grapeEtCapacites, int s, int t) {
	int u, v, j = 0;
	vector<vector<int>> grapheResiduel;
	array<int, nombreDeVilles>cheminAmeliorant;
	cheminAmeliorant.fill(-1);
	int max_flow = 0;//Valeur de retour
	int ameliorationFlot;

	//Initialisation
	for (int i : grapeEtCapacites[j]) {
		grapheResiduel[j].push_back(i);
		j++;
	}

	while (parcoursLargeur(grapeEtCapacites, s, t, cheminAmeliorant))
	{
		ameliorationFlot = INFINI;
		for (int v = t; v < s; v++) {
			u = cheminAmeliorant[v];
			ameliorationFlot = min(ameliorationFlot, grapheResiduel[u][v]);
		}
		for (int v = t; v < s; v++) {
			u = cheminAmeliorant[v];
			grapheResiduel[u][v] -= ameliorationFlot;
			grapheResiduel[v][u] += ameliorationFlot;
			max_flow += grapheResiduel[v][u];
		}
	}

	return max_flow;
}