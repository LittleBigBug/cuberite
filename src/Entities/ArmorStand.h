
#pragma once

#include "Entity.h"





// tolua_begin
class cArmorStand :
	public cEntity
{
	typedef cEntity Super;
	// tolua_end

public:
	CLASS_PROTODEF(cArmorStand)

	cArmorStand(Vector3d a_Pos, double a_Yaw);


	// tolua_begin

	/** Returns true if the armor stand is invisible. */
	virtual bool IsInvisible() const override;

	/** Set whatever the armorstand is visible */
	void SetVisible(bool a_IsVisible);

	/** Returns true if the armor stand has a custom name. */
	bool HasCustomName(void) const { return !m_CustomName.empty(); }

	/** Gets the custom name of the armor stand. If no custom name is set, the function returns an empty string. */
	const AString & GetCustomName(void) const { return m_CustomName; }

	/** Sets the custom name of the armor stand. You see the name over the armor stand.
	If you want to disable the custom name, simply set an empty string. */
	void SetCustomName(const AString & a_CustomName);

	/** Is the custom name of this armor stand always visible? If not, you only see the name when you sight the mob. */
	bool IsCustomNameAlwaysVisible(void) const { return m_CustomNameAlwaysVisible; }

	/** Sets the custom name visiblity of this armor stand.
	If it's false, you only see the name when you sight the mob. If it's true, you always see the custom name. */
	void SetCustomNameAlwaysVisible(bool a_CustomNameAlwaysVisible);

	/** Returns true if the armor stand is a normal sized one. */
	short GetSize(void) const { return m_Size; }
	void SetSize(short a_Size);

	/** Returns true if the armor stand is a normal sized one. */
	bool IsNormal(void) const { return m_Size == 2; }

	/** Returns true if the armor stand is a small one. */
	bool IsSmall(void) const { return m_Size == 1; }

	/** Returns true if the armor stand is a marker (null size). */
	bool IsMarker(void) const { return m_Size == 0; }

	/** Returns true if the armor stand have amrs. */
	bool HasArms(void) const { return m_HasArms; }
	void SetHasArms(bool a_HasArms);

	/** Returns true if the armor stand have a base platform. */
	bool HasBasePlate(void) const { return m_HasBasePlate; }
	void SetHasBasePlate(bool a_HasBasePlate);

	Vector3d GetHeadRotation(void) const { return m_HeadRotation; }
	Vector3d GetBodyRotation(void) const { return m_BodyRotation; }
	Vector3d GetLeftArmRotation(void) const { return m_LeftArmRotation; }
	Vector3d GetRightArmRotation(void) const { return m_RightArmRotation; }
	Vector3d GetLeftLegRotation(void) const { return m_LeftLegRotation; }
	Vector3d GetRightLegRotation(void) const { return m_RightLegRotation; }

	void SetHeadRotation(Vector3d a_HeadRotation);
	void SetBodyRotation(Vector3d a_BodyRotation);
	void SetLeftArmRotation(Vector3d a_LeftArmRotation);
	void SetRightArmRotation(Vector3d a_RightArmRotation);
	void SetLeftLegRotation(Vector3d a_LeftLegRotation);
	void SetRightLegRotation(Vector3d a_RightLegRotation);

	virtual cItem GetEquippedWeapon(void) const override { return m_RightHand; }
	virtual cItem GetOffHandEquipedItem(void) const override { return m_LeftHand; }
	virtual cItem GetEquippedHelmet(void) const override { return m_Helmet; }
	virtual cItem GetEquippedChestplate(void) const override { return m_ChestPlate; }
	virtual cItem GetEquippedLeggings(void) const override { return m_Leggings; }
	virtual cItem GetEquippedBoots(void) const override { return m_Boots; }

	void SetEquippedWeapon(const cItem & a_RightHand);
	void SetOffHandEquipedItem(const cItem & a_LeftHand);
	void SetEquippedHelmet(const cItem & a_Helmet);
	void SetEquippedChestplate(const cItem & a_ChestPlate);
	void SetEquippedLeggings(const cItem & a_Leggings);
	void SetEquippedBoots(const cItem & a_Boots);

	// tolua_end

private:

	// cEntity overrides:
	virtual void SpawnOn(cClientHandle & a_ClientHandle) override;
	virtual void Tick(std::chrono::milliseconds a_Dt, cChunk & a_Chunk) override;
	virtual void KilledBy(TakeDamageInfo & a_TDI) override;
	virtual void OnRightClicked(cPlayer & a_Player) override;


	bool m_IsVisible;
	AString m_CustomName;
	bool m_CustomNameAlwaysVisible;

	short m_Size;
	bool m_HasArms;
	bool m_HasBasePlate;
	Vector3d m_HeadRotation;
	Vector3d m_BodyRotation;
	Vector3d m_LeftArmRotation;
	Vector3d m_RightArmRotation;
	Vector3d m_LeftLegRotation;
	Vector3d m_RightLegRotation;

	cItem m_LeftHand;
	cItem m_RightHand;
	cItem m_Helmet;
	cItem m_ChestPlate;
	cItem m_Leggings;
	cItem m_Boots;

};  // tolua_export
