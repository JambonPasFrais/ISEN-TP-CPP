// Main prog.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

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


	return EXIT_SUCCESS;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
