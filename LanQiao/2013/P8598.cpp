#include<bits/stdc++.h>
using namespace std;

int n,x,a[100005],ans1,ans2;

int main(){
	cin >> n;
	while(cin >> x)a[x]++;
	for(int i=1;i<=10004;i++){
		if(a[i-1]&&a[i+1]&&!a[i])ans1=i;
		if(a[i]>1)ans2=i;
		if(ans1&&ans2)break;
	}
	cout << ans1 << " " << ans2 << endl; 
	return 0;
}