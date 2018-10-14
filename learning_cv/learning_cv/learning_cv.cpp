//#include<opencv2\highgui\highgui.hpp>
//#include<opencv2\imgproc\imgproc.hpp>
//#include<iostream>
//#include<fstream>
//using namespace std;
//int g_slider_position = 0;
//int g_run = 1, g_dontset = 0;
//cv::VideoCapture g_cap;
//void example2_5(const cv::Mat& imag) {
//	cv::namedWindow("Example2_5-in", cv::WINDOW_AUTOSIZE);
//	cv::namedWindow("Example2_5-out", cv::WINDOW_AUTOSIZE);
//
//	cv::imshow("Example2_5-in", imag);
//
//	cv::Mat out;
//	cv::GaussianBlur(imag, out, cv::Size(5, 5), 3, 3);
//	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);
//	cv::imshow("Example2_5-out", out);
//	cv::waitKey(0);
//}
//void onTrackbarSlide(int pos, void *) {
//	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
//	if (!g_dontset)
//		g_run = 1;
//	g_dontset = 0;
//
//}
//int main(int argc, char** argv) {
//	/*cv::Mat img = cv::imread("C:\\Users\\gaoqian\\Pictures\\boolenn.jpg", -1);
//	if (img.empty())
//		return -1;
//	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
//	cv::imshow("Example1", img);
//	cv::waitKey(0);
//	cv::destroyWindow("Example1");*/
//
//	/*cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
//	cv::VideoCapture cap;
//	cap.open("F:\\黑暗物质\\[蚁人]Ant-Man.2015.BluRay.720p.x264.2Audio.AC3-CnSCG.mkv");
//	cv::Mat frame;
//	for (;;) {
//		cap >> frame;
//		if (frame.empty()) break;
//		cv::imshow("Example3", frame);
//		if (cv::waitKey(33) >= 0) break;
//	}*/
//
//	/*cv::namedWindow("Example4", cv::WINDOW_AUTOSIZE);
//	g_cap.open("F:\\黑暗物质\\[蚁人]Ant-Man.2015.BluRay.720p.x264.2Audio.AC3-CnSCG.mkv");
//	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
//	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
//	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
//	cout << "THis video has" << frames << "frames of dimensions(" << tmpw << ", " << tmph << ")" << endl;
//	cv::createTrackbar("Postion", "Example4", &g_slider_position, frames, onTrackbarSlide);
//	cv::Mat frame;
//	for (;;) {
//		if (g_run != 0) {
//			g_cap >> frame;
//			if (frame.empty()) break;
//			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
//			g_dontset = 1;
//			cv::setTrackbarPos("Position", "Example4", current_pos);
//			cv::imshow("Example4", frame);
//			g_run -= 1;
//		}
//		char c = (char)cv::waitKey(10);
//		if (c == 's')
//		{
//			g_run = 1; cout << "Single step, run = " << g_run << endl;
//		}
//		if (c == 'r') {
//			g_run = -1; cout << "Run mode, run = " << g_run << endl;
//		}
//		if (c == 27) 
//			break;
//	}*/
//
//
//	return 0;
//}
