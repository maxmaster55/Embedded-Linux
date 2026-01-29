#include <vsomeip/vsomeip.hpp>
#include "CapsLK_client.hpp"


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    hello_world_client hw_cl;
    if (hw_cl.init()) {
        hw_cl.start();
        return 0;
    } else {
        return 1;
    }
}
