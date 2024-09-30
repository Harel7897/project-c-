#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H

#include <opencv2/opencv.hpp>
#include <string>

class VideoProcessor {
public:
    VideoProcessor(const std::string& inputFile);
    void process();
    
private:
    std::string inputFile;
    cv::VideoCapture cap;
    cv::VideoWriter writer;
    
    void resizeFrame(cv::Mat& frame);
    void rotateFrame(cv::Mat& frame);
    void addTextOverlay(cv::Mat& frame);
    void applyFilter(cv::Mat& frame);
};

#endif // VIDEOPROCESSOR_H
