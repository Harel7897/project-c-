#include "VideoProcessor.h"
#include <iostream>

//מקבל קובץ וידאו כקלט 
VideoProcessor::VideoProcessor(const std::string& inputFile) : inputFile(inputFile) {
    //פותח אותו
    cap.open(inputFile);
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file: " << inputFile << std::endl;
    }
    //מגדיר את הממדים של הווידאו כדי ליצור כותב ווידאו
    cv::Size size(static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH)), 
                  static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT)));
    writer.open("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 
                cap.get(cv::CAP_PROP_FPS), size);
}

//פונקציה לשינוי גודל הפריים
void VideoProcessor::resizeFrame(cv::Mat& frame) {
    cv::resize(frame, frame, cv::Size(640, 480));
}

//פונקציה שעושה סיבוב של הפריים 90 מעלות
void VideoProcessor::rotateFrame(cv::Mat& frame) {
    cv::rotate(frame, frame, cv::ROTATE_90_CLOCKWISE);
}

//פונקציה שמוסיפה טקסט לפריים
void VideoProcessor::addTextOverlay(cv::Mat& frame) {
    cv::putText(frame, "Processing Video", cv::Point(30, 50), 
                cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);
}

//פונקציה שעושה המרה של הפריים לגווני אפור
void VideoProcessor::applyFilter(cv::Mat& frame) {
    cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
}

//פונקציה שמביאה את תהליך העיבוד
void VideoProcessor::process() {
    cv::Mat frame;
    while (cap.read(frame)) {
        // עיבוד הפריים
        resizeFrame(frame);
        rotateFrame(frame);
        addTextOverlay(frame);
        applyFilter(frame);
        
        // כתיבת הפריים המעובד לקובץ
        writer.write(frame);
        
        // הצגת הפריים המעובד על המסך
        cv::imshow("Processed Video", frame);
        
        // המתנה של 30 מילישניות או עד שלחיצה על מקש
        if (cv::waitKey(30) >= 0) break;
    }

    // שחרור המשאבים
    cap.release();
    writer.release();
    cv::destroyAllWindows();
}