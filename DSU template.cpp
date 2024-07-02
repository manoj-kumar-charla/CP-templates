
class DSU{
	public:
	vector<int> size, parent;
	DSU(int n){
		size.resize(n, 1);
		parent.resize(n, 0);
		for(int i=0; i<n; i++) parent[i]=i;
	}
	int getUltPar(int u){
		if(parent[u]==u) return u;
		return parent[u]=getUltPar(parent[u]);
	}
	void unbs(int u, int v){
		int ulp_u = getUltPar(u);
		int ulp_v = getUltPar(v);
		if(ulp_u == ulp_v) return;
		if(size[ulp_u] > size[ulp_v]){
			size[ulp_u] += size[ulp_v];
			parent[ulp_v] = ulp_u;
		}else{
			size[ulp_v] += size[ulp_u];
			parent[ulp_u] = ulp_v;
		}
	}
};
