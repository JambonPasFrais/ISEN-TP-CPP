#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <array>

constexpr int nombreDeVilles = 6;
constexpr int INFINI = 99999;

using namespace std;

class graphe
{
private:
	vector<vector<int>>grapheEtCapacites;
public:
	graphe();
};

bool parcoursLargeur(vector<vector<int>>, int, int, vector<int>);
int fordFulkerson(vector<vector<int>>, int, int);
