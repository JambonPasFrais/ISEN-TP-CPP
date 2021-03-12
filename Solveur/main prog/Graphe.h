#pragma once
#include <iostream>
#include <vector>

const int TAILLEDUGRAPHE = 6;
const int INFINI = 9999999;

using namespace std;


class Graphe
{
private:
	vector < string > vecSommets;
	int arcs[TAILLEDUGRAPHE][TAILLEDUGRAPHE];
	int cheminCourt[TAILLEDUGRAPHE][TAILLEDUGRAPHE];
	int pointChemin[TAILLEDUGRAPHE][TAILLEDUGRAPHE];

public:
	Graphe();
	//Graphe(vector<string>, int arcs[TAILLEDUGRAPHE][TAILLEDUGRAPHE], int cheminCourt[TAILLEDUGRAPHE][TAILLEDUGRAPHE], int pointChemin[TAILLEDUGRAPHE][TAILLEDUGRAPHE])
};

