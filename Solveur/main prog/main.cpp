// main prog.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Graphe.h"

int main()
{
	setlocale(LC_ALL, "fr-Fr");

	Graphe<string>test;
	vector<string>villes;
	villes.push_back("Lille");
	villes.push_back("Lens");
	villes.push_back("Paris");
	villes.push_back("Bourges");
	villes.push_back("Clermont-Ferrand");
	villes.push_back("Montpellier");
	test.setVecSommets(villes);
	test.setDistance(0, 1, 40);
	test.setDistance(0, 2, 230);
	test.setDistance(1, 2, 200);
	test.setDistance(2, 3, 250);
	test.setDistance(2, 4, 425);
	test.setDistance(3, 4, 190);
	test.setDistance(4, 5, 300);
	test.updatePointChemin();
	test.fwAlgorithm();
	test.displayGraphe();
	bool value = true;
	test.displayChemin(0, 5, value);



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
