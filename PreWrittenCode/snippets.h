//Power function LOG_POWER
ll power(ll a,ll b,ll mod=MOD){
	ll ans=1;
	for(ll i=0;(1LL<<i)<=b;++i){
		ans*=(b&(1LL<<i)?a:1LL);
		ans%=mod;
		a*=a;
		a%=mod;
	}
	return ans;
}
//Integer floor square root INT_ROOT
ll intRoot(ll x){
	ll l{0},r{x};
	while(l<r){
		ll mid=(l+r+1)/2;
		if(x/mid>=mid){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
//Ordered sets with find by order and find order of ORDERED_SET
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//Min priority queue MIN_QUEUE
template <typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;
//Random hash base RAN_HASH
seed_seq seq{
	(uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
	(uint64_t) __builtin_ia32_rdtsc(),
	(uint64_t) (uintptr_t) make_unique<char>().get()
};
mt19937 rng(seq);
const long long int base = uniform_int_distribution<long long int>(1, ModularInteger::_mod-1)(rng),input_limit;
vector<ModularInteger> powers(input_limit+1,1LL);
for(int i=1;i<powers.size();++i){
	powers[i]=powers[i-1]*base;
}
