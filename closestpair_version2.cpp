#include<iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class coordinates
{
    public:
    double x_coordinate;
    double y_coordinate;
};//class for storing the points


class findDistance
{
    public:
    double x1_coordinate;
    double y1_coordinate;
    double x2_coordinate;
    double y2_coordinate;
    double dis;
};//class for finding closest pair of points

//Function for finding closest pair of points with the points(data) and their size(n) as arguments
void findClosest(coordinates data[], int n) 
{
    coordinates temp;
    int k = 0;
    double min = 0;//for finding minimum distance
    findDistance distance[4950];
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            //distance between two points(x1,y1) and (x2,y2) is √ [(x2-x1)^2 + (y2-y1)^2]
            distance[k].dis=sqrt(pow(data[j].x_coordinate - data[i].x_coordinate, 2) + pow(data[j].y_coordinate - data[i].y_coordinate, 2));
            //Storing the two points and distance between them
            distance[k].x1_coordinate=data[i].x_coordinate;
            distance[k].y1_coordinate=data[i].y_coordinate;
            distance[k].x2_coordinate=data[j].x_coordinate;
            distance[k].y2_coordinate=data[j].y_coordinate;
            if( i == 0 && j == 1)
            {
                min = distance[0].dis;
            }
            if(distance[k].dis <= min)
            {
                min = distance[k].dis;
            }
            k++;
        }
    }
    //Printing the closest pair of points
    for(int i = 0; i < 4950; i++)
    {
        if(distance[i].dis == min)
        {
            cout<<"\nClosest pair of points are ("<<distance[i].x1_coordinate<<","<<distance[i].y1_coordinate<<")and ("<<distance[i].x2_coordinate<<","<<distance[i].y2_coordinate<<")";
        }
    } 
}
int main()
{
    coordinates data[100];
    srand((unsigned) time(NULL));
    for(int i = 0; i < 100; i++)
    {
        data[i].x_coordinate = (float) rand() / RAND_MAX;
        data[i].y_coordinate = (float) rand() / RAND_MAX;
    }
    int n = sizeof(data)/sizeof(data[0]);
    cout<<"\nThe Random points are : ";
    for(int i = 0; i < 100; i++)
    {
        cout<<"\n("<<data[i].x_coordinate<<","<<data[i].y_coordinate<<"),";
    }
    findClosest(data,n);
}