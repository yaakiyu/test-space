// c++ templates - helped by blueberry1001
// Python勢だった僕がc++を快適に使えるように作ったいろいろ
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;  // 「ll」と書くだけでlonglongが使える
/* rep関数の使い方
rep(a) -> a回繰り返す
rep(i, a) -> for i in range(a) と同義
rep(i, a, b) -> for i in range(a, b) と同義
rep(i, a, b, c> for i in range(a, b, c)と同義 */
#define rep1(a)          for(ll i = 0; i < (a); i++)
#define rep2(i, a)       for(ll i = 0; i < (a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define overload4(a, b, c, d, e, ...) e
// 下のやつは、5番目の引数を実行するので、引数の個数に合わせてちょうどいい関数が選ばれる仕組みになってる　賢い
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define append push_back  // append
//可変長引数のprint関数
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
//可変長引数のmin
template<class... T>
constexpr auto min(T... a){return min(initializer_list<common_type_t<T...>>{a...});}
//可変長引数のmax
template<class... T>
constexpr auto max(T... a){return max(initializer_list<common_type_t<T...>>{a...});}
template<typename T,typename U>inline bool chmax(T&a,U b){if(a<b){a=b;return 1;}return 0;}
template<typename T,typename U>inline bool chmin(T&a,U b){if(a>b){a=b;return 1;}return 0;}

inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

//vectorのcin
template<typename T>
std::istream &operator>>(std::istream&is,std::vector<T>&v){for(T &in:v){is>>in;}return is;}
//vectorのcout
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}

//sum関数
template<typename T> inline T sum(vector<T>&a){T ret{};for(auto&i:a)ret+=i;return ret;}


void setup() {
    cin.tie(0);  // 入力高速化
    ios::sync_with_stdio(false); // 入力高速化
    cout<<fixed<<setprecision(30); // 小数点精度を30桁にする
    // 以下、大量のメモ
    // cout<<__builtin_popcount(n)<<endl; // 立っているビットの数を数える
    // str.find("aaa") // aaaの含まれる位置を返す、見つからなかったらstring::nposが返る
}


int main() {
    setup();
}
