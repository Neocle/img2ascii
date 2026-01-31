#include "ImageConverter.h"

#include <opencv2/opencv.hpp>
#include <iostream>

void ImageConverter::toPgm(const std::string& input,
                           const std::string& output) const {
    cv::Mat image = cv::imread(input, cv::IMREAD_UNCHANGED);

    if (image.empty()) {
        std::cerr << "Impossible d'ouvrir l'image " << input << "!" << std::endl;
        return;
    }

    cv::Mat grayImage;

    if (image.channels() == 4) {
        std::vector<cv::Mat> channels;
        cv::split(image, channels);

        cv::Mat bgr, gray;
        cv::merge(std::vector<cv::Mat>{channels[0], channels[1], channels[2]}, bgr);
        cv::cvtColor(bgr, gray, cv::COLOR_BGR2GRAY);

        cv::Mat alpha = channels[3];
        gray.setTo(255, alpha == 0);

        grayImage = gray;
    } else {
        cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    }

    bool success = cv::imwrite(output, grayImage);

    if (!success) {
        std::cerr << "Impossible de créer l'image PGM " << output <<"!" << std::endl;
    }
}
