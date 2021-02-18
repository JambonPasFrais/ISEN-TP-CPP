//=========================================================================
/// \name allPermutationWithSTL.cpp
/// \version 1.1 (2020.2021)
/// \brief Algorithme combinatoire récursif
//=========================================================================
/* Remplacez l’include suivant par tous les #include de la STL nécessaires si
vous utilisez Visual Studio */

#include <iostream>
#include <vector>
#include<time.h>
#include <cstdlib>
#include <random>
#include <tuple>
#include <map>
#include <array>
#include <cmath>
#include <algorithm>
//#include <bits/stdc++.h>

constexpr int codeASCIIde_a = 97;
constexpr int codeASCIIde_A = 65;
constexpr int nombreDeLettres = 26;
constexpr int tailleMinNomVille = 4;
constexpr int tailleMaxNomVille = 12;
constexpr int grainePourLeRand = 1;
constexpr int nombreDeVilles = 4;
constexpr int nombreCombinaisons = 24;
constexpr int tailleCoteCarte = 100;

using namespace std;
void toutesLesPermutations(vector<string>villes, int debut, int fin);
void afficheMap(map<string, tuple<int, int, int>>maMapNomsVillesEtCoordonnees);
array<array<int, nombreDeVilles>, nombreDeVilles> calculDistances(map<string, tuple<int, int, int>>maMapNomsVillesEtCoordonnees);
int calculDistanceTotale(vector<string>allCities, array<array<int, nombreDeVilles>, nombreDeVilles>, map<string, tuple<int, int, int>>maMapNomsVillesEtCoordonnees);
void afficheMatriceDist(array<array<int, nombreDeVilles>, nombreDeVilles> DIST);
vector<pair<vector<string>, int>> toutesLesPermutationsV2(vector<string>tournee, int debut, int fin, array<array<int, nombreDeVilles>, nombreDeVilles>DIST, map<string, tuple<int, int, int>>maMapNomsVillesEtCoordonnees, vector<pair<vector<string>, int>>);

