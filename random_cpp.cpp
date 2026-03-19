#include <random>

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_real_distribution<float> value_dist(0.0f, 100.0f);
static std::uniform_int_distribution<int> action_dist(1, 10);

extern "C" {
    
    float get_random_value(void) {
        return value_dist(gen);
    }
    
    int get_random_action(void) {
        return action_dist(gen);
    }
    
}