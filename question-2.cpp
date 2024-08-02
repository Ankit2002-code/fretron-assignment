#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void distribute_apples(vector<int> &weights) {
    const int ramPaid = 50;
    const int shamPaid = 30;
    const int rahimPaid = 20;

    int totalPaid = ramPaid + shamPaid + rahimPaid;

    int totalWeight = accumulate(weights.begin(), weights.end(), 0);

    int ramWeight = totalWeight * ramPaid / totalPaid;
    int shamWeight = totalWeight * shamPaid / totalPaid;
    int rahimWeight = totalWeight * rahimPaid / totalPaid;

    vector<int> ramApples, shamApples, rahimApples;

    sort(weights.begin(), weights.end(), greater<int>());

    auto allocate_apples = [&](vector<int> &personApples, int &personWeight) {
        for (auto it = weights.begin(); it != weights.end() && personWeight > 0;) {
            if (*it <= personWeight) {
                personApples.push_back(*it);
                personWeight -= *it;
                it = weights.erase(it); 
            } else {
                ++it;
            }
        }
    };

    allocate_apples(ramApples, ramWeight);
    allocate_apples(shamApples, shamWeight);
    allocate_apples(rahimApples, rahimWeight);

    cout << "Distribution Result:" << endl;

    cout << "Ram: ";
    for (const int &apple : ramApples) {
        cout << apple << " ";
    }
    cout << endl;

    cout << "Sham: ";
    for (const int &apple : shamApples) {
        cout << apple << " ";
    }
    cout << endl;

    cout << "Rahim: ";
    for (const int &apple : rahimApples) {
        cout << apple << " ";
    }
    cout << endl;
}

int main() {
    vector<int> appleWeights;
    int weight;

    cout << "run distribute_apple" << endl;
    cout << "Enter apple weight in gram (-1 to stop): ";

    while (cin >> weight && weight != -1) {
        appleWeights.push_back(weight);
        cout << "Enter apple weight in gram (-1 to stop): ";
    }

    distribute_apples(appleWeights);

    return 0;
}