int main()
{
	setlocale(LC_ALL, "fr-Fr");

	//Random
	random_device nbRand;
	uniform_int_distribution<int>cityName{ 0, nombreDeLettres - 1 };
	uniform_int_distribution<int>cityNameSize{ tailleMinNomVille, tailleMaxNomVille };
	uniform_int_distribution<int>cityCoordonate{ 0, tailleCoteCarte };

	//Implementation
	int sizeNomVille = 0;
	string Ville;
	vector<string>vecteurDeNomsDeVille;
	auto cityCoordonates = make_tuple(0, 0, 0);
	map<string, tuple<int, int, int>>maMapNomsVillesEtCoordonnees;
	array<array<int, nombreDeVilles>, nombreDeVilles> DIST;
	
	//Generation aléatoire
	for (int i = 0; i < nombreDeVilles; i++) {
		//Partie 3
		sizeNomVille = cityNameSize(nbRand);//Taille du nom de la ville aléatoire
		Ville.erase(Ville.begin(), Ville.end());//On Supprime ce que contient Ville à chaque itération
		for (int j = 0; j < sizeNomVille; j++) {
			if (j == 0) {
				Ville.push_back('A' + cityName(nbRand));
			}
			else {
				Ville.push_back('a' + cityName(nbRand));
			}
		}
		//On Stocke le Nom dans un vecteur.
		vecteurDeNomsDeVille.push_back(Ville);
		//Fin Partie 3

		//Partie 4 
		cityCoordonates = make_tuple(i, cityCoordonate(nbRand), cityCoordonate(nbRand));//On modifie cityCoordonates à chaque fois
		maMapNomsVillesEtCoordonnees.insert(maMapNomsVillesEtCoordonnees.begin(), pair<string, tuple <int, int, int>>(Ville, cityCoordonates));
	}

	//afficheMap(maMapNomsVillesEtCoordonnees);
	//Fin Partie 4

	//Partie 5
	DIST = calculDistances(maMapNomsVillesEtCoordonnees);
	//Fin partie 5

	//Partie 6
	//afficheMap(maMapNomsVillesEtCoordonnees);
	//afficheMatriceDist(DIST);
	//toutesLesPermutations(vecteurDeNomsDeVille, 0, vecteurDeNomsDeVille.size() - 1);
	//Fin Partie 6

	//Partie 7
	vector<string>Tournée;
	//Test
	int TailleTournée = vecteurDeNomsDeVille.size();
	for (int i = 0; i < TailleTournée; i++) {
		Tournée.push_back(vecteurDeNomsDeVille[i]);
	}
	int distanceTournée = calculDistanceTotale(Tournée, DIST, maMapNomsVillesEtCoordonnees);

	vector<pair<vector<string>, int>>toutesLesTourneesEtLeurDistanceTotale = toutesLesPermutationsV2(vecteurDeNomsDeVille, 0, vecteurDeNomsDeVille.size() - 1, DIST, maMapNomsVillesEtCoordonnees, toutesLesTourneesEtLeurDistanceTotale);
	//Affichage
	/*for (int i = 0; i < toutesLesTourneesEtLeurDistanceTotale.size(); i++) {
		cout << "La tournée : ";
		for (int j = 0; j < toutesLesTourneesEtLeurDistanceTotale[i].first.size(); j++) {
			cout << toutesLesTourneesEtLeurDistanceTotale[i].first[j] << ' ';
		}
		cout << "a pour distance totale: " << toutesLesTourneesEtLeurDistanceTotale[i].second << endl;
	}*/



	return 0;
}
/// \brief Methode recursive generant l ensemble des mots possibles
/// avec les caractères du mots villes donne en parametre.
void toutesLesPermutations(vector<string>villes, int debut, int fin)
{
	if (debut == fin) {
		for (auto i : villes) {
			cout << i << ' ';
		}
		cout << endl;
	}	
	else{
		// Permutations made
		for (int i = debut; i <= fin; i++)
		{
			// echange des deux lettres
			swap(villes[debut], villes[i]);
			// Appel Recursif
			toutesLesPermutations(villes, debut + 1, fin);
			// On revient à la situation précédente
			swap(villes[debut], villes[i]);
		}
	}
}
//Partie 4
void afficheMap(map<string, tuple<int, int, int>>maMapNomsVillesEtCoordonnees) {
	map<string, tuple<int, int, int>>::iterator it;	
	for (it = maMapNomsVillesEtCoordonnees.begin(); it != maMapNomsVillesEtCoordonnees.end(); it++) {
		cout << "La ville " << it->first << " d'index " << get<0>(it->second) << ", a pour coordonnées en X: " << get<1>(it->second) << " Y: " << get<2>(it->second) << endl;
	}
}
//Partie 5
array<array<int, nombreDeVilles>, nombreDeVilles> calculDistances(map<string, tuple<int, int, int>>maMapNomsVillesEtCoordonnees) {
	array<array<int, nombreDeVilles>, nombreDeVilles> DIST;
	map<string, tuple<int, int, int>>::iterator it;
	map<string, tuple<int, int, int>>::iterator it2;
	it = maMapNomsVillesEtCoordonnees.begin();
	for (int i = 0; i < DIST.size(); i++) {
		it2 = maMapNomsVillesEtCoordonnees.begin();
		for (int j = 0; j < DIST.size(); j++) {
			if (i == j) {
				DIST[i][j] = 0;
			}
			else {
				DIST[i][j] = sqrt(pow(get<1>(it->second) - get<1>(it2->second), 2) + pow(get<2>(it->second) - get<2>(it2->second), 2));
			}
			it2++;
		}
		it++;
	}
	return DIST;
}
//Partie 6
void afficheMatriceDist(array<array<int, nombreDeVilles>, nombreDeVilles> DIST) {
	for (int i = 0; i < DIST.size(); i++) {
		for (int j = 0; j < DIST.size(); j++) {
			cout << "Distance entre ville " << i + 1 << " et ville " << j + 1 << " : " << DIST[i][j] << endl;
		}
	}
}
//Partie 7
int calculDistanceTotale(vector<string>allCities, array<array<int, nombreDeVilles>, nombreDeVilles>DIST, map<string, tuple<int, int, int>>maMapNomsVillesEtCoordonnees) {
	int j = 1, distanceTotale = 0;
	if (allCities.size() <= 1) {
		return 0;
	}
	for (int i = 0; i < allCities.size(); i++) {
		distanceTotale += DIST[get<0>(maMapNomsVillesEtCoordonnees[allCities[i]])][get<0>(maMapNomsVillesEtCoordonnees[allCities[j]])];
		j++;
		if (i == allCities.size() - 2) {
			j = 0;
		}
	}
	return distanceTotale;
}

vector<pair<vector<string>, int>>toutesLesPermutationsV2(vector<string>tournee, int debut, int fin, array<array<int, nombreDeVilles>, nombreDeVilles>DIST, map<string, tuple<int, int, int>>maMapNomsVillesEtCoordonnees, vector<pair<vector<string>, int>>tempTab){
	if (debut == fin) {
		pair<vector<string>, int>tempPair;
		for (auto i : tournee) {
			tempPair.first.push_back(i);
		}
		tempPair.second = calculDistanceTotale(tournee, DIST, maMapNomsVillesEtCoordonnees);
		tempTab.push_back(tempPair);
		
		tempPair.first.erase(tempPair.first.begin(), tempPair.first.end());	
	}
	else {
		// Permutations made
		for (int i = debut; i <= fin; i++)
		{
			// echange des deux lettres
			swap(tournee[debut], tournee[i]);
			// Appel Recursif
			tempTab = toutesLesPermutationsV2(tournee, debut + 1, fin, DIST, maMapNomsVillesEtCoordonnees, tempTab);
			// On revient à la situation précédente
			swap(tournee[debut], tournee[i]);
		}
	}
	return tempTab;
}