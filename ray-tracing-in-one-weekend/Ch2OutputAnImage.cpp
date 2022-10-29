// #include <iostream>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main() {
  int32_t width = 256;
  int32_t height = 256;
  cout << "P3\n"
       << width << " " << height << "\n"
       << "256\n";
  for (int i = 0; i < 256; i++) {
    cerr << "\rScanlines remaining: " << 255 - i << " " << flush;
    for (int j = 0; j < 256; j++) {
      cout << "128 " << i << " " << j << "\n";
    }
  }
  // this_thread::sleep_for(chrono::seconds(1));
  // cout << "after exit" << endl;
  return 0;
}
