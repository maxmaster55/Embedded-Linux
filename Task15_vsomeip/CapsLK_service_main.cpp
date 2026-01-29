#include <vsomeip/vsomeip.hpp>
#include "CapsLK_service.hpp"



int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    CapsLK_service hw_srv;
    if (hw_srv.init()) {
        hw_srv.start();
        return 0;
    } else {
        return 1;
    }
}
