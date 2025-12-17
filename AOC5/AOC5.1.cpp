#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isNumber(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c) && c != '-') return false;
    }
    return true;
}

// Lee los rangos desde la entrada estándar
vector<pair<long long, long long>> readRanges() {
    vector<pair<long long, long long>> ranges;
    string line;

    while (getline(cin, line)) {
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

        if (line.empty())
            break;

        size_t dash = line.find('-');
        if (dash == string::npos)
            continue;

        string aStr = line.substr(0, dash);
        string bStr = line.substr(dash + 1);

        if (!isNumber(aStr) || !isNumber(bStr))
            continue;

        long long a = stoll(aStr);
        long long b = stoll(bStr);

        if (a > b) swap(a, b);
        ranges.emplace_back(a, b);
    }

    sort(ranges.begin(), ranges.end());
    return ranges;
}

// Fusiona rangos que se solapan
vector<pair<long long, long long>> mergeRanges(const vector<pair<long long, long long>> &ranges) {
    vector<pair<long long, long long>> merged;
    for (const auto &r : ranges) {
        if (merged.empty() || r.first > merged.back().second + 1) {
            merged.push_back(r);
        } else {
            merged.back().second = max(merged.back().second, r.second);
        }
    }
    return merged;
}

// Cuenta los IDs que están dentro de los rangos fusionados
long long countFreshIDs(const vector<pair<long long, long long>> &merged) {
    long long freshCount = 0;
    string line;

    while (getline(cin, line)) {
        if (line.empty())
            continue;

        long long id = stoll(line);

        int left = 0, right = (int)merged.size() - 1;
        bool fresh = false;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (id < merged[mid].first) {
                right = mid - 1;
            } else if (id > merged[mid].second) {
                left = mid + 1;
            } else {
                fresh = true;
                break;
            }
        }

        if (fresh)
            freshCount++;
    }

    return freshCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto ranges = readRanges();
    auto merged = mergeRanges(ranges);
    long long freshCount = countFreshIDs(merged);

    cout << freshCount << "\n";

    return 0;
}
