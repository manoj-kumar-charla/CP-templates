class StringHash {
public:
    vector<long long>ps1,ps2;
    long long Q1 = 271, Q2 = 277, M1 = 1000000007, M2 = 998244353;
    StringHash(string s) {
        ps1 = vector<long long>(s.size()+1); ps2 = vector<long long>(s.size()+1);
        for (int i = 1; i <= s.size(); i++) {
            long long c = s[i-1] + 1;
            ps1[i] = ((Q1 * ps1[i-1]) + c)%M1;
            ps2[i] = ((Q2 * ps2[i-1]) + c)%M2;
        }
    }
    long long int powxy(long long int x, long long int y, long long M) {
        if (y == 0) return 1;
        if (y%2 == 1) return (x*powxy(x, y-1, M))%M;
        long long int t = powxy(x, y/2, M);
        return (t*t)%M;
    }
    long long substrHash1(int firstIndex, int lastIndex) {
        long long rem = (powxy(Q1,lastIndex-firstIndex+1,M1) * ps1[firstIndex])%M1;
        return (ps1[lastIndex+1] - rem + M1)%M1;
    }
    long long substrHash2(int firstIndex, int lastIndex) {
        long long rem = (powxy(Q2,lastIndex-firstIndex+1,M2) * ps2[firstIndex])%M2;
        return (ps2[lastIndex+1] - rem + M2)%M2;
    }
    pair<long long, long long> substrHash(int firstIndex, int lastIndex) {
        return {substrHash1(firstIndex, lastIndex), substrHash2(firstIndex, lastIndex)};
    }
};
