#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
#define pb push_back
#define mkp make_pair


int main(){
  //freopen("input.txt", "r", stdin);
  int n;
  vii v;
  scanf("%d", &n);
  for(int nn = 0; nn < n; nn++){
    int m;
    scanf("%d", &m);
    int l, r;
    scanf("%d %d", &l, &r);
    while(!(l == 0 && r == 0)){
      if(r > 0 && l < m){
	v.pb(mkp(l, r));
      }
      scanf("%d %d", &l, &r);
    }
    
    sort(v.begin(), v.end());

    vii q;
    int segment = 0;
    int ub = 0;
    for(int i = 0; i < v.size();){
      int maxR = -1;
      int maxRL;
      while(v[i].first <= ub){
	if(v[i].second > maxR){
	  maxR = v[i].second;
	  maxRL = v[i].first;
	}
	i++;
      }
      if(maxR >= m){
	q.pb(mkp(maxRL, maxR));
	segment++;
	break;
      }else if(maxR == -1){
	segment = 0;
	break;
      }else{
	ub = maxR;
	q.pb(mkp(maxRL, maxR));
	segment++;
      }
    }
    
    printf("%d\n", segment);
    for(int i = 0; i < segment; i++){
      printf("%d %d\n", q[i].first, q[i].second);
    }
    if(nn != n-1) printf("\n");
    q.clear();
    v.clear();
  }
  return 0;
}
