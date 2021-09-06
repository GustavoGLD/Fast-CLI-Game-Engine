#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;

namespace gld
{

////////////////////////////////////////////////////////////
/// \brief to use time functions
////////////////////////////////////////////////////////////
class Time {
private:
    high_resolution_clock::time_point _init_time;
    high_resolution_clock::time_point _last_frame;
    double _delta_time = 0.1f;

protected:
    inline void setTimeInit() {
        _init_time  = high_resolution_clock::now();
        _last_frame = high_resolution_clock::now();
    }

    inline void setFrameInit() {
        high_resolution_clock::time_point now = high_resolution_clock::now();
        _delta_time = duration_cast<std::chrono::duration<double>>(now - _last_frame).count();
        _last_frame = high_resolution_clock::now();
    }

public:
    inline double getTime() {
        high_resolution_clock::time_point now = high_resolution_clock::now();
        return duration_cast<duration<double>>(now - _init_time).count();
    }

    inline double getDeltaTime() {
        return _delta_time;
    }
};

}
