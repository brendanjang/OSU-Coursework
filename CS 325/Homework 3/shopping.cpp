/*****************************************************************************
 * Name:		Brendan Jang
 * Date:		7/15/2019
 * Description: Implementation file for shopping.cpp. Uses knapsack algorithm
 * 				to determine maximum total price of items for each family and
 * 				the items that each family memeber should select.
 ****************************************************************************/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int knapsack(int[], int[], int, int, vector<int>&);
int max(int, int);
int main() {
	// number of test cases
    int T;  
	// number of items
    int N;    
	// prices of items
    int P[100];    
	// weights of items
	int W[100]; 
	// number of family members   
    int F;    
	// max weight that can be carried
    int M = 0;
    vector<vector<int>> vec(100);
    ifstream inFile;
    ofstream outFile;
    // open input file
    inFile.open("shopping.txt");
    // check to see if the input file is open
    if (!inFile.is_open()) {
        cout << "Error: Can't open file!" << endl;
        return 1;
    }
    // open the output file
    outFile.open("result.txt");
    // check to see if the the output file is open
    if (!outFile.is_open()) {
        cout << "Error: Can't open file!" << endl;
        return 1;
    }
    // read the number of test cases from the input file
    inFile >> T;
    // process T number of test cases
    for (int k = 0; k < T; k++) {
        // read the number of items from the input file
        inFile >> N;
        // read the price and weight of each item and place into arrays
        for (int i = 0; i < N; i++) {
            inFile >> P[i];
            inFile >> W[i];
        }
        int maxPrice = 0; 
        // read number of family members
        inFile >> F;
        // find maximum price of items that can be carried by each family 
		// member and keep track of the total of the max prices
        for (int j = 0; j < F; j++) {
            // read the maximum weight that can be carried by a family member
            inFile >> M;
            // find max price of items that can be carried by family 
			// member and add it to maxPrice
            maxPrice = maxPrice + knapsack(W, P, N, M, vec[j]);
		}
        // write the max total price to output file
        outFile << "Total Price:  " << maxPrice << endl;
        outFile << "Member Items: " << endl;    
        // print the items each family member should take
        for (int t = 0; t < F; t++) {
            sort(vec[t].begin(), vec[t].end());
            outFile << t + 1 << ": ";
			for (int s = 0; s < vec[t].size(); s++) {
                outFile << vec[t][s] << " ";
            }
			vec[t].clear();
            outFile << endl;
        }
    }
    // close files
    inFile.close();
    outFile.close();
    return 0;
}

// return the max price of items that can be carried by a person, who 
// can carry maximum weight M
int knapsack(int W[], int P[], int N, int M, vector<int> &v) {
    int K[N + 1][M + 1];
    // build table K[][]
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= M; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (W[i - 1] <= w) {
                K[i][w] = max(P[i - 1] + K[i - 1][w - W[i - 1]], K[i - 1][w]);
            }
			else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    // store result of knapsack
    int result = K[N][M];
    int w = M;
    for (int i = N; i > 0 && result > 0; i--) {
        if (result == K[i - 1][w]) {
            continue;
		}
        else {
            // this item is included
            v.push_back(i);
            // since this weight is included, the value is subtracted
            result = result - P[i - 1];
            w = w - W[i - 1];
        }
    }
    // K[N][M] represents the max price of items that can be carried by
    // the family member
    return K[N][M];
}

// returns max of two parameters
int max(int a, int b) {
    if (a > b) {
        return a;
	}
    else {
		return b;
	}
}
