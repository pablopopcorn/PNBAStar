#pragma once

#include <vector>

#include <wx/wx.h>

class NavMeshNode
{
public:
	NavMeshNode(const wxPoint &point);

	float fCost1, fCost2;
	float gCost1, gCost2;
	float hCost1, hCost2;

	inline float getID() const { return id; }
	inline void setID(unsigned int id) { this->id = id; }

	inline float getX() const { return x; }
	inline float getY() const { return y; }
	inline void setPosition(float x, float y) { this->x = x; this->y = y; }

	inline std::vector<NavMeshNode*> *getAdjacentNodes() { return &adjacentNodes; }
	inline void addAdjacentNode(NavMeshNode *node) { assert(node); adjacentNodes.push_back(node); }
	void removeAdjacentNode(NavMeshNode *node);

	/*
	inline float getForwardCost() const { return forwardCost; }
	inline float getBackwardsCost() const { return backwardsCost; }
	inline float getTotalCost() const { return totalCost; }
	inline void setForwardCost(float forwardCost) { this->forwardCost = forwardCost; }
	inline void setBackwardsCost(float backwardsCost) { this->backwardsCost = backwardsCost; }
	inline void updateTotalCost() { totalCost = forwardCost + backwardsCost; }
	*/

	inline NavMeshNode *getPathPointer() const { return pathPointer; }
	inline void setPathPointer(NavMeshNode *pathPointer) { this->pathPointer = pathPointer; }

	inline void setLinePosition(float x, float y) { lineX = x; lineY = y; }
	inline void setLineEnable(bool enable) { lineEnable = enable; }

	void renderConnections(float r, float g, float b) const;
	void renderLine(float r, float g, float b) const;
	void renderNormalNode(float r, float g, float b) const;
	void renderStartNode(float r, float g, float b) const;
	void renderGoalNode(float r, float g, float b) const;
	void renderPathPointer(float r, float g, float b, bool invert) const;

	void dumpToStringStream(std::stringstream &s) const;
	
private:
	static const float ICON_SIZE;
	static const float CONNECTION_WIDTH;
	static const float PATH_POINTER_WIDTH;
	static const float PATH_POINTER_ARROW_LENGTH;

	unsigned int id;
	float x, y;
	std::vector<NavMeshNode*> adjacentNodes;

	float forwardCost, backwardsCost, totalCost;
	NavMeshNode *pathPointer;

	float lineX, lineY;
	bool lineEnable;

	void renderLineTo(float x, float y, float r, float g, float b) const;
};