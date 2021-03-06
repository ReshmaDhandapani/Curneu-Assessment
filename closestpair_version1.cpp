#include<iostream>
#include <cmath>
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
    int k=0;
    double min=0;//for finding minimum distance
    findDistance distance[5*5];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //distance between two points(x1,y1) and (x2,y2) is √ [(x2-x1)^2 + (y2-y1)^2]
            distance[k].dis=sqrt(pow(data[j].x_coordinate - data[i].x_coordinate, 2) + pow(data[j].y_coordinate - data[i].y_coordinate, 2));
            //Storing the two points and distance between them
            distance[k].x1_coordinate=data[i].x_coordinate;
            distance[k].y1_coordinate=data[i].y_coordinate;
            distance[k].x2_coordinate=data[j].x_coordinate;
            distance[k].y2_coordinate=data[j].y_coordinate;
            if(i==0 && j==1)
            {
                min=distance[0].dis;
            }
            if(distance[k].dis<=min)
            {
                min=distance[k].dis;
            }
            k++;
        }
    }
    //Printing the closest pair of points
    for(int i=0;i<5*5;i++)
    {
        if(distance[i].dis==min)
        {
            cout<<"\nClosest pair of points are ("<<distance[i].x1_coordinate<<","<<distance[i].y1_coordinate<<")and ("<<distance[i].x2_coordinate<<","<<distance[i].y2_coordinate<<")";
        }
    } 
}
int main()
{
    coordinates data[] = {{0.1, 0.6}, {0.33, 0.30}, {0.20, 0.40}, {0.5, 0.1}, {0.12, 0.1}, {0.3, 0.4}};
    int n = sizeof(data)/sizeof(data[0]);
    cout<<"\nRandom Testing data : {{0.1, 0.6}, {0.33, 0.30}, {0.20, 0.40}, {0.5, 0.1}, {0.12, 0.1}, {0.3, 0.4}}\n";
    findClosest(data,n);
}
