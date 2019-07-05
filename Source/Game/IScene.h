#pragma once

class __declspec(novtable) IScene
{
public:
	virtual ~IScene() = default;
	virtual void Frame(float delta) = 0;
};