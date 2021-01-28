#include <iostream>
#include <algorithm>
using namespace std;

int N, A[10009];

int main(){

    // swap関数の使い方
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    //　バブルソート実装：小さい順に並べる
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N - i; j++){
            if(A[j] > A[j + 1]) swap(A[j], A[j+1]);
        }
    }

    // 大きい順にバブルソートする 配列０番目からやるとしたら？
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i; j++){
            if(A[j] < A[j+1]) swap(A[j], A[j+1]);
        }
    }

    // sort関数の使い方
    long long N,K,L[10009];
    scanf("%lld%lld", &N, &K);
    for(int i = 1; i < N; i++) scanf("%lld", &L[i]);

    // 棒を長い順に並べ替える
    sort(L+1, L+N+1);

    // 1番目に長い棒、2番めに長い棒、と順番にとっていくだけで
    // 「与えられた棒を大きい順に並び替えて足せば良い」となる。
    // ABC067 B
    long long ans = 0;
    for(int i = N - K + 1; i = N; i++){
        ans += L[i];
    }
    return 0;

    // ABC088 B card game for two
    // stdinを取得する
    // stdinを配列に格納する(回答ではvectorを利用しており、かつ6秒と速い)
    int N;
    cin >> N;
    vector<int> v(110);
    for(int i = 0; i < N; i++) cin >> v[i];
    // 配列をソートする
    // std::vecto::sortでは、greater<int>を利用することで降順にソートできる
    sort(v.begin(), v.end(), greater<int>());
    // 大きいものから順に足していく
    int alice = 0;
    int bob = 0;
    for(int i = 0; i < N; i++){
        if(i%2 == 0){
            alice += v[i];
        }else{
            bob += v[i];
        }
    }

    cout << alice - bob << endl;

    // ABC132 C 
    // stdinされた難易度の個数が奇数か偶数か判断する
    // 奇数の場合ば弾く。ただし、偶数の場合、2で割って-1されたものとその数の
    // 番号数でベクトル内の値を取得して、その差分が回答となる

    // 自分の回答 手術後でだるいので提出なし
    // stdinがよくわからない・・・。
    int Num;
    cin >> Num;
    vector<int> v(110);
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++) cin >> v[i];
    if(v.size() % 2 != 0) abort;
    int left = v.size() / 2 - 1;
    int right = v.size() / 2;
    cout << v[right] - v[left] << endl;

    // lower_bound関数の使い方
    // a[i] < x となるようなiが何個あるのかを 0(logN) で検索する
    int N, a[100009];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N); // aという配列の0番目からN-1番目までをソートする
    int x;
    cin >> x;
    cout << lower_bound(a, a+N, x) - a << endl;

    // lower_bounds関数の応用例
    long long N,L,R,A[10000009];
    scanf("%lld%lld%lld", &N, &L, &R);
    for(int i = 0; i < N; i++) scanf("%lld", &A[i]);

    sort(A+1, A+N+1);
    long long ans = 0;
    for(int i = 1; i < N; i++){
        int left_j = lower_bound(A+1, A+N+1, L - A[i]) - A;
        int right_j = lower_bound(A+1, A+N+1, R - A[i]) -A;
    }
}