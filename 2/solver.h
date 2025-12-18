#include <string>
#include <vector>
#include <fstream>

class Solver {
    public: 
        Solver(const std::string& filePath);
        ~Solver() = default;
        void solve();
        void testPrint();

    private:
        std::vector<std::pair<long long, long long>> _ranges;
        std::ifstream _input;
        long long _sum = 0;

        void parseRanges();
};