// MaurerRose.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define OLC_PGE_APPLICATION
#include "C:\Users\Akolam\Desktop\olcPixelGameEngine-master\olcPixelGameEngine.h"
#include <thread>

using namespace std;

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}
public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here

		return true;
	}

private:
	float n = 6;
	float d = 71;
	vector<pair<int, int>> points;
	vector<pair<int, int>> points2;
	
	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame, draws random coloured pixels
		//for (int x = 0; x < ScreenWidth(); x++)
			//for (int y = 0; y < ScreenHeight(); y++)
			//	Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
		//DrawLine(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(100, 100, 245));
		Clear(olc::DARK_CYAN);
		for (int i = 0; i < 361; i++) {
			float k = i * d * (3.14 / 180);
			float r = 300 * sinf(n * k);
			float x = r * cosf(k) + ScreenWidth() / 2;
			float y = r * sinf(k) + ScreenHeight() / 2;
			points.push_back(make_pair(x,y));
		}
		
		for (int i = 0; i < points.size()-1; i++) {
			DrawLine(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
			this_thread::sleep_for(std::chrono::milliseconds(30));
		}

		for (int i = 0; i < 361; i++) {
			float k = i * (3.14 / 180);
			float r = 300 * sinf(n * k);
			float x = r * cosf(k) + ScreenWidth() / 2;
			float y = r * sinf(k) + ScreenHeight() / 2;
			points2.push_back(make_pair(x, y));
		}
		for (int i = 0; i < points2.size() - 1; i++) {
			DrawLine(points2[i].first, points2[i].second, points2[i + 1].first, points2[i + 1].second, olc::Pixel(255,0,0));
			this_thread::sleep_for(std::chrono::milliseconds(30));
		} 
		
		return true;
	}
};
int main()
{
	Example demo;
	if (demo.Construct(800, 800, 16, 16))
		demo.Start();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
