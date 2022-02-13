#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <napi.h>
#include <iostream>
#include <string>
#include "FaceDetector.h"
using namespace cv;

static Napi::String Method(const Napi::CallbackInfo& info) {

    Napi::Env env = info.Env();

    Napi::TypedArrayOf<uint8_t> buf = info[0].As<Napi::TypedArrayOf<uint8_t>>();
    
    //Mat img = cv::imdecode(cv::Mat(1, buf.ByteLength(), CV_8UC1, buf.Data() ), 1);
    Mat img = cv::imdecode(cv::Mat(1, buf.ByteLength(), CV_8UC1, buf.Data() ), 1);
    FaceDetector face_detector;
    std::string str;

    if(img.empty())
    {
        str = "Could not read the image";
    }

    auto rectangles = face_detector.detect_face_rectangles(img);
    cv::Scalar color(0, 105, 205);

    
    for(const auto & r : rectangles)
    {
        cv::rectangle(img, r, color, 4);
        str += std::to_string(r.x) + ",";
        str += std::to_string(r.y) + ",";
        str += std::to_string(r.width) + ",";
        str += std::to_string(r.height) + ",";
    }
    str.pop_back();

    return Napi::String::New(env, str);
}

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "getCoords"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(getCoords, Init)