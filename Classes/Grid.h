//
//  Grid.h
//  TowerDefence
//
//  Created by Hackintosh on 7/27/17.
//
//

#ifndef Grid_h
#define Grid_h

#include "FieldCell.h"
#include "external/json/document.h"
#include <fstream>
#include "external/json/stringbuffer.h"
#include "external/json/writer.h"
#include <string> 
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace std;

class Grid : public Node {
    
public:
    Grid(Point startPoint, Point endPoint);
    CC_SYNTHESIZE(Size, size, GridSize);
    CC_SYNTHESIZE(Size, cellSize, CellSize);
    CC_SYNTHESIZE(Point, startPoint, StartPoint);
    CC_SYNTHESIZE(Point, endPoint, EndPoint);
    CC_SYNTHESIZE(int, editMode, EditMode);
    void exportGrid();
    string JsonToString(rapidjson::Document jsonGrid);
    bool importGridFromJson();
    void showGridState();
    FieldCell *getCell(Point cell);
    void changeEditMode();
    void setCellsEditMode();
    bool hasChanged();
    
private:
    FieldCell ***cells;
    rapidjson::Document createJSON();
    rapidjson::Document readJSON();
    int getJsonLength(rapidjson::Document &jsonGrid);
    int editToolsAMount;
    Sprite **editTools;
    Sprite *selectedEdit;
    Sprite *getEditTool(int editMode);
    EventListenerTouchOneByOne *listener;
    bool isEditToolTouch(Sprite *editToll, Point touchPoint);
};

#endif /* Grid_h */
