#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <openssl/sha.h>
#include <opencv2/opencv.hpp>

void task3() {
    std::string imagePath = "input_image.jpg";
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

    auto computeSha256 = [](const unsigned char* data, size_t len) -> std::string {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX ctx;
        SHA256_Init(&ctx);
        SHA256_Update(&ctx, data, len);
        SHA256_Final(hash, &ctx);
        std::stringstream ss;
        ss << std::hex << std::setfill('0');
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
            ss << std::setw(2) << (int)hash[i];
        return ss.str();
    };

    std::string origHash = computeSha256(image.data, image.total() * image.elemSize());

    cv::Mat modified = image.clone();
    int x = image.cols/2, y = image.rows/2, chan = 0;
    modified.at<cv::Vec3b>(y, x)[chan] ^= 1;

    std::string modHash = computeSha256(modified.data, modified.total() * modified.elemSize());

    std::ofstream out("hash_results.txt");
    auto print = [&](const std::string& s) {
        std::cout << s << std::endl;
        if (out) out << s << std::endl;
    };

    print("Original hash: " + origHash);
    print("Modified hash: " + modHash);
    print(origHash == modHash ? "Hashes match" : "Hashes differ");
}