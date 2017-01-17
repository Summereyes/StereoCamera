#include "stdafx.h"

typedef unsigned int uint;
class StereoCamera{
private:
	cv::Size imgSize;
	cv::Size chessboardSize;
	double chessboardLength;
	double imgScale;
	char* intrinsic_filename;
	char* extrinsic_filename;
	std::vector<std::string> picFileList;
public:
	StereoCamera(){
		imgSize.height = 720;
		imgSize.width = 1280;
		chessboardSize.height = 6;
		chessboardSize.width = 9;
		chessboardLength = 19.1f;
		imgScale = 1;
	}
	~StereoCamera(){};
	void saveCloudPoints(std::string cloud_point_filename, std::string distance_filename, const cv::Mat& mat);
	void initPictureFileList(std::string filename, int first, int last);
	void saveParallaxPic(std::string filename, const cv::Mat& mat);
	void fromGrayToColor(cv::Mat gray_pic, cv::Mat& color_pic);
	cv::Mat mergeImg(cv::Mat img1, cv::Mat img2);
	void stereoCalibrateCamera(std::string intrinsic_filename, std::string extrinsic_filename);
	void stereoMatch(int pic_num, std::string intrinsic_filename, 
		             std::string extrinsic_filename, bool no_display, std::string point_cloud_filename, std::string distance_filename);

};