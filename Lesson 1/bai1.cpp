#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> openFile(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open file " << fileName << endl;
        exit(1);
    }
    int n;
    vector<pair<int, int>> result;
    file >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        file >> x >> y;
        result.push_back(make_pair(x, y));
    }
    return result;
}
vector<pair<int, int>> mergeSort(vector<pair<int, int>> a) {
    if (a.size() <= 1) return a;

    int mid = a.size() / 2;
    vector<pair<int, int>> left(a.begin(), a.begin() + mid);
    vector<pair<int, int>> right(a.begin() + mid, a.end());

    left = mergeSort(left);
    right = mergeSort(right);

    vector<pair<int, int>> merged;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].second < right[j].second)
            merged.push_back(left[i++]);
        else
            merged.push_back(right[j++]);
    }
    while (i < left.size()) merged.push_back(left[i++]);
    while (j < right.size()) merged.push_back(right[j++]);

    return merged;
}

void saveFile(vector<pair<int, int>> result, string fileName) {
    ofstream file(fileName);
    for (int i = 0; i < result.size(); i++) {
        file << result[i].first << " " << result[i].second << endl;
    }
}

void solve(vector<pair<int, int>> a) {
    vector<pair<int, int>> result;
    int r = INT_MIN; 
    for (int i = 0; i < a.size(); i++) {
        if (a[i].first >= r) {  
            result.push_back(a[i]);
            r = a[i].second; 
        }
    }
    for(auto &p : result) {
        cout << p.first << " " << p.second << endl;
    }
    saveFile(result, "output1.txt");
}

int main() {
    cout<<"----------------------------"<<endl;
    cout<<"|    Bai 1: Doan roi       |"<<endl;
    cout<<"----------------------------"<<endl;
    string fileName = "test1.txt";
    vector<pair<int, int>> result = openFile(fileName);
    result = mergeSort(result);
    solve(result);
    return 0;
}
