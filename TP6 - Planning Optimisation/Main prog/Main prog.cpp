// Main prog.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//Code by Armand DEFFRENNES alias Jambon

#include "graphe.h"

int main()
{
	setlocale(LC_ALL, "fr-FR");

	
	vector<vector<int>>grapheEtCapacites;
	vector<int>tempVec;
	//On initialise toutes les cases à 0
	for (int j = 0; j <= nombreDeVilles; j++) {
		tempVec.push_back(0);
	}
	for (int i = 0; i <= nombreDeVilles; i++) {
		grapheEtCapacites.push_back(tempVec);
	}
	//Partie 2
	/*
	//On initialise quelques cases de manières spécifiques
	grapheEtCapacites[0][1] = 50;
	grapheEtCapacites[0][2] = 70;
	grapheEtCapacites[0][3] = 40;
	grapheEtCapacites[1][4] = 60;
	grapheEtCapacites[2][4] = 40;
	grapheEtCapacites[2][5] = 50;
	grapheEtCapacites[3][5] = 30;
	grapheEtCapacites[4][6] = 80;
	grapheEtCapacites[5][6] = 70;

	//Partie 2.2
	int cheminAmeliorant[nombreDeVilles];
	// Test
	cout << boolalpha << parcoursLargeur(grapheEtCapacites, 0, 6, cheminAmeliorant) << endl;
	//Partie 2.3
	cout << fordFulkerson(grapheEtCapacites, 2, 6) << endl;
    //Partie 2.4
	cout << fordFulkerson(grapheEtCapacites, 0, 6) << endl;
	*/
	//Partie 3.1
	/*
	grapheEtCapacites[0][1] = INFINI;
	grapheEtCapacites[0][2] = INFINI;
	grapheEtCapacites[0][3] = INFINI;
	grapheEtCapacites[1][4] = 20;
	grapheEtCapacites[2][4] = 7;
	grapheEtCapacites[3][4] = 5;
	cout << "Production infinie: "<<fordFulkerson(grapheEtCapacites, 0, 4) << endl;*/
	//Partie 3.2
	/*
	grapheEtCapacites[0][1] = 25;
	grapheEtCapacites[0][2] = 10;
	grapheEtCapacites[0][3] = 8;
	grapheEtCapacites[1][4] = 20;
	grapheEtCapacites[2][4] = 7;
	grapheEtCapacites[3][4] = 5;
	cout << "Production Limitée "<<fordFulkerson(grapheEtCapacites, 0, 4)<<endl;
	*/
	//Partie 3.3
	/*
	grapheEtCapacites[0][1] = 25;
	grapheEtCapacites[0][2] = 10;
	grapheEtCapacites[0][3] = 8;
	grapheEtCapacites[1][4] = 30;
	grapheEtCapacites[1][3] = 12;
	grapheEtCapacites[1][2] = 8;
	grapheEtCapacites[2][4] = 7;
	grapheEtCapacites[2][1] = 8;
	grapheEtCapacites[2][3] = 3;
	grapheEtCapacites[3][2] = 3;
	grapheEtCapacites[3][1] = 12;
	grapheEtCapacites[3][4] = 5;
	cout << "Transfert et production limitées " << fordFulkerson(grapheEtCapacites, 0, 4);*/
	//Partie 3.4
	//Start
	grapheEtCapacites[0][1] = 25;
	grapheEtCapacites[0][2] = 15;
	grapheEtCapacites[0][3] = 10;
	grapheEtCapacites[0][4] = 5;
	grapheEtCapacites[0][5] = 5;
	grapheEtCapacites[0][6] = 8;
	//France Initialisation part 1
	grapheEtCapacites[1][2] = 15;
	grapheEtCapacites[1][3] = 10;
	grapheEtCapacites[1][5] = 10;
	grapheEtCapacites[1][7] = 14;
	//France Initialisation part 2
	grapheEtCapacites[2][4] = 5;
	grapheEtCapacites[2][6] = 5;
	grapheEtCapacites[2][7] = 19;
	//Belgium Initialisation part 1
	grapheEtCapacites[3][1] = 4;
	grapheEtCapacites[3][4] = 8;
	grapheEtCapacites[3][5] = 10;
	grapheEtCapacites[3][7] = 3;
	//Belgium Initialisation part 2
	grapheEtCapacites[4][2] = 8;
	grapheEtCapacites[4][6] = 5;
	grapheEtCapacites[4][7] = 10;
	//Switzerland Initialisation part 1
	grapheEtCapacites[5][1] = 4;
	grapheEtCapacites[5][3] = 10;
	grapheEtCapacites[5][6] = 7;
	grapheEtCapacites[5][7] = 7;
	//Switzerland Initialisation part 2
	grapheEtCapacites[6][2] = 7;
	grapheEtCapacites[6][4] = 5;
	grapheEtCapacites[6][7] = 5;
	cout << "flot_max = " << fordFulkerson(grapheEtCapacites, 0, 7);

	//Partie 4

	return EXIT_SUCCESS;
}