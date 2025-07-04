#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> tickets;
    vector<ll> customer_prices;
    for(int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        tickets.push_back(temp);
    }

    for(int i = 0; i < m; i++) {
        ll temp;
        cin >> temp;
        customer_prices.push_back(temp);
    }

    multiset<ll> ticket_set;
    for(ll ticket: tickets) {
        ticket_set.insert(ticket);
    }

    for(int i = 0; i < m; i++) {
        ll price = customer_prices[i];

        auto it = ticket_set.upper_bound(price);

        if (it == ticket_set.begin()) {
            cout << -1 << endl;
        }
        else {
            cout << *(--it) << endl;
            ticket_set.erase(it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}