/*****************************************************************************
** Author:		Brendan Jang
** Date:		7/29/2019
** Description: Implementation of wrestler program using BFS. References:	
**				https://www.geeksforgeeks.org/graph-and-its-representations/			
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

// use struct node to assign sides to keep track of each wrestler's side
struct node {
	string side;
	int node;
};

int main() {
	string user;
	ifstream fp;
	bool open = false;

	// loop until correct file is opened
	while (!open) {
		cout << "Enter a file name followed by .txt: ";
		getline(cin, user);
		fp.open(user.c_str());
		// check to see if file is opened
		if (fp.is_open()) {
			open = true;
			cout << endl;
		}
		else {
			cout << endl << user << " File could not be accessed!\n" << endl;
		}
	}

	int n;
	fp >> n;
	unordered_map<string, int> wrestlerMap;
	unordered_map<int, string> reverse;
	string wrestler;

	for (int i = 0; i < n; i++) {
		fp >> wrestler;
		wrestlerMap.insert({ wrestler, i });
		reverse.insert({ i, wrestler });
	}

	int rivalries;
	fp >> rivalries;
	string wrestler1, wrestler2;
	vector <unordered_set<int> > adjacent(n);

	// create adjacency matrix
	for (int i = 0; i < rivalries; i++) {
		fp >> wrestler1 >> wrestler2;
		if (wrestlerMap[wrestler1] < wrestlerMap[wrestler2]) {
			adjacent[wrestlerMap[wrestler1]].insert(wrestlerMap[wrestler2]);
		}
		else {
			adjacent[wrestlerMap[wrestler2]].insert(wrestlerMap[wrestler1]);
		}
	}

	vector<node> nodes(n);
	unordered_set<int> babyfaces;
	unordered_set<int> heels;
	queue<int> wrestleQueue;

	int count = 0;
	int s;

	// continue to loop until count is greater than or equal to rivalries to 
	// handle disconnected graphs
	while (count < rivalries) {
		for (int a = 0; a < n; a++) {
			if (nodes[a].side != "b" && nodes[a].side != "h") {
				// push next node onto the queue and assign to babyfaces if it doesn't
				// have a side yet
				nodes[a].side = "b";
				wrestleQueue.push(a);
				// continue until queue is empty
				while (!wrestleQueue.empty()) {
					// pop top wrestler off the queue
					s = wrestleQueue.front();
					wrestleQueue.pop();
					//if a wrestler next to current wrestler has the same side, then fail
					for (unordered_set<int> ::iterator it = adjacent[s].begin(); it != adjacent[s].end(); ++it) {
						if (nodes[s].side == nodes[*it].side) {
							cout << "Impossible!" << endl;
							return 0;
						}
						// if not then we push wrestlers onto queue to be checked later
						wrestleQueue.push(*it);
						// we need to assign the right side to wrestler
						if (nodes[s].side == "b") {
							nodes[*it].side = "h";
							heels.insert(*it);
							babyfaces.insert(s);
							count++;
						}
						else {
							nodes[*it].side = "b";
							heels.insert(s);
							babyfaces.insert(*it);
							count++;
						}
					}
				}
				if (count >= rivalries) {
					break;
				}
			}
		}
	}
	// print results
	cout << "Yes" << endl;
	unordered_set<int>::iterator iter;
	cout << "Babyfaces: ";
	for (iter = babyfaces.begin(); iter != babyfaces.end(); ++iter) {
		cout << reverse[*iter] << " ";
	}
	cout << endl;
	cout << "Heels: ";
	for (iter = heels.begin(); iter != heels.end(); ++iter) {
		cout << reverse[*iter] << " ";
	}
	cout << endl;
	fp.close();
	return 0;
}