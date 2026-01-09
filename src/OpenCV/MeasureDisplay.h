#ifndef MeasureDISPLAY_H
#define MeasureDISPLAY_H

#include "opencv2/opencv.hpp"
#include "BlockDetector.h"

class MeasureDisplay {
public:
    MeasureDisplay();
    
    // Display Measures on image
    cv::Mat displayMeasures(const cv::Mat& image, 
                               const std::vector<BlockMeasure>& blocks,
                               bool showValues = true);
    
    // Create Measure report image
    cv::Mat createReport(const cv::Mat& image, 
                        const std::vector<BlockMeasure>& blocks);
    
    // Draw Measure scale/ruler
    void drawScale(cv::Mat& image, double pixelsPerMM, 
                  const cv::Point& start = cv::Point(20, 20));
    
    // Draw grid for reference
    void drawGrid(cv::Mat& image, int gridSize = 50);
    
private:
    // Draw single block with Measures
    void drawBlockWithMeasures(cv::Mat& image, 
                                  const BlockMeasure& block, 
                                  int blockID,
                                  bool showValues);
    
    // Add text with background for better visibility
    void putTextWithBackground(cv::Mat& image, const std::string& text,
                              const cv::Point& position, double fontScale = 0.5,
                              const cv::Scalar& textColor = cv::Scalar(255, 255, 255),
                              const cv::Scalar& bgColor = cv::Scalar(0, 0, 0));
    
    // Colors for different block types
    std::map<std::string, cv::Scalar> typeColors;
    
    // Font properties
    int fontFace;
    double fontScale;
    int thickness;
};
#endif // MeasureDISPLAY_H
