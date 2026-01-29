# Copyright (C) 2015-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

cmake_minimum_required (VERSION 3.13)
project (CapsLK_task)

find_package(vsomeip3 REQUIRED)


add_executable(CapsLK_service 
    CapsLK_service_main.cpp
    )
target_link_libraries(CapsLK_service PRIVATE vsomeip3 )


add_executable(CapsLK_client
    CapsLK_client_main.cpp
)
target_link_libraries(CapsLK_client PRIVATE vsomeip3 )

