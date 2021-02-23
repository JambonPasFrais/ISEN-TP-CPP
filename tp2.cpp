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

using namespace std;

int	RechercheDichotomique(vector<int>a, int recherche, int size);
bool RechercheDichotomiqueIt(vector<int>a, int recherche);

int main() {
	setlocale(LC_ALL, "Fr-fr");
	srand(time(NULL));

	//Partie 6 : chrono
	std::chrono::time_point<std::chrono::system_clock> start, end;

	//Partie 1 & 2 Initialisation tableau
	vector<int>Tab;
	vector<int>::iterator it;
	int size = 1000000, max = 10000000;
	for (int i = 0; i < size; i++) {
		Tab.push_back(rand() % max);
	}
	sort(Tab.begin(), Tab.end());
	for (auto const elements : Tab)cout << elements << ' ';
	int const recherche = 100;

	//Partie 3 : Recherche Dichotomique maison
	start = std::chrono::system_clock::now();
	cout << "\nOn cherche la valeur " << recherche << ", position : " << RechercheDichotomique(Tab, recherche, Tab.size()) << endl;
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	cout << "Algorithme exécuté en :" << elapsed_seconds.count() << endl;

	//Partie 4 : Recherche Dichotomique maison w/ it
	start = std::chrono::system_clock::now();
	if (RechercheDichotomiqueIt(Tab, recherche))
		cout << '\n' << recherche << " a été trouvé." << endl;
	else
		cout << '\n' << recherche << " n'a pas été trouvé." << endl;
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = std::chrono::system_clock::to_time_t(end);
	cout << "Algorithme exécuté en :" << elapsed_seconds.count() << endl;

	//Partie 5 : Recherche Dichotomique STL
	start = std::chrono::system_clock::now();
	if (binary_search(Tab.begin(), Tab.end(), recherche))
		cout << '\n' << recherche << " a été trouvé." << endl;
	else
		cout << '\n' << recherche << " n'a pas été trouvé." << endl;
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = std::chrono::system_clock::to_time_t(end);
	cout << "Algorithme exécuté en :" << elapsed_seconds.count() << endl;

	return EXIT_SUCCESS;
}
//Partie 3
int	RechercheDichotomique(vector<int>a, int const recherche, int const size) {
	auto min = 1, max = size;
	while (min < max) {
		auto mid = (min + max) / 2;
		if (a[mid] < recherche) {
			min = mid + 1;
		}
		else
			max = mid;
	}
	if (a[min] == recherche)
		return min;
	else
		return -1;
}
//Partie 4
bool RechercheDichotomiqueIt(vector<int>a, int const recherche) {
	vector<int>::iterator it_s, it_e, it_m;
	it_s = a.begin();
	it_e = a.end();
	while (it_s < it_e) {
		auto dist = distance(it_s, it_e) / 2;
		dist += distance(a.begin(), it_s);
		it_m = a.begin() + dist;
		if (*it_m < recherche) {
			it_s = it_m;
			advance(it_s, 1);
		}
		else
			it_e = it_m;
	}
	if (*it_s == recherche)
		return true;
	else
		return false;
}