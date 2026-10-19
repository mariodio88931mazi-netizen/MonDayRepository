#pragma once
#include "MagicalGirl.h"
class Homura :public MagicalGirl
{
public:
	/// <summary>
	/// 戦闘行動（ほむら）
	/// </summary>
	void Fight() override;

	/// <summary>
	/// プロフィール表示
	/// </summary>
	void ShowProfile() override;
};