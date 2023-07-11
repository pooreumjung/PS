long long sum(int *a, int n) {
	long long ans = 0;
    for(int x=0;x<n;x++){
        ans+=a[x];
    }
	return ans;
}
