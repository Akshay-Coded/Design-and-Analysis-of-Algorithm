#include <string.h>
#include <iostream>
using namespace std;

#define d 10

void rabinKarp(char pattern[], char text[], int q, int n1, int n2) {
  int m = n2;
  int n = n1;
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;
    int chk=0;
  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;
  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }
  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == m){
        cout << "String found in position " << i + 1 << endl;
        chk=1;
    }}

    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
  if(chk == 0){
      cout<<"String not found";
  }
  
}
int main() {
  char text[10];
  char pattern[5];
  int n1,n2;
  cin>>n1;
  for(int i=0;i<n1;i++){
      cin>>text[i];
  }
  cin>>n2;
  for(int i=0;i<n2;i++){
      cin>>pattern[i];
  }

  rabinKarp(pattern, text, n1+n2,n1,n2);
}
