#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <array>
#include <list>
#include <stack>
#include <set>
#include <map>

#define Nb 1001
#define nbTours 10

using namespace std;

bool IsPrime(int n);
array<int, Nb / 2> AreTheyAllPrime(int n, array<int, Nb / 2>tabPremiers);

int main() {
	setlocale(LC_ALL, "Fr-fr");
	srand(time(NULL));

	//Partie 1 & 2
	array<int, Nb / 2>tabPremiers;
	tabPremiers.fill(0);
	tabPremiers = AreTheyAllPrime(Nb, tabPremiers);
	for (auto i : tabPremiers)
		cout << i << ' ';
	cout << endl;
	//Fin Partie 1 & 2

	//Partie 3 & 4 & 5

	//Vector liste queue stack
	array<int, 10>Array{ 2, 3, 5, 7, 5, 5, 5, 8, 9, 10 };
	vector<int>Vector;
	list<int>List;
	stack<int>Stack;
	queue<int>Queue;

	//Set Multiset Map Multimap
	set<int>Set;
	set<int>::iterator itSet;
	multiset<int>Multiset;
	multiset<int>::iterator ItMultiset;
	map<int, int>Map;
	map<int, int>::iterator itMap;
	multimap<int, int>Multimap;
	multimap<int, int>::iterator ItMultimap;

	//Chrono
	std::chrono::time_point<std::chrono::system_clock> start, end;

	//Départ course
	//Equipe non associatif
	start = std::chrono::system_clock::now();
	for (auto i : Array) {
		Vector.push_back(i);
	}
	for (int i = 0; i < nbTours; i++) {
		while (Vector.size()) {
			List.push_back(Vector.back());
			//cout << " vector to list " << Vector.back() << endl;
			Vector.pop_back();
		}
		while (List.size()) {
			Stack.push(List.front());
			//cout << " list to stack " << List.front() << endl;
			List.pop_front();
		}
		while (Stack.size()) {
			Queue.push(Stack.top());
			//cout << " stack to queue " << Stack.top() << endl;
			Stack.pop();
		}
		while (Queue.size()) {
			Vector.push_back(Queue.front());
			//cout << " queue to vector " << Queue.front() << endl;
			Queue.pop();
		}
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "Algorithme Non Associatif exécuté en :" << elapsed_seconds.count() << endl;

	//Equipe associatif
	start = std::chrono::system_clock::now();

	for (auto i : Array) {
		Set.insert(i);
	}
	for (int i = 0; i < nbTours; i++) {
		for (itSet = Set.begin(); itSet != Set.end(); itSet++) {
			if (i > 0) { Multimap.erase(Multimap.begin()); }
			Multiset.insert(*itSet);
		}
		for (ItMultiset = Multiset.begin(); ItMultiset != Multiset.end(); ItMultiset++) {
			Set.erase(Set.begin());
			Map.insert(pair<int, int>(*ItMultiset, *ItMultiset));
		}
		for (itMap = Map.begin(); itMap != Map.end(); itMap++) {
			Multiset.erase(Multiset.begin());
			Multimap.insert(pair<int, int>((*itMap).first, (*itMap).second));
		}
		for (ItMultimap = Multimap.begin(); ItMultimap != Multimap.end(); ItMultimap++) {
			Map.erase(Map.begin());
			Set.insert((*ItMultimap).second);
		}
	}

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "Algorithme Associatif exécuté en :" << elapsed_seconds.count() << endl;
	//Fin partie 3 & 4 & 5

	return EXIT_SUCCESS;
}
//Partie 1
bool IsPrime(int n) {
	if (n < 1)return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
//Partie 2
array<int, Nb / 2> AreTheyAllPrime(int n, array<int, Nb / 2>tabPremiers) {
	if (n < 1)return tabPremiers;
	int cpt = 0;
	for (int i = 2; i <= n; i++) {
		if (IsPrime(i) == true) {
			tabPremiers[cpt] = i;
			cpt++;
		}
	}
	return tabPremiers;
}
