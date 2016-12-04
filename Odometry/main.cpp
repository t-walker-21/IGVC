// http://www.geomidpoint.com/destination/
//http://andrew.hedges.name/experiments/haversine/
//http://www.igismap.com/formula-to-find-bearing-or-heading-angle-between-two-points-latitude-longitude/
//  main.cpp
//  gpsNavi
//
//  Created by Tevon Walker on 12/3/16.
//  Copyright © 2016 Tevon Walker. All rights reserved.
//

#include <iostream>
#include <math.h>


using namespace std;


double calc_heading(double LatA, double LonA, double LatB, double LonB);
double calc_dist(double LatA, double LonA, double LatB, double LonB);

int main(int argc, const char * argv[]) {
  
    
    double dist = calc_dist(34.701076, -86.795648, 34.700668, -86.787212); //LatA,LonA LatB,LonB
    double ber = calc_heading(34.701076, -86.795648, 34.700668, -86.787212);
    
    cout << "You need to travel " << dist << " miles, at a bearing of: " << ber <<  endl;
    return 0;
}


double calc_dist(double LatA, double LonA, double LatB, double LonB)
{
    LatB *=  M_PI / 180;
    LatA *=  M_PI / 180;
    LonA *=  M_PI / 180;
    LonB *=  M_PI / 180;
    
    double R = 3961; //earth radius in miles
    
    double deltaLon = LonA - LonB;
    double deltaLat = LatA - LatB;
    
    double a = pow((sin(deltaLat/2)),2) + cos(LatA) * cos(LatB) * pow(sin(deltaLon/2),2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double dist = R * c;
    return dist;
}

double calc_heading(double LatA, double LonA, double LatB, double LonB)
{
    
    LatB *=  M_PI / 180;
    LatA *=  M_PI / 180;
    LonA *=  M_PI / 180;
    LonB *=  M_PI / 180;
    
    double deltaLon = LonA - LonB;
    double deltaLat = LatA - LatB;
    
    double X = cos(LatB) * sin(deltaLon) * -1;
    
    //cout << "X: " << X << endl;
    
    double Y = cos(LatA) * sin(LatB) - sin(LatA) * cos(LatB) * cos(deltaLon);
    
    //cout << "Y: " << Y << endl;
    
    double ber = atan2(X, Y);
    
    ber *= 180 / M_PI; //convert to degrees
    
    if (ber < 0)
        ber += 360;
    
    return ber;
}
