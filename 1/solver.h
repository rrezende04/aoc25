#include <string>
#include <iostream>
#include <fstream>

class Solver {
    public:
        Solver(const std::string& filePath, bool click = false);
        ~Solver() = default;
        void solve();

    private:;
        static constexpr int DIAL_RANGE = 100;
        std::ifstream _input;
        int _dialValue = 50;
        int _result = 0;
        bool _click;

        int solutionLoop();
        void turnDial(char direction, int turnValue);
        void clickLogic(bool left, int turnValue);
};