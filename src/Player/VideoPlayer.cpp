#include <iostream>

#include "opencv2/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char* argv[]) {
  //  cv::CommandLineParser parser(argc, argv, keys);

  if (argc < 2) {
    std::cout << "ERROR: Not enough parameters.." << std::endl;
    return false;
  }

  int is_fullscreen = 0;

  std::string source_file = argv[1];

  if (source_file.length() == 0)
    return false;
    
  std::cout << "INFO: predicting video..." << std::endl;

  // When the source file is an video it must use a predicit(cv::Mat& src_img) function in ExYoloDetector for each images in video.
  cv::VideoCapture video_cap;

  video_cap.open(source_file);

  if (!video_cap.isOpened()) {
    std::cout << "ERROR: I can not open camera or video file." << std::endl;
    return 0;
  }

  cv::Mat source_img;

  for (;;) {
    video_cap >> source_img;

    cv::imshow("image", source_img);           

    //  cv::waitKey(0);
  }

  return 0;
}
