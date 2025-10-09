#include <bits/stdc++.h>
using namespace std;

vector<int> ActivitySelection(int startTimes[], int finishTimes[], int totalActivities)
{
    int lastSelected = 1;
    vector<int> selectedActivities;
    selectedActivities.push_back(1); // Select the first activity

    for (int current = 2; current <= totalActivities; current++)
    {
        if (startTimes[current] >= finishTimes[lastSelected])
        {
            selectedActivities.push_back(current);
            lastSelected = current;
        }
    }

    return selectedActivities;
}

int main()
{
    int totalActivities;
    cout << "Enter number of activities: ";
    cin >> totalActivities;

    int startTimes[totalActivities + 1];
    cout << "Enter starting times:\n";
    for (int i = 1; i <= totalActivities; i++)
    {
        cin >> startTimes[i];
    }

    int finishTimes[totalActivities + 1];
    cout << "Enter finishing times:\n";
    for (int i = 1; i <= totalActivities; i++)
    {
        cin >> finishTimes[i];
    }

    vector<int> selectedActivities = ActivitySelection(startTimes, finishTimes, totalActivities);

    cout << "\nSelected Activities (by index): ";
    for (int i = 0; i < selectedActivities.size(); i++)
    {
        cout << selectedActivities[i] << " ";
    }

    cout << endl;
    return 0;
}
