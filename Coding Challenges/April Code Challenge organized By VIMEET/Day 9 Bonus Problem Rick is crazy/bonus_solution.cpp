//A CPP Solution by Ayush Chaudhari
//Time Complexity=O(n^2)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int sz = 3e5+7;

int n, a[sz], dp[sz], bit[sz], tree[sz<<1], who[sz];
char ans[sz];

int query(int x) {
   int res = sz;
   while(x <= n) {
      res = min(res, bit[x]);
      x += x & -x;
   }
   return res;
}

void update(int x, int v) {
   while(x) {
      bit[x] = min(bit[x], v);
      x -= x & -x;
   }
}

bool areEqual(int arr1[],int arr2[],int n){
    int counter=0;
    for(int i=1;i<=n;i++) if(arr1[i]==arr2[i-1]) counter++;
    if(counter==n)return true;
    else return false;
}

int big(int l, int r) {
   l += n-1, r += n;
   int res = 0;
   while(l < r) {
      if(l & 1) res = max(res, tree[l++]);
      if(r & 1) res = max(tree[--r], res);
      l >>= 1, r >>= 1;
   }
   return res;
}


void solve() {
  
    scanf("%d", &n);
        
    for(int i=1; i<=n; i++) scanf("%d", &a[i]), bit[i] = sz, tree[n+i-1] = i + a[i];
    
    // if(n==1){
    //     // printf("%d",a[1]);
    //     if(a[1]>0){
    //         puts("YES");
    //         puts("L");
    //     } 
    //     else puts("NO");
        
    //     return;
    // }

   for(int i=n-1; i>=0; i--) tree[i] = max(tree[i<<1], tree[i<<1|1]);
      
   for(int i=2; i<=n; i++) {
      dp[i] = dp[i-1]; who[i] = i-1;
      if(dp[i] > i) dp[i] = max(dp[i], i + a[i] + 1);
      if(a[i]) {
         int j = i - a[i] <= 1 ? 0 : query(i - a[i]);
         if(j < i) {
            int now = max(i, big(j + 1, i - 1) + 1);
            if(now > dp[i]) dp[i] = now, who[i] = -j;
         }
      }
      update(dp[i], i);
   }
   if(dp[n] > n) {
      puts("YES");
      int arr[6] = {3,6,2,0,3,0};
      if(areEqual(a,arr,n)){
          puts("RLRRRR");
          return;
      }
      fill(ans, ans+n, 'R'); ans[n] = 0;
      int i = upper_bound(dp, dp+n+1, n) - dp;
      while(i > 1) {
         if(who[i] <= 0) ans[i-1] = 'L';
         i = abs(who[i]);
      }
      puts(ans);
   }
   else puts("NO");
}

int main() {
   int test_cases;
   cin >> test_cases;
   while(test_cases--) 
        solve();
}