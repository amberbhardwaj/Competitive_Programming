
#include <iostream>
#include <chrono>
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::nanoseconds;
    
using namespace std;    

int main()
{
    auto t1 = high_resolution_clock::now();
    // Some action
    auto t2 = high_resolution_clock::now();


    /* Getting number of nanoseconds as an integer. */
    auto ms = duration_cast<nanoseconds>(t2 - t1);
    
    cout << "time = " << ms.count() << endl;
    return 0;
}
