#pragma once

/*
TODO:
	Confuse: confuse ������ ���Ͱ� �ٸ� ���͸� �����ϴ��� �׽�Ʈ
	Protect: �����ۿ� �ɸ� ���ָ� ���������� ���� (�������ο����� x)
*/

#include "../Item.hpp"

class Scroll : public Item
{
public:
	enum Type
	{
		Confuse,
		Map,
		Hold,
		Sleep,
		EnchantArmor,
		IdPotion, // TODO: ID ��ũ���� �ϳ���
		IdScroll,
		IdWeapon,
		IdArmor,
		IdRingOrStick,
		Scare,
		FoodFind,
		Teleport,
		EnchantWeapon,
		Create,
		Remove,
		Aggravate,
		Protect,
		MaxScrolls
	};

public:
	using Item::Item;

	std::wstring getAName() const override;

	// read
	bool use(Actor& actor) override;

	void identify() override;
	bool isIdentified() const override;

	static void initNames(Rng& rng);

	static int pickOne(Rng& rng);
};
