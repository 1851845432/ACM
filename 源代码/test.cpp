#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
ll n, m;
ll kuai(ll base,ll power)
{
 ll ant = 1;
 while (power > 0)
 {
  if (power & 1)
  {
   ant = (ant * base ) % mod;
  }
  power >>= 1;
  base = (base  * base ) % mod;
 }
 return ant;
}
int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  cin >> n >> m;
  ll pp = kuai(2, n - 1);
  ll sum = (m * kuai(pp, mod-2)%mod);
  cout << (m%mod-sum%mod+sum)%mod << endl;
 }
 return 0;
}
