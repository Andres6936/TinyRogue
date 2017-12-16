#pragma once

/*
TODO:
	Hallucinate: ���� �ڵ� ����ȭ/����ȭ
	Blind: �Ǹ� ������ ��� �ڵ��̵� ó��(���� ��)
	Levitate: ���� ���� ó��
	Throw a potion (Epyx Rogue)
*/

#include "../Item.hpp"

class Potion : public Item
{
public:
	enum Type
	{
		Confuse,
		Hallucinate,
		Poison,
		Strength,
		SeeInvisible,
		Healing,
		MonsterFind,
		MagicFind,
		RaiseLevel,
		ExtraHeal,
		Haste,
		Restore,
		Blind,
		Levitate,
		MaxPotions
	};

public:
	using Item::Item;

	std::wstring getAName() const override;

	// quaff
	bool use(Actor& actor) override;
	
	void identify() override;
	bool isIdentified() const override;

	static void initColors(Rng& rng);

	static std::wstring randomColor(); // Rainbow
	static std::wstring pickColor(Actor& actor, const std::wstring& color);

	static int pickOne(Rng& rng);

private:
	void quaff(Actor& actor, int type, bool knowit, int flag = 0, int time = 0);
};
