//
//  main.cpp
//  UglyMan_Stitching
//
//  Created by uglyman.nothinglo on 2015/8/15.
//  Copyright (c) 2015 nothinglo. All rights reserved.
//

#include "niswgsp.h"

bool nigswgsp(int nums, char * files) {
    Eigen::initParallel(); /* remember to turn off "Hardware Multi-Threading */
    cout << "nThreads = " << Eigen::nbThreads() << endl;
    cout << "[#Images : " << nums - 1 << "]" << endl;

    TimeCalculator timer;
    
    cout << "[Images :" << files << "]" << endl;
    MultiImages multi_images(files, LINES_FILTER_WIDTH, LINES_FILTER_LENGTH);
    
    timer.start();
    /* 2D */
    NISwGSP_Stitching niswgsp(multi_images);
    niswgsp.setWeightToAlignmentTerm(1);
    niswgsp.setWeightToLocalSimilarityTerm(0.75);
    niswgsp.setWeightToGlobalSimilarityTerm(6, 20, GLOBAL_ROTATION_2D_METHOD);
    niswgsp.writeImage(niswgsp.solve(BLEND_AVERAGE), BLENDING_METHODS_NAME[BLEND_AVERAGE]);
    niswgsp.writeImage(niswgsp.solve(BLEND_LINEAR),  BLENDING_METHODS_NAME[BLEND_LINEAR]);
   
    return false;
}
