#pragma once

#include <QWidget>
#include <QGridLayout>
#include <vector>
#include <QPushButton>
#include <QLabel>

class ResourceMarketLevelWidget : public QWidget {
public:
	ResourceMarketLevelWidget();
	~ResourceMarketLevelWidget();
	void createFullLevelMarket();
	void createUraniumLevelMarket();
	int iconWidth;
	int iconHeight;
private:
	QGridLayout *gridLayout;
	QLabel *costLabel;
	std::vector<QPushButton*> coalButtons;
	std::vector<QPushButton*> oilButtons;
	std::vector<QPushButton*> garbageButtons;
	std::vector<QPushButton*> uraniumButtons;
};

