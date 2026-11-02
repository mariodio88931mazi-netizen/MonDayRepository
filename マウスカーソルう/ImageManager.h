#pragma once
class ImageManager
{
public:
	// ‰æ‘œ‚ğ“Ç‚İ‚Ş
	static bool Initialize();

	// ‰æ‘œ‚ğŠJ•ú‚·‚é
	static void Finalize();

	static int GetSwordGraph();
	static int GetBackGround();
	static int GetBirdGraph();
	static int GetEffectGraph(int index);
	static int GetEffectMax();
};

