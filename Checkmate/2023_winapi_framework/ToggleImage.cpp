#include "pch.h"
#include "ToggleImage.h"
#include "ResMgr.h"

ToggleImage::ToggleImage(Vec2 pos, Vec2 scale, wstring tex1, wstring tex2) : Interface(pos, scale)
{
	this->tex1 = ResMgr::GetInst()->TexLoad(tex1, L"Texture\\" + tex1 + L".bmp");
	this->tex2 = ResMgr::GetInst()->TexLoad(tex2, L"Texture\\" + tex2 + L".bmp");
}

ToggleImage::~ToggleImage()
{
}

void ToggleImage::ToggleTexture()
{
	if (texture != tex1)
		texture = tex1;
	else
		texture = tex2;
}

void ToggleImage::SetTexture(int texID)
{
	if (texID == 1)
		Interface::SetTexture(tex2);
	else
		Interface::SetTexture(tex1);
}

Texture* ToggleImage::GetTexture(int texID)
{
	if (texID == 0)
		return tex1;
	if (texID == 1)
		return tex2;

	return nullptr;
}
