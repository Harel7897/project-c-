#include <opencv2/opencv.hpp>
#include <iostream>
#include "VideoProcessor.h"
//פונקציה שמתחילה את התכנית
int main(int argc, char** argv) {
    //בודקת אם יש מספיק ארגומנטים
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_video_file>" << std::endl;
        return -1;
    }
//שומרת את נתיב קובץ הווידאו מהארגומנט הראשון
    std::string inputFile = argv[1];
    //יצירת מופע
    VideoProcessor videoProcessor(inputFile);
    //מפעיל את תהליך העיבוד ווידאו
    videoProcessor.process();

    return 0;
}