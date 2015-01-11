#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
typedef long long ll;

using namespace std;

class QuadraticLaw {
    public:

    long long getTime(long long d) {
            ll rootd;
            ll i,res;

            rootd = sqrt(d);

            cout<<endl<<"d is "<<d<<endl;
             res = 1;

            if( d == 1)
                return 0; //Base Case

            while(res*res + res <= d )
                res*=2; //Binary shift by 2

            res/=2;

            ll drootd = sqrt(rootd);

            cout<<"d is: "<<d<<" rootd is: "<<rootd<<" "<<" drootd is: "<<drootd<<endl;
            cout<<"res is: "<<res;

            while( res <= rootd) {
                if( res*res +res <=d)
                    res+=drootd;
                else
                    break;
            }
            res-=drootd;

            while(   res<=rootd)
                if(res*res+res<=d)
                    res+=1;
                else
                    break;
            res-=1;

    return res;
    }


};

// CUT begin
ifstream data("QuadraticLaw.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(long long d, long long __expected) {
    time_t startClock = clock();
    QuadraticLaw *instance = new QuadraticLaw();
    long long __result = instance->getTime(d);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        long long d;
        from_stream(d);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(d, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421005240;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "QuadraticLaw (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
