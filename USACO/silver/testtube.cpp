#include <iostream>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sq(x) ((x) * (x))
#define sz(x) (int)(x.size())

// #define int long long

void solve() {
	ll P;
	ll n; 

	cin >> n >> P;

	vector<pair<ll, ll>> one;
	vector<pair<ll, ll>> two;
	vector<pair<ll, ll>> three;

	string firstBeaker, secondBeaker;
	cin >> firstBeaker >> secondBeaker;

    //Input
	ll rn = firstBeaker[0] - '0';
	ll count = 1;

    for(int i=1; i<firstBeaker.length(); i++) {
        ll number = firstBeaker[i] - '0';

        if(number == rn) {
            count++;
        } else {
            one.push_back({rn, count});
            rn = number;
            count =  1;
        }
    }
    one.push_back({rn, count});

	rn = secondBeaker[0] - '0';
	count = 1;
    for(int i=1; i<secondBeaker.length(); i++) {
        ll number = secondBeaker[i] - '0';

        if(number == rn) {
            count++;
        } else {
            two.push_back({rn, count});
            rn = number;
            count = 1;
        }
    }
    two.push_back({rn, count});

    // for(auto o : one) {
    //     cout << o.first << " " << o.second << "\n";
    // }
    // cout << "\n";
    // for(auto o : two) {
    //     cout << o.first << " " << o.second << "\n";
    // }

    vector<pair<int, int>> ans;
    ll moves = 0;
    // while(false) {
    while(!(((one.size() == 0) && (two.size() == 1) && (three.size() == 1)) || ((one.size() == 1) && (two.size() == 0) && (three.size() == 1)) || ((one.size() == 1) && (two.size() == 1) && (three.size() == 0)))) {
        int valOne = 0;
        int valTwo = 0;

        if(!one.empty()) {
            valOne = one.back().first;
        }
        if(!two.empty()) {
            valTwo = two.back().first;
        }

        if((one.size() == 1) && (two.size() == 1) && (three.size() == 1)) {
            //FINAL GREEDY STEP

            //if 1 == 3
            if(one.back().first == three.back().first) {
                ans.push_back({3, 1});
                moves++;
            }

            //if 2 == 3
            if(two.back().first == three.back().first) {
                ans.push_back({3, 2});
                moves++;
            }

            break;
        } 

        //Greedy move if there is a 1 --> move it to test tube 3
        if(valOne == 1) {
            if(three.size() == 0) {
                three.push_back(one.back());
            }
            else if(three[three.size()-1].first == 1) { //If top 1
                three.back().second += one.back().second;
            }
            else { //If top 2
                three.push_back(one.back());
            }

            ans.push_back({1, 3});
            one.pop_back();
        }
        else if(valTwo == 1) {
            if(three.size() == 0) {
                three.push_back(two.back());
            }
            else if(three[three.size()-1].first == 1) {
                three.back().second += two.back().second;
            }
            else {
                three.push_back(two.back());
            }

            ans.push_back({2, 3});
            two.pop_back();
        }
        else {
            //Look for the highest "2" level between the two

            if(one.size() >= two.size()) { //Move from test 1 to test 2
                if(two.size() == 0) {
                    two.push_back(one.back());
                }
                else {
                    two.back().second += one.back().second;
                }
                
                one.pop_back();
                ans.push_back({1, 2});
            }
            else { //Test 2 to test 1
                if(one.size() == 0) {
                    one.push_back(two.back());
                }
                else {
                    one.back().second += two.back().second;
                }

                two.pop_back();
                ans.push_back({2, 1});
            }

        }

        moves++;
    }


    cout << moves << "\n";

    if(P == 2 || P == 3) {
        for(auto mv : ans) {
            cout << mv.first << " " << mv.second << "\n";
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T; cin >> T;
	while(T--) {
		solve();
	}

}