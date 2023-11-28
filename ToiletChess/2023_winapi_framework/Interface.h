#pragma once
#include "Object.h"
#include "Texture.h"

class Interface : public Object
{
public:
	Interface(Vec2 pos, Vec2 scale);
	~Interface();

public:
	void Update() override;
	void Render(HDC hDC) override;

public:
	void SetRender(bool render) { this->render = render; }
	bool GetRender() { return render; }

public:
	virtual void OnMouseEnter();
	virtual void OnMouse();
	virtual void OnMouseExit();

protected:
	Texture* texture;
	bool onMouse;
	bool render;
};

