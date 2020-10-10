#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define test(t) int t; cin >> t; while(t--)
#define forr(I, a, b) for(register int I = a; I < b; I++)
#define pb push_back

vector<int> SegmentTree;
vector<int> v;
int N;

int left (int pos) {return pos << 1;}
int right (int pos) {return (pos << 1) + 1;}

void build (int L, int R, int position) {
    if (L == R) {
        SegmentTree[position] = L;
        return;
    }
    build (L, (L + R) / 2, left(position));
    build (((L + R) / 2) + 1, R, right(position));
    int p1 = SegmentTree[left(position)], p2 = SegmentTree[right(position)];
    SegmentTree[position] = (v[p1] <= v[p2]) ? p1 : p2;
}

int Rmq(int position, int L, int R, int i, int j) {
    if (i > R or j < L)    return -1;
    if (L >= i and R <= j)  return SegmentTree[position];

    int p1 = Rmq(left(position), L, (L + R) / 2, i, j);
    int p2 = Rmq(right(position), ((L + R) / 2) + 1, R, i, j);
    if (p1 == -1)   return p2;
    if (p2 == -1)   return p1;
    return v[p1] <= v[p2] ? p1 : p2;
}

int rmq (int L, int R) {
    return Rmq (1, 0, N - 1, L, R);
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int ele;
    cin >> N;
    forr (i, 0, N) {
        cin >> ele;
        v.pb(ele);
    }
    SegmentTree.assign(4 * N, 0);
    build (0, N - 1, 1);
    forr (i, 1, int(SegmentTree.size())) {
        cout << SegmentTree[i] << " ";
    }
    cout << endl;
    cout << rmq(0, 6) << endl;
    cout << rmq(0, 3) << endl;
    cout << rmq(4, 6) << endl;
    cout << rmq(0, 1) << endl;
    cout << rmq(2, 3) << endl;
    cout << rmq(4, 5) << endl;
    cout << rmq(6, 6) << endl;
    return 0;
} 
