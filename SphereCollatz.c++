#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    assert(i > 0);
    assert(i < 1000000);
    assert(j > 0);
    assert(j < 1000000);
    if (i > j) {
    	int temp = i;
    	i = j;
    	j = temp;
    }
    int max = 0;
    for( ; i <= j; i++) {
        int a = i;
        int c = 1;
        while (a > 1) {
            if ((a % 2) == 0)
                a = (a / 2);
            else
                a = (3 * a) + 1;
            ++c;
        }
        if(c > max)
            max = c;
    }
    assert(max > 0);
    return max;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}