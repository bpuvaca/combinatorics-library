#include <bits/stdc++.h>
using namespace std;

class FunkcijeUtil{
   public:
      static int uredeneNtorkeMclanogSkupaBezPonavljanja(int n, int m){
         string subset = "";
         vector<int> veki;
         int c = 0;
         for (int i = 0; i < m-n; i++) subset += "0";
         for (int i = 0; i < n; i++) subset += "1";
         do{
            veki.clear();
            for (int i = 0; i < m; i++){
               if (subset[i] == '1'){
                  veki.push_back(i);
               }
            }
            do{
               for (auto x: veki) cout << x + 1 << ' ';
               c++;
               cout << endl;
            } while (next_permutation(veki.begin(), veki.end()));
         } while (next_permutation(subset.begin(), subset.end()));
         return c;
      }
      static int uredeneNtorkeMclanogSkupaUzPonavljanja(int n, int m){
         vector<int> tren(n,0);
         int count = 0;
         do{
            for (int i = 0; i < n; i++){
               cout << tren[i] + 1 << " ";
            }
            cout << endl;
            count++;
         } while(varUzPonNext(tren,n,m));
         return count;
      }

      static bool varUzPonNext(vector<int>& curr, int n, int m){
         int i;
         for (i = n-1; i >= 0 && curr[i] == m-1; i--);
         if (i < 0) return false;
         curr[i]++;
         for (int j = i+1; j < n; j++) curr[j] = 0;
         return true;
      }

      static int rastuceFunkcije(int n,int m){
         vector<int> tren(n,0);
         int count = 0;
         do{
            for (int i = 0; i < n; i++){
               cout << tren[i] + 1 << " ";
            }
            cout << endl;
            count++;
         } while(rastuceFunkcijeNext(tren,n,m));
         return count;
      }

      static bool rastuceFunkcijeNext(vector<int>& curr, int n, int m){
         int i;
         for (i = n-1; i >= 0 && curr[i] == m-1; i--);
         if (i < 0) return false;
         curr[i]++;
         for (int j = i+1; j < n; j++) curr[j] = curr[i];
         return true;
      }

      static int surjekcije(int n, int m){
         vector<int> tren(n,0);
         set<int> skup;
         int count = 0;
         do{
            skup.clear();
            for (int i = 0; i < n; i++){
               skup.insert(tren[i]);
            }
            if (skup.size() == m){      
               for (int i = 0; i < n; i++){
                  cout << tren[i] + 1 << " ";
               }
               count++;
               cout << endl;
            }
            
         } while(varUzPonNext(tren,n,m));
         return count;
      }
};

class PodskupoviUtil{
   public:
      static void printGrayCode(int k){
         for (int i = 0; i < pow(2,k); i++){
            string code = rankToGray(i);
            int c = code.length();
            for (int j = 0; j < k - c; j++){
               code = '0' + code;
            }
            cout << code << endl;
         }
      }

      static string nextGray(string code){
         return rankToGray(grayToRank(code) + 1);
      }
      static long long generirajPodskupove(int n){
         long long count = 0, i;
         for (i = 0; i < pow(2,n); i++){
            count++;
         }
         return count;
      }

      static long long generirajkPodskupove(int n, int k){
         string subset = "";
         int c = 0;
         for (int i = 0; i < n-k; i++) subset += "0";
         for (int i = 0; i < k; i++) subset += "1";
         do{
            //cout << subset << endl;
            c++;
         } while (next_permutation(subset.begin(), subset.end()));
         return c;
      }
   private:
      static string rankToGray(int rank){
         string code = "";
         if (rank == 0) return "0";
         int eksp = (int) log2(rank) + 1;
         int lower = 0, upper = pow(2,eksp) - 1, middle;
         bool flag = 0;
         while (lower != upper){
            middle = (upper+lower)/2;
            if ((rank > middle) != flag){
               code += "1";
               flag = !flag;
            } else code += "0";
            if (rank > middle) {
               lower = (upper+lower)/2 + 1;
            }
            else upper = (upper+lower)/2;
         }
         return code;
      }

      static int grayToRank(string code){
         int lower=0,upper=pow(2,code.length())-1;
         bool flag = false, up;
         for (auto c: code){
            up = (c == '1') != flag;
            if (c == '1') flag = !flag;
            if (up){
               lower = (upper+lower)/2 + 1;
            }
            else upper = (upper+lower)/2;
         }
         return upper;
      }
      static string bin(int k){
         string s = "";
         if (k == 0) return "0";
         while (k != 0){
            if (k%2){
               s = "1" + s;
            }
            else s = "0" + s;
            k/=2;
         }
         return s;
      }

};

long long zbroj2n(int n){
   long long count = 0, i,j,k;
   for (i = 0; i < pow(2,n); i++){
      k = 0;
      for (j=0;j<n;j++){
         if (i & (long long)pow(2,j)){
            k+=j+1;
         }
      }
      if (k == 2*n) count++;
   }
   return count;
}

long long deranzmani(int n){
   long long count = 0;
   vector<int> perm(n,0);
   for (int i = 0; i < n; perm[i] = i, i++);
   do{
      bool fiksna = false;
      for (int i = 0; i < n; i++){
         if (perm[i] == i){
            fiksna = true;
            break;
         }
      }
      if (!fiksna){
         count++;
         for (int i = 0; i < n; i++) cout << perm[i] + 1 << " ";
         cout << endl;
      }
   } while (next_permutation(perm.begin(), perm.end()));
   return count;
}



long long cjelobrojnaRjesenja(int xeva, int k){
   if (xeva == 1) return 1;
   int suma = 0;
   for (int i = 0; i <= k; i++){
      suma += cjelobrojnaRjesenja(xeva-1, k-i);
   }
   return suma;
}

int main(){
   return 0;
}