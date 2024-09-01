#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> freq(5, 0);
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                freq[4]++;
                continue;
            }
            freq[s[i] - 'A']++;
        }

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            if (freq[i] <= n) {
                ans += freq[i];
            } else {
                ans += n;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
