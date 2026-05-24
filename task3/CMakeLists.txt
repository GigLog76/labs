
find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)

add_library(task3_lib STATIC task3.cpp)

target_link_libraries(task3_lib
    PUBLIC
    ${OpenCV_LIBS}
    OpenSSL::Crypto
)
target_include_directories(task3_lib PUBLIC ${OpenCV_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})