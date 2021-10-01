#define MOD 10000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<vector<double>> pq;
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            pq.push({(double)position[i], (double)speed[i], time});
        }
        if (pq.size() == 0) {
            return 0;
        }
        int fleet = 0;
        while (true) {
            if (pq.size() == 1) {
                fleet++;
                break;
            }
            auto ahead = pq.top(); pq.pop();
            auto behind = pq.top(); pq.pop();
            if (ahead[2] >= behind[2]) {
                pq.push(ahead);
            } else {
                fleet++;
                pq.push(behind);
            }
        }
        return fleet;
    }
};
