#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "utils.hpp"

using namespace std;




string minWindow(string S, string T) {
    std::unordered_map<char, int> TT;
    std::unordered_map<char, int> T_count;
    std::unordered_set<char> is_present;
    for (const auto& t: T) {
        auto& tt = TT[t];
        auto& tc = T_count[t];
        if(!tt) {
            tt = 0;
            tc = 0;
        }
        ++tt;
    }
    debug(TT);
    debug(T_count);

    pair<int, int> res(-1,-1);
    pair<int, int> curr(-1,-1);
    int l = 0, r = 0;
    while (r < S.size()) {
        while (r < S.size() &&  is_present.size() < TT.size()) {
            //debug(S[r]);
            if (TT.find(S[r]) != TT.end())  {
                auto& tc = T_count[S[r]];
                ++tc;
                if (tc == TT[S[r]]) {
                    if (is_present.find(S[r]) == is_present.end()) {
                        is_present.insert(S[r]);
                    }
                }
                //debug(T_count);
                //debug(is_present.size());
            }
            ++r;
        }
        debug(is_present.size());
        debug(r);
        while (l < r && is_present.size() == TT.size()) {
            //debug(S[l]);
            if (TT.find(S[l]) != TT.end()) {
                auto& tc = T_count[S[l]];
                --tc;
                if (tc < TT[S[l]]) {
                    is_present.erase(S[l]);
                }
                //debug(T_count);
                //debug(is_present);
            }
            ++l;
        }
        debug(is_present.size());
        debug(l);
        curr = {l-1, r};
        if ((res.first == -1 && res.second == -1) || (r-l) < (res.second - res.first)) {
            res = {l-1,r};
        }
    }
    if(res.first != -1) {
        return S.substr(res.first, res.second - res.first + 1);
    } else {
        return "";
    }

}



int main (void)
{
    string A("xiEjBOGeHIMIlslpQIZ6jERaAVoHUc9Hrjlv7pQpUSY8oHqXoQYWWll8Pumov89wXDe0Qx6bEjsNJQAQ0A6K21Z0BrmM96FWEdRG69M9CYtdBOrDjzVGPf83UdP3kc4gK0uHVKcPN4HPdccm9Qd2VfmmOwYCYeva6BSG6NGqTt1aQw9BbkNsgAjvYzkVJPOYCnz7U4hBeGpcJkrnlTgNIGnluj6L6zPqKo5Ui75tC0jMojhEAlyFqDs7WMCG3dmSyVoan5tXI5uq1IxhAYZvRQVHtuHae0xxwCbRh6S7fCLKfXeSFITfKHnLdT65K36vGC7qOEyyT0Sm3Gwl2iXYSN2ELIoITfGW888GXaUNebAr3fnkuR6VwjcsPTldQSiohMkkps0MH1cBedtaKNoFm5HbH15kKok6aYEVsb6wOH2w096OwEyvtDBTQwoLN87JriLwgCBBavbOAiLwkGGySk8nO8dLHuUhk9q7f0rIjXCsQeAZ1dfFHvVLupPYekXzxtWHd84dARvv4Z5L1Z6j8ur2IXWWbum8lCi7aErEcq41WTo8dRlRykyLRSQxVH70rUTz81oJS3OuZwpI1ifBAmNXoTfznG2MXkLtFu4SMYC0bPHNctW7g5kZRwjSBKnGihTY6BQYItRwLUINApd1qZ8W4yVG9tnjx4WyKcDhK7Ieih7yNl68Qb4nXoQl079Vza3SZoKeWphKef1PedfQ6Hw2rv3DpfmtSkulxpSkd9ee8uTyTvyFlh9G1Xh8tNF8viKgsiuCZgLKva32fNfkvW7TJC654Wmz7tPMIske3RXgBdpPJd5BPpMpPGymdfIw53hnYBNg8NdWAImY3otYHjbl1rqiNQSHVPMbDDvDpwy01sKpEkcZ7R4SLCazPClvrx5oDyYolubdYKcvqtlcyks3UWm2z7kh4SHeiCPKerh83bX0m5xevbTqM2cXC9WxJLrS8q7XF1nh");
    string B("dO4BRDaT1wd0YBhH88Afu7CI4fwAyXM8pGoGNsO1n8MFMRB7qugS9EPhCauVzj7h");
    auto res = minWindow(A,B);
    cout << res << endl;
    return 0;
}
