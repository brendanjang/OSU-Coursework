/*****************************************************************************
* Author:		Brendan Jang
* Date:			7/22/2019
* Description:  Implementation file for last to start. Algorithm works as
*				follows. First sort the activities in increasing order of
*				finish times, then we create a vector to hold selected
*				activities and initialize it with the initial activity
*				that has the first finish time, declare a variable that keeps
*				track of the last selected activity, and finally starts to
*				iterate from second element of that array up to its last and
*				chooses an acticity if its start time is greater than the final
*				activity's finish time resulting in the optimal solution.
*****************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main() {
    // read file
    freopen("act.txt", "r", stdin);
	
    // declare variables
    int tt = 1, activities, startTime, finishTime, setNumber = 1;
 
    while (cin >> tt) {
        // use vector to pair template
        vector<pair<int, pair<int, int>>> p;
        for (int i = 0; i < tt; ++i) {
            cin >> activities >> startTime >> finishTime;
            p.push_back(make_pair(finishTime, make_pair(startTime, activities)));     
        }
		
        // sort
        sort(p.begin(), p.end());
        
        int lastTime = 0;
		
        // declare the vector variable
        vector<int> selectedActs;
		
        // push selected activities
        selectedActs.push_back(p[0].second.second);
        for (int i = 1; i < tt; ++i) {
            if (p[i].second.first >= p[lastTime].first) {
                selectedActs.push_back(p[i].second.second);
                lastTime = i;
            }
        }
		
        // print the given result
        cout << "Set " << setNumber << endl;
        cout << "Number of activities selected = " << selectedActs.size() << "\n";
        cout << "Activities: ";
        for (int i:selectedActs) {
            cout << i << " ";
        }
        cout << "\n";
        setNumber++;
    } 
}