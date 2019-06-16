#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int *p1= new int[n];
	int *p2= new int[n];
	for(int i=0;i<n;i++){
		p1[i]=1;
		p2[i]=-1;
	}
	int *p3= new int[n];
	int *p4= new int[n];
	for(int i=0;i<n;i++){
		cin>>p3[i];
	}
	for(int i=0;i<n;i++){
		cin>>p4[i];
	}
	for(int l=0;l<m;l++){
		int x;
		cin>>x;
		if(x==1){
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			int *q=new int[r-l+1];
			for(int i=0;i<r-l+1;i++){
				q[i]=p4[l+i];
			}
			int temp=r;
			for(int i=0;i<r-l+1;i++){
				p4[l+i]=p3[temp];
				temp--;

			}
			temp=r-l;
			for(int i=0;i<r-l+1;i++){
				p3[l+i]=q[temp];
				temp--;
			}
			delete [] q;
		}
		if(x==2){
			int k;
			cin>>k;
			int l=0,r=k;
			r--;

			int *q=new int[r-l+1];
			for(int i=0;i<r-l+1;i++){
				q[i]=p2[l+i];
			}
			int temp=r;
			for(int i=0;i<r-l+1;i++){
				p2[l+i]=p1[temp];
				temp--;

			}
			temp=r-l;
			for(int i=0;i<r-l+1;i++){
				p1[l+i]=q[temp];
				temp--;
			}
			delete [] q;

		}
		if(x==3){
          int a,b,c,d;
          cin>>a>>b>>c>>d;
          a--;
          b--;
          c--;
          d--;
          int sum=0;
          for(int i=0;i<d-c+1;i++){
          	sum+=p1[c+i]*p3[a+i];
          }
          cout<<sum<<"\n";
		}
	}
	return 0;
}