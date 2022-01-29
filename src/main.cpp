#include "ringbuffvec.h"
#include "ringbufflist.h"

int main(int argc, char* argv[]) {
    try {
        RingBuffList<int> RL1{5};
        RingBuffVec<int> RV1{5};

        for(int i=1; i<6; ++i) {
            RL1.write(i);
            RV1.write(i);
        }
        std::cout << "ring buffer based on list:" << std::endl;
        RL1.print();
        std::cout << "ring buffer based on vector:" << std::endl;
        RV1.print();
        std::cout << std::endl;

        RL1.write(6);
        RV1.write(6);
        std::cout << "ring buffer based on list:" << std::endl;
        RL1.print();
        std::cout << "ring buffer based on vector:" << std::endl;
        RV1.print();
        std::cout << std::endl;

        std::cout << "ring buffer based on list:" << std::endl;
        for(int i=0; i<2; ++i)
            std::cout << RL1.read() << ", ";
        std::cout << std::endl;
        RL1.print();
        std::cout << std::endl;

        std::cout << "ring buffer based on vector:" << std::endl;
        for(int i=0; i<2; ++i)
            std::cout << RV1.read() << ", ";
        std::cout << std::endl;
        RV1.print();
    }
    catch(const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
    }
    return 0;
}
