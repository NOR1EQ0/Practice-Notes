#include <chrono>

inline auto now() {
    return std::chrono::system_clock::now();
}

template<class Clock = std::chrono::system_clock>
inline time_t duration(std::chrono::time_point<Clock> tp1,
    std::chrono::time_point<Clock> tp2) {
    auto _duration = tp2 - tp1;

}