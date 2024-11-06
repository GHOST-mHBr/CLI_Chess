cmake_minimum_required(VERSION 3.16)

project(RastaFinal VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(offline_source_path sources/offline)
set(online_source_path sources/online)

set(offline_cpp_files ${offline_source_path}/main-offline.cpp)
set(offline_hpp_files)

set(online_client_cpp_files ${online_source_path}/ClientGame.cpp ${online_source_path}/AbstractOnlinePlayer.cpp ${online_source_path}/LocalPlayer.cpp ${online_source_path}/RemotePlayer.cpp ${online_source_path}/main-client.cpp)
set(online_client_hpp_files ${online_source_path}/ClientGame.hpp ${online_source_path}/AbstractOnlinePlayer.hpp ${online_source_path}/LocalPlayer.hpp ${online_source_path}/RemotePlayer.hpp)

set(online_server_cpp_files ${online_source_path}/ServerGame.cpp ${online_source_path}/AbstractOnlinePlayer.cpp ${online_source_path}/RemotePlayer.cpp ${online_source_path}/LocalPlayer.cpp ${online_source_path}/main-server.cpp)
set(online_server_hpp_files ${online_source_path}/ServerGame.hpp ${online_source_path}/AbstractOnlinePlayer.hpp ${online_source_path}/LocalPlayer.hpp ${online_source_path}/RemotePlayer.hpp)

add_subdirectory(sources)

add_executable(offline_chess ${offline_cpp_files} ${offline_hpp_files})
add_executable(client_chess ${online_client_cpp_files} ${online_client_hpp_files})
add_executable(server_chess ${online_server_cpp_files} ${online_server_hpp_files})

target_link_libraries(offline_chess PUBLIC CommonFiles)
target_link_libraries(client_chess PUBLIC CommonFiles)
target_link_libraries(server_chess PUBLIC CommonFiles)
