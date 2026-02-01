#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <thread>


constexpr static auto APP_NAME = "Hello_Client";

constexpr int SERVICE_ID = 0xAAAA;
constexpr int INSTANCE_ID = 0x01;
constexpr int HELLO_METHOD_ID = 0x01;
constexpr int CAPSLK_METHOD_ID = 0x02;


void state_handler(vsomeip::state_type_e _state)
{
    if(_state == vsomeip::state_type_e::ST_REGISTERED)
    {
        std::cout << "from client register complete \n";
        std::shared_ptr<vsomeip::application> app = vsomeip::runtime::get()->get_application(APP_NAME);
        app->request_service(SERVICE_ID, INSTANCE_ID);
    }
}


void availability_handler(vsomeip::service_t _service, vsomeip::instance_t _inst, bool _flag)
{
    std::shared_ptr<vsomeip::application> app = vsomeip::runtime::get()->get_application(APP_NAME);

    std::shared_ptr<vsomeip::message> request = vsomeip::runtime::get()->create_message();
    request->set_service(_service);
    request->set_instance(_inst);
    request->set_method(HELLO_METHOD_ID);
    request->set_message_type(vsomeip::message_type_e::MT_REQUEST);

    std::shared_ptr<vsomeip::payload> payload =
        vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> data = {1, 2, 3};
    payload->set_data(data);
    request->set_payload(payload);

    app->send(request);
}


void send_capslock_request(std::shared_ptr<vsomeip::application> app)
{
    std::shared_ptr<vsomeip::message> request = vsomeip::runtime::get()->create_message();
    request->set_service(SERVICE_ID);
    request->set_instance(INSTANCE_ID);
    request->set_method(CAPSLK_METHOD_ID);
    request->set_message_type(vsomeip::message_type_e::MT_REQUEST);

    std::shared_ptr<vsomeip::payload> payload =
        vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> data = {7, 8, 9};
    payload->set_data(data);
    request->set_payload(payload);

    std::cout << "Sending Caps Lock request\n";
    app->send(request);
}

int main(int argc, char **argv)
{
    std::shared_ptr<vsomeip::runtime> rtm = vsomeip::runtime::get();
    std::shared_ptr<vsomeip::application> app = rtm->create_application(APP_NAME);
   
    app->init();

    app->register_state_handler(state_handler);
    app->register_availability_handler(SERVICE_ID, INSTANCE_ID, availability_handler);

    std::thread capslock_thread([app]() {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            send_capslock_request(app);
        }
    });

    app->start();

    capslock_thread.join();
    return 0;
}
