#include<bits/stdc++.h>
using namespace std;
struct Ans{
	int sum,ansleft,ansright;
}ans;
Ans MaxSum(int a[],int left,int right){
	Ans midSum,leftSum,rightSum;
	int center,s1,s2,lefts,rights;
	if(left==right){
		ans.sum=a[left];
		ans.ansleft=left;
		ans.ansright=right;
	}
	else{
		center=(left+right)/2;
		leftSum=MaxSum(a,left,center);
		rightSum=MaxSum(a,center+1,right);
		s1=-1e9;lefts=0;
		int ans_tmp_left=center;
		for(int i=center;i>=left;i--){
			lefts+=a[i];
			if(lefts>s1){
			s1=lefts;
			ans_tmp_left=i;
			}
		} 
		s2=-1e9;rights=0;
		int ans_tmp_right=center;
		for(int j=center+1;j<=right;j++){
			rights+=a[j];
			if(rights>s2){
				s2=rights;	
				ans_tmp_right=j;	
			}
		}
		midSum.sum=s1+s2;
		midSum.ansleft=ans_tmp_left;
		midSum.ansright=ans_tmp_right;
		if(midSum.sum<=leftSum.sum) ans=leftSum;
		else ans=midSum;
		if(ans.sum<rightSum.sum) ans=rightSum;
	}
	return ans;
} 
int main(){
	int k;
	while(cin>>k&&k!=0){
		int a[k];
		for(int i=0;i<k;i++)
			scanf("%d",&a[i]);
			Ans tmp= MaxSum(a,0,k-1);
			if(tmp.sum>=0)
			cout<<tmp.sum<<" "<<a[tmp.ansleft]<<" "<<a[tmp.ansright]<<endl;
			else cout<<0<<" "<<a[0]<<" "<<a[k-1]<<endl;                                                                                                                                           
	}
	return 0;
}
