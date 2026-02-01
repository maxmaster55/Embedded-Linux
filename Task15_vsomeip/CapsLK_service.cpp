#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <fstream>
#include <csignal>

constexpr static auto CAPSLK_PATH = "/sys/class/leds/input9::capslock/brightness";
constexpr static auto APP_NAME = "CapsLK_service";

constexpr int SERVICE_ID = 0xAAAA;
constexpr int INSTANCE_ID = 0x01;
constexpr int HELLO_METHOD_ID = 0x01;
constexpr int CAPSLK_METHOD_ID = 0x02;

void signal_handler(int signal)
{
    std::shared_ptr<vsomeip::application> app = vsomeip::runtime::get()->get_application(APP_NAME);
        app->stop_offer_service(SERVICE_ID, INSTANCE_ID);
        // unregister the state handler
        app->unregister_state_handler();
        // unregister the message handler
        app->unregister_message_handler(
            SERVICE_ID,
            INSTANCE_ID,
            HELLO_METHOD_ID
        );
        app->unregister_message_handler(
            SERVICE_ID,
            INSTANCE_ID,
            CAPSLK_METHOD_ID
        );
    app->stop();
    std::cout << "Service stopped due to signal " << signal << std::endl;
}


void state_handler(vsomeip::state_type_e _state)
{
    if(_state == vsomeip::state_type_e::ST_REGISTERED)
    {
        std::cout << "from service register complete \n";
    }
}

void hello_message_handler(const std::shared_ptr<vsomeip::message>& _request)
{
    std::cout << "Message received with payload length: "
              << _request->get_payload()->get_length() << std::endl;

    // Create a response message
    std::shared_ptr<vsomeip::message> response = vsomeip::runtime::get()->create_message();
    response->set_service(_request->get_service());
    response->set_instance(_request->get_instance());
    response->set_method(HELLO_METHOD_ID);
    response->set_client(_request->get_client());
    response->set_message_type(vsomeip::message_type_e::MT_RESPONSE);

    // Create payload for the response
    std::shared_ptr<vsomeip::payload> payload =
        vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> data = {4, 5, 6};
    payload->set_data(data);
    response->set_payload(payload);

    // Send the response
    vsomeip::runtime::get()->get_application(APP_NAME)->send(response);
}

void capslock_message_handler(const std::shared_ptr<vsomeip::message>& _request)
{
    static int count = 0;
    std::cout << "CapsLock Message received with payload length: "
              << _request->get_payload()->get_length() << std::endl;

    // Create a response message
    std::shared_ptr<vsomeip::message> response = vsomeip::runtime::get()->create_message();
    response->set_service(_request->get_service());
    response->set_instance(_request->get_instance());
    response->set_method(CAPSLK_METHOD_ID);
    response->set_client(_request->get_client());
    response->set_message_type(vsomeip::message_type_e::MT_RESPONSE);

    // Create payload for the response
    std::shared_ptr<vsomeip::payload> payload =
        vsomeip::runtime::get()->create_payload();
    std::string message;

    // Toggle Caps Lock LED
    int brightness = (count % 2 == 0) ? 1 : 0;
    std::ofstream capslock_file(CAPSLK_PATH);
    if(capslock_file.is_open())
    {
        std::string str = (brightness ? "ON" : "OFF");
        capslock_file << brightness;
        capslock_file.close();
        std::cout << "Caps Lock LED set to " << str << std::endl;
        message = "capslock: " +  str + "\n";
    }
    else
    {
        std::cerr << "Failed to open Caps Lock LED file." << std::endl;
        message = "capslock: ERROR\n";
    }

    std::vector<vsomeip::byte_t> data(message.begin(), message.end());
    payload->set_data(data);
    response->set_payload(payload);

    // Send the response
    vsomeip::runtime::get()->get_application(APP_NAME)->send(response);
    count++;
}



int main(int argc, char **argv)
{

    // signal handling
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);

    std::shared_ptr<vsomeip::runtime> rtm = vsomeip::runtime::get();
    std::shared_ptr<vsomeip::application> app = rtm->create_application(APP_NAME);
   
    app->init();

    app->register_state_handler(state_handler);
    app->register_message_handler(
        SERVICE_ID, 
        INSTANCE_ID, 
        HELLO_METHOD_ID,
        hello_message_handler
    );
    app->register_message_handler(
        SERVICE_ID, 
        INSTANCE_ID, 
        CAPSLK_METHOD_ID,
        capslock_message_handler
    );

    app->offer_service(SERVICE_ID, INSTANCE_ID);

    app->start();

    return 0;
}
