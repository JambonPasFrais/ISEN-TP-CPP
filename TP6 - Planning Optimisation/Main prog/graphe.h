#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <array>

constexpr int nombreDeVilles = 7;
constexpr int INFINI = 99999;

using namespace std;

class graphe
{
private:
	vector<vector<int>>grapheEtCapacites;
public:
	graphe();
};

bool parcoursLargeur(vector<vector<int>> grapheEtCapacites, int s, int t, array<int, nombreDeVilles>cheminAmeliorant);
int fordFulkerson(vector<vector<int>>, int, int);
