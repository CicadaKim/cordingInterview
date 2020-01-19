#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
ostream& operator << (ostream& os, const pair<T,T>& p )
{
	os<<p.first<<" "<<p.second;
	return os;
}

template <typename T>
ostream& operator << (ostream& os, const vector<T> &v)
{
	for(auto e : v)
		os<<e<<endl;
	return os;
}

void rotateMatrix(vector<vector<int> >& matrix,int startY, int startX, int width)
{
	if(width<=1)
		return;
	
	int size = matrix.size()-1;
	
	for(int dx=0; dx<width-1; dx++)
	{
		int cX = startX + dx;
		int cY = startY;
		int tmp = matrix[cY][cX];
		
		int posX[4] = {size-cY,size-cX,cY,cX};
		int posY[4] = {cX,size-cY, size-cX,cY};
		
		for(int dir=3; dir>=1; dir--)
		{
			int pX = posX[dir];
			int pY = posY[dir];
			
			int nX = posX[dir-1];
			int nY = posY[dir-1];
			
			matrix[pY][pX] = matrix[nY][nX];	
		}
		
		matrix[posY[0]][posX[0]] = tmp;
	}
	rotateMatrix(matrix,startY+1,startX+1,width-2);
}

int main()
{
	vector<vector<int> > matrix{ {1,2,3},{4,5,6},{7,8,9}};
	rotateMatrix(matrix,0,0,matrix.size());
	cout<<matrix;
	return 0;
}
