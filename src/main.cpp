#include "ringbuffvec.h"

int main(int argc, char* argv[]) {
    RingBuffVec<int> R1{5};
    R1.print();
    R1.put(1);
    R1.put(2);
    R1.put(3);
    R1.put(4);
    R1.put(5);
    R1.print();
    R1.put(6);
    R1.print();
    return 0;
}
