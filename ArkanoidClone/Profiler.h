#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <string>


class Profiler
{
public:

	Profiler() : mFrame(0), mFps(0), seconds(0) { LoadProfile(); }

private:


	std::vector<int> allFps;
	double lastMean = 0;

	sf::RenderWindow window;
	unsigned int mFrame;
	unsigned int mFps;
	sf::Clock mClock;
	unsigned int seconds = 0;
	unsigned int secondsToWait = 3;
	double mean = 0;
	double sd = 0;

public:
	void Update()
	{
		if (mClock.getElapsedTime().asSeconds() >= 1.f)
		{
			mFps = mFrame;
			mFrame = 0;
			mClock.restart();
			seconds++;
			if (seconds > secondsToWait)
			{				
				allFps.push_back(mFps);
				AddToMean(mFps);
				CalculateSD();
				ShowStats();
			}
		
		}
		++mFrame;
	}

	void SaveProfile()
	{
		if (seconds <= secondsToWait + 2)
			return;

		std::filesystem::path current = std::filesystem::current_path();
		current.append("Profiler");
		std::filesystem::create_directories(current);
		std::filesystem::path firstFile = current;
		firstFile.append("FPS_history.txt");

		std::ofstream main(firstFile, std::ios_base::app);
		if (main)
		{
			main << mean << " " << sd << " " << seconds << " " << FormatFilename(CurrentDateTime()) << std::endl;
		}
		main.close();
		
		std::filesystem::path secondFile = current;
		secondFile.append("Builds");
		std::filesystem::create_directories(secondFile);

		std::string date = CurrentDateTime();
		date = FormatFilename(date);		
		secondFile.append(date);
		secondFile.concat(".txt");

		std::ofstream builds(secondFile);
		if (builds)
		{
			for (int i = 0; i < allFps.size(); i++)
			{
				builds << allFps[i] << std::endl;
			}
		}
		builds.close();


		std::cout << "Profiler saved to file!" << std::endl;
	}

private:

	void AddToMean(int newFPS) {
		double newMean;
		newMean = mean + ((newFPS - mean) / allFps.size());
		mean = newMean;
	}

	double CalculateSD()
	{
		if (seconds <= secondsToWait)
			return 0;

		if (allFps.size() - 1 <= 0)
			return 0;

		double upper = 0;
		for (int fps: allFps)
		{
			upper += pow(fps - mean, 2);
		}

		double _sd = upper / (allFps.size() - 1);
		sd = round(sqrt(_sd));
		return sd;

	}

	void ShowStats()
	{
		std::cout<<mFps<< "\t" << CalculateFpsDrop()<< std::endl;
	}

	std::string CurrentDateTime() 
	{
		auto start = std::chrono::system_clock::now();
		auto legacyStart = std::chrono::system_clock::to_time_t(start);
		char tmBuff[30];
		ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
		return tmBuff;
	}

	std::string FormatFilename(std::string text)
	{
		std::replace(text.begin(), text.end(), ' ', '_');
		std::replace(text.begin(), text.end(), ':', '-');
		text = text.erase(text.size() - 6);
		return text;
	}

	void LoadProfile()
	{
		std::filesystem::path current = std::filesystem::current_path();
		current.append("Profiler");
		current.append("FPS_history.txt");
		double fps, sd;
		int sec;
		std::string date, line;
		std::vector<double> fileFPS;

		std::ifstream main(current);
		if(main)
		{
			while (main >> fps >> sd >> sec >> date)
			{
				fileFPS.push_back(fps);
			}
			
		}
		main.close();

		if (fileFPS.size() >= 3)
		{
			lastMean = (fileFPS[fileFPS.size()-1] + fileFPS[fileFPS.size() - 2] + fileFPS[fileFPS.size() - 3]) / 3;
		}

	}

	inline std::string CalculateFpsDrop() 
	{
		if (lastMean == 0)
			return "no_data";
		std::string drop = "";
		int value = static_cast<int>((100 - ((mFps / lastMean) * 100)));
		if (value > 0)
			drop += "-";
		else if (value < 0)
			drop += "+";
		drop += std::to_string(abs(value));
		drop += "%";

		return drop;
	}

};

