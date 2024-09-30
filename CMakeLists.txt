cmake_minimum_required(VERSION 3.10)
project(VideoProcessingApp)

# חיפוש ספריית OpenCV
find_package(OpenCV REQUIRED)

# הוספת תיקיות ה-include
include_directories(includ ${OpenCV_INCLUDE_DIRS})

# הוספת הקבצים המהדרים
add_executable(VideoProcessingApp src/main.cpp src/VideoProcessor.cpp)

# קישור עם ספריית OpenCV
target_link_libraries(VideoProcessingApp ${OpenCV_LIBS})
