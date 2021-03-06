#pragma once

#include <QGraphicsView>
#include <QWheelEvent>
#include "City.h"
#include <memory>
#include <map>
#include "ConnectionItem.h"
#include "CityItem.h"
#include "HouseItem.h"

class MapGraphicsView : public QGraphicsView {
    Q_OBJECT

public:
    MapGraphicsView();
    ~MapGraphicsView() {}
    void Refresh();
    void DrawMap();
    void ResetSelected();

private:
    std::unique_ptr<QGraphicsScene> graphicsScene;
    int scaleSteps = 0;
    const int MAX_ZOOM = 10;
    const int MIN_ZOOM = -10;
    float scaleFactor = 1.15f;
    std::map<string, shared_ptr<CityItem>> cityItemsMap;
    vector<std::unique_ptr<ConnectionItem>> connectionItems;
    vector<std::unique_ptr<HouseItem>> houseItems;
    
    // Used to highlight selected city or region
    shared_ptr<City> selectedCity;
    shared_ptr<Region> selectedRegion;
    int scrollBarValue = 0;

    shared_ptr<City> GetCityByPoint(QPoint point);

    void MarkCitiesToRemove(shared_ptr<City> city);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

signals:
    void CitySelected(shared_ptr<City> city);
    void RegionSelected(shared_ptr<Region> region);
};

