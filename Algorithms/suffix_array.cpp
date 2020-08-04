struct SuffixArray {
	std::string t;
	std::vector< int32_t > suffArr, lcpArr;
	
	void init(const std::string &s) {
		t = s + '$';
		
		suffArr.resize(t.size());
		lcpArr.resize(t.size() - 1);
 
		build_suff_array(t);
		build_lcp_array();
	}
 
	void radix_sort(std::vector< std::pair< std::pair< int32_t, int32_t >, int32_t > > &v) {
		int32_t n = v.size();
		
		{
			std::vector< int32_t > cnt(n, 0);
			for(auto &x : v) {
				cnt[x.first.second]++;
			}
			
			std::vector< int32_t > ind(n, 0);
			for(int32_t i = 1; i < n; i++) {
				ind[i] = ind[i - 1] + cnt[i - 1];
			}
 
			std::vector< std::pair< std::pair< int32_t, int32_t >, int32_t > > newV(n);
			for(auto &x : v) {
				newV[ind[x.first.second]] = x;
				ind[x.first.second]++;
			}
 
			v = newV;
		}
 
		{
			std::vector< int32_t > cnt(n, 0);
			for(auto &x : v) {
				cnt[x.first.first]++;
			}
			
			std::vector< int32_t > ind(n, 0);
			for(int32_t i = 1; i < n; i++) {
				ind[i] = ind[i - 1] + cnt[i - 1];
			}
 
			std::vector< std::pair< std::pair< int32_t, int32_t >, int32_t > > newV(n);
			for(auto &x : v) {
				newV[ind[x.first.first]] = x;
				ind[x.first.first]++;
			}
 
			v = newV;
		}
	}
 
	void build_suff_array(const std::string &s) {
		int32_t n = s.size();
 
		std::vector< std::pair< char, int32_t > > a(n);
		for(int32_t i = 0; i < n; i++) {
			a[i] = { s[i], i };
		}
		std::sort(a.begin(), a.end());
 
		std::vector< int32_t > ranks(n);
		ranks[a[0].second] = 0;
		for(int32_t i = 1; i < n; i++) {
			if(a[i].first == a[i - 1].first) {
				ranks[a[i].second] = ranks[a[i - 1].second];
			}
			else {
				ranks[a[i].second] = ranks[a[i - 1].second] + 1;
			}
		}
 
		for(int32_t k = 0; (1 << k) < n; k++) {
			std::vector< std::pair< std::pair< int32_t, int32_t >, int32_t > > v(n);
 
			for(int32_t i = 0; i < n; i++) {
				v[i] = {{ ranks[i], ranks[(i + (1 << k)) % n] }, i};	
			}
			
			radix_sort(v);
			
			for(int32_t i = 0; i < n; i++) {
				suffArr[i] = v[i].second;
			}
 
			ranks[suffArr[0]] = 0;
			for(int32_t i = 1; i < n; i++) {
				if(v[i].first == v[i - 1].first) {
					ranks[suffArr[i]] = ranks[suffArr[i - 1]];
				}
				else {
					ranks[suffArr[i]] = ranks[suffArr[i - 1]] + 1;
				}
			}
		}
	}
 
	bool contains(const std::string &p) {
		int32_t n = t.size();
		int32_t m = p.size();
 
		int32_t low = 0, high = n - 1;
		while(low <= high) {
			int32_t mid = (low + high) / 2;
			
			bool ok = true;
			for(int32_t i = 0; i < m; i++) {
				if(t[(suffArr[mid] + i) % n] < p[i]) {
					low = mid + 1;
					ok = false;
					break;
				}
				else if(t[(suffArr[mid] + i) % n] > p[i]) {
					high = mid - 1;
					ok = false;
					break;
				}
			}
 
			if(ok) {
				return true;	
			}
		}
 
		return false;
	}
 
	void build_lcp_array() {
				
	}
};
