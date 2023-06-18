// C++ program to illustrate
// page faults in LFU

#include <bits/stdc++.h>
using namespace std;

/* Counts no. of page faults */
int pageFaults(int n, int c, int pages[])
{
	// Initialise count to 0
	int count = 0;

	// To store elements in memory of size c
	vector<int> v;
	// To store frequency of pages
	unordered_map<int, int> mp;

	int i;
	for (i = 0; i <= n - 1; i++) {

		// Find if element is present in memory or not
		auto it = find(v.begin(), v.end(), pages[i]);

		// If element is not present
		if (it == v.end()) {

			// If memory is full
			if (v.size() == c) {

				// Decrease the frequency
				mp[v[0]]--;

				// Remove the first element as
				// It is least frequently used
				v.erase(v.begin());
			}

			// Add the element at the end of memory
			v.push_back(pages[i]);
			// Increase its frequency
			mp[pages[i]]++;

			// Increment the count
			count++;
            cout << count << endl;
		}
		else {

			// If element is present
			// Remove the element
			// And add it at the end
			// Increase its frequency
			mp[pages[i]]++;
			v.erase(it);
			v.push_back(pages[i]);
		}

		// Compare frequency with other pages
		// starting from the 2nd last page
		int k = v.size() - 2;

		// Sort the pages based on their frequency
		// And time at which they arrive
		// if frequency is same
		// then, the page arriving first must be placed
		// first
		while (mp[v[k]] > mp[v[k + 1]] && k > -1) {
			swap(v[k + 1], v[k]);
			k--;
		}
	}
	// Return total page faults
	return count;
}

int main()
{

	int pages[] = { 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5 };
	int n = 12, c = 4;
    int numOfPageFault = pageFaults(n, c, pages);
	cout << "Page Faults = " << numOfPageFault << endl;
	cout << "Page Hits = " << n - numOfPageFault << endl;
	return 0;
}