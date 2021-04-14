#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <array>
#include <locale>

constexpr int nombreDeVilles = 5;
constexpr int INFINI = 99999;

using namespace std;

class graphe
{
private:
	vector<vector<int>>grapheEtCapacites;
public:
	graphe();
};

bool parcoursLargeur(vector<vector<int>> grapheEtCapacites, int s, int t, int cheminAmeliorant[nombreDeVilles]);
int fordFulkerson(vector<vector<int>>, int, int);
