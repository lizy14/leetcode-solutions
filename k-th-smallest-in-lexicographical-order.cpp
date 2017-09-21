class Solution {
public:
    long long findKthNumber(long long n, long long k) {

        long long prefix = 1;
        long long expected = k - 1;

        while (expected > 0) {

            long long prefix_count = 0;
            long long lower = prefix;
            long long upper = lower + 1;

            while (lower <= n && lower > 0) {
                long long bounded_upper = min(n + 1, upper);
                prefix_count += bounded_upper - lower;
                lower *= 10;
                upper *= 10;
            }


            if (expected < prefix_count) {
                // one more digit
                prefix *= 10;
                expected--;
            }
            else {
                prefix++;
                expected -= prefix_count;
            }

        }
        return prefix;
    }
};
